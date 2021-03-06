#include <config.h>
#include <gpio.h>
#include <pwm.h>

void pwm_tout0_init(u32 cnt, u32 cmp)
{
    set_nbit(GPD0CON, 0, 4, 2); //TOUT0 

    //Timer Input Clock Frequency = PCLK/({prescaler value + 1})/{divider value}
    set_nbit(TCFG0, 0, 8, 249);

    //Selects Mux input for PWM timer 0
    set_nbit(TCFG1, 0, 4, 2);

    //Timer 0 Count Buffer register
    set_val(TCNTB0, cnt);

    //Timer 0 Compare Buffer register
    set_val(TCMPB0, cmp);

    //Updates TCNTB0 and TCMPB0
    set_one(TCON, 1);

    //set_nbit(TCON, 0, 4, 0x9);
    //[3] 1 = Interval mode (auto-reload)
    //[2] 1 = TOUT_0 inverter-on
    //[1] 0 = No operation
    //[0] 1 = Starts Timer 0
    set_nbit(TCON, 0, 4, 0xd);
}

void pwm_timer4_irq_init(u32 s)
{
    //PCLK /(249+1) = 400000HZ
    set_nbit(TCFG0, 8, 8, 249); 
    //400000/4 = 100000HZ;
    set_nbit(TCFG1, 16, 4, 2);  //(100KHZ -> 10us) (1GHZ -> 1ns) (1MHZ -> 1us) (1KHZ -> 1ms)
    
    //使能中断timer4
    set_one(TINT_CSTAT, 4);

    set_val(TCNTB4, s * 100000);
    set_one(TCON, 21);          //Updates TCNTB4

    set_nbit(TCON, 20, 3, 5);   //auto-reload 和 Starts Timer 4
}

void do_pwm_timer4(void)
{
    printf("pwm timer4 handler\n");
    set_one(TINT_CSTAT, 9);
}
