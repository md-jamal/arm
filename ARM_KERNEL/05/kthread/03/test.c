#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/interrupt.h>
#include <linux/kthread.h>

#define DEV_NAME    "test-dev"

int test_thread(void *data)
{
    printk("test thread running \n");

    while(1)
    {

        if(kthread_should_stop())
            break;

        printk("pid: %d cpu: %d comm: %s\n",
                current->pid,
                current_thread_info()->cpu,
                current->comm);
        //mdelay(1000);
        msleep(1000);
    }

    return 10;
}

struct task_struct *task;
int test_init(void)
{
    printk("test init\n");
    task = kthread_run(test_thread, NULL, "test-kthread");
    if(IS_ERR(task))
    {
        return PTR_ERR(task);
    }

    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    int ret;
    printk("test exit\n");
    ret = kthread_stop(task);   //通知线程结束, 并阻塞等待线程结束;
    printk("ret : %d\n", ret);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



