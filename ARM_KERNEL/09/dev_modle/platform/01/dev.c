#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/vmalloc.h>
#include <linux/pagemap.h>
#include <linux/io.h>
#include <linux/device.h>

#include "mini_device.h"

#define DEV_NAME    "test-dev0"

struct mini_device dev = {
    .name = DEV_NAME,
    .master = 0,
    .slave = 127,
    .gpio = (void *)0x11400000,
    .num = 10,
    .irq = 442,
};

int test_init(void)
{
    int ret;
    printk("test init\n");
    ret = mini_device_register(&dev);
    if(IS_ERR_VALUE(ret))
    {
        return ret;
    }
    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    mini_device_unregister(&dev);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");



