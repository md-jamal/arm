#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/sched.h>
#include "ioctl-dev.h"

#define DEV_NAME    "test-dev"
#define MAX         1024

struct test_dev {
    char dev_buf[MAX];
    int cur;
    int offset;

    void *reg_base;
    u32 gpio_irq;

    struct file_operations fops;
    int major;
};

volatile bool empty = true;

////////////////////////chrdev//////////////////////////
int test_open(struct inode *inode, struct file *filp)
{
    struct test_dev *tdev;
    struct task_struct *task;
    struct thread_info *thread;
    //int stack;
    tdev = container_of(filp->f_op, struct test_dev, fops);
    filp->private_data = tdev;
    printk("test open\n");

    task = current;
    printk("pid: %d comm: %s\n", task->pid, task->comm);

    //thread = (struct thread_info *)(((unsigned long)&stack) &~ (THREAD_SIZE - 1));
    thread = current_thread_info();

    printk("cpu: %d pid: %d comm: %s\n", thread->cpu, thread->task->pid, thread->task->comm);

    return 0;
}

int test_close (struct inode *inode, struct file *filp)
{
    //struct test_dev *tdev = filp->private_data;
    printk("test close\n");
    return 0;
}

struct __wait_node{
    struct task_struct *task;
    struct list_head node;
};

LIST_HEAD(_whead);

ssize_t test_read(struct file *filp, char __user *buf, size_t size, loff_t *offset)
{
    struct test_dev *tdev = filp->private_data;
    int ret;
    struct __wait_node wait;     
    printk("test read\n"); 
    if(tdev->offset == tdev->cur)
        empty = true;

    while(empty)
    {
        INIT_LIST_HEAD(&wait.node);
        wait.task = current; 
        list_add_tail(&wait.node, &_whead);

        set_current_state(TASK_INTERRUPTIBLE);  //1)wake_up_process();
        schedule();                             //2)signal

        printk("wake up\n");

        if(signal_pending(current))
        {
            return -ERESTARTSYS;
            //return -EINTR;
        }
    }

    if(tdev->offset + size > tdev->cur)
        size = tdev->cur - tdev->offset;

    //memcpy(buf, dev_buf + *offset, num);
    ret = copy_to_user(buf, tdev->dev_buf + tdev->offset, size);
    tdev->offset += size - ret;
    printk("ret : %d size : %lu\n", ret, size);

    if(tdev->offset == tdev->cur)
        empty = true;
    if(ret == size)
        return -EFAULT;
    return size - ret;
}

ssize_t test_write(struct file *filp, const char __user *buf, size_t size, loff_t *offset)
{
    struct test_dev *tdev = filp->private_data;
    struct __wait_node *node;
    int ret;
    printk("test write\n");   
    if(*offset + size > MAX)
        size = MAX - *offset;

    //memcpy(dev_buf + *offset, buf, num);
    ret = copy_from_user(tdev->dev_buf + *offset, buf, size);
    *offset += size - ret;
    tdev->cur += size - ret;
    printk("ret: %d size: %lu\n", ret, size);
    if(ret == size)
        return -EFAULT;

    if(size - ret != 0)
    {
        empty = false;
        while(!list_empty(&_whead))
        {
            node = list_first_entry(&_whead, struct __wait_node, node);
            list_del_init(&node->node);
            wake_up_process(node->task);
        }
    }
    return size - ret;
}

loff_t test_lseek (struct file *filp, loff_t offset, int whence)
{
    //struct test_dev *tdev = filp->private_data;
    loff_t tmp = filp->f_pos;
    switch(whence)
    {
        case SEEK_SET:
            tmp = offset;
            break;
        case SEEK_CUR:
            tmp += offset;
            break;
        case SEEK_END:
            tmp = MAX + offset;
            break;
    }

    if(tmp > MAX)
        tmp = MAX;

    filp->f_pos = tmp;
    return tmp;
}

long test_ioctl (struct file *filp, unsigned int cmd, unsigned long arg)
{
    struct led_set *lset;
    //struct test_dev *tdev = filp->private_data;
    
    if(_IOC_TYPE(cmd) != LED_TYPE)
    {
        return -EINVAL;
    }

    switch(cmd)
    {
        case LED_ON:
            printk("led on\n");
            //gpio_direction_output();
            break;
        case LED_OFF:
            printk("led off\n");
            //gpio_direction_output();
            break;
        case LED_SET:
            printk("set led %lu\n", arg);
            break;
        case LED_SETON:
            lset = (void *)arg;
            printk("led_num: %d led_flag: %d\n", lset->led_num, lset->led_flag);
            break;
    }
    
    return 0;
}

///////////////////////////module///////////////////////////////////
struct test_dev tdev = {
    .fops = {
        .owner = THIS_MODULE, 
        .open = test_open, 
        .release = test_close,
        .read = test_read,
        .write = test_write,
        .llseek = test_lseek,
        .unlocked_ioctl = test_ioctl,
    },
    .major = 0,
};

int test_init(void)
{
    int ret;
    printk("test init\n");
    ret = register_chrdev(tdev.major, DEV_NAME, &tdev.fops);
    if(ret < 0)
    {
        return ret;
    }
    if(tdev.major == 0)      //动态申请到主设备号;
    {
        tdev.major = ret;
    }
    printk("major : %d\n", tdev.major);

    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    unregister_chrdev(tdev.major, DEV_NAME);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



