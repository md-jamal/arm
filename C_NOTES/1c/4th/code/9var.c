#include <stdio.h>

/*
 *9. 局部变量和全局变量
 *     局部变量；
 *     定义变量可能有三种情况：
 *         在函数的开头定义  形参
 *         在函数内的复合语句内定义
 *
 *     局部变量的生命周期:
 *     在一个函数内部定义的变量只在本函数范围内有效
 *     在复合语句内定义的变量只在本复合语句范围内有效
 *
 *     在函数内部或复合语句内部定义的变量称为“局部变量”
 *
 *     全局变量：
 *     在函数内定义的变量是局部变量，而在函数之外定义的变量称为全局变量
 *     外部变量是全局变量(也称全程变量)
 *     全局变量可以为本文件中其他函数所共用
 *     有效范围为从定义变量的位置开始到本源文件结束
 */

//全局变量一般放在bss或者data段
int a = 3;

//局部变量一般放在栈中
//函数的形参是局部变量
int add(int x, int y)
{
    return x + y;
}

int main(void)
{
    int a = 3;
    {
        //在复合语句中定义的局部变量
        int a = 4;
        //就进原则  输出的是代码快中定义的a 它的生命周期到代码块中就结束
        printf("a = %d\n", a);
    }
    //代码块中定义的a在此不可见
    printf("a = %d\n", a);

    return 0;
}
