#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/preempt.h>
#include <linux/interrupt.h>
#include <linux/slab.h>

#define DEV_NAME    "test-dev"

struct timer_list timer;

void func(unsigned long data)       //tasklet (中断下半部)软中断; 
{
    printk("timer out start data: %lu\n", data);
    mdelay(3000);
    printk("timer out end data: %lu\n", data);
}

irqreturn_t handler(int irq, void *data)
{
    printk("irq handler\n");
    return IRQ_HANDLED;
}

int test_init(void)
{
    printk("test init\n");
    setup_timer(&timer, func, 100);     
    timer.expires = jiffies + 3 * HZ;
    add_timer(&timer);                  //3s 后来定时器中断;

    request_irq(IRQ_EINT(26), handler, IRQF_TRIGGER_FALLING, "test-key1", NULL);

    preempt_disable();
    mdelay(10000);
    preempt_enable();


    return 0;
}

void test_exit(void)    //模块拔出时的函数;
{
    printk("test exit\n");
    free_irq(IRQ_EINT(26), NULL);
}

module_init(test_init);
module_exit(test_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("V1.0");
MODULE_AUTHOR("xuwei www.uplooking.com");


