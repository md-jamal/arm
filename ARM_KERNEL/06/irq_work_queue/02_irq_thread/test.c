#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/interrupt.h>

#define DEV_NAME    "test-dev"

spinlock_t slock;
struct mutex mlock;
void func(char *str)
{
    int i;
    unsigned long flag;
     
    //mutex_lock(&mlock);
    //local_irq_disable();
    //local_irq_save(flag);
    //spin_lock(&slock);
    spin_lock_irqsave(&slock, flag);
    for(i = 0; i < 3; i++)
    {
        printk("%s: pid: %d cpu: %d comm: %s\n",
            str, current->pid, 
            current_thread_info()->cpu,
            current->comm);
        mdelay(1000);
    }
    //mutex_unlock(&mlock);
    //spin_unlock(&slock);
    //local_irq_restore(flag);
    //local_irq_enable();
    spin_unlock_irqrestore(&slock, flag);
}


int test_open(struct inode *inode, struct file *filp)
{
    printk("test open\n");
    func("test");
    return 0;
}

int test_close (struct inode *inode, struct file *filp)
{
    printk("test close\n");
    return 0;
}

struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = test_open, 
    .release = test_close,
};

//中断处理函数中禁止中断;
irqreturn_t handler(int irq, void *dev_id)
{
    printk("irq handler\n");
    func("irq");
    return IRQ_HANDLED;
}

int major = 0;
dev_t devno;
struct cdev *cdev;
int test_init(void)
{
    int ret;
    printk("test init\n");
    if(major == 0)
    {
        ret = alloc_chrdev_region(&devno, 0, 4, DEV_NAME);
        if(ret < 0)
        {
            return ret;
        }

        major = MAJOR(devno);
    }
    else
    {
        ret = register_chrdev_region(MKDEV(major, 0), 4, DEV_NAME);
        if(ret < 0)
        {
            return ret;
        }
    }
    printk("major: %d\n", major);

    cdev = cdev_alloc();   
    if(NULL == cdev)
    {
        unregister_chrdev_region(MKDEV(major, 0), 4);
        return -ENOMEM;
    }

    cdev_init(cdev, &fops);
    cdev->owner = THIS_MODULE;

    ret = cdev_add(cdev, MKDEV(major, 0), 4);
    if(ret < 0)
    {
        unregister_chrdev_region(MKDEV(major, 0), 4);
        return ret;
    }

    ret = request_irq(IRQ_EINT(26), handler, IRQF_TRIGGER_FALLING, "test-key1", NULL);
    if(IS_ERR_VALUE(ret))
    {
        cdev_del(cdev);
        unregister_chrdev_region(MKDEV(major, 0), 4);
        return ret;
    }

    spin_lock_init(&slock);
    mutex_init(&mlock);

    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    cdev_del(cdev);
    unregister_chrdev_region(MKDEV(major, 0), 4);
    free_irq(IRQ_EINT(26), NULL);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



