#include <iostream>
#include <string>

using namespace std;

    
/*
 *(1) 在一个字符串数组中包含若干个(现为5个)元素，每个元素相当于一个字符串变量。
 *(2) 并不要求每个字符串元素具有相同的长度，即使对同一个元素而言，它的长度也是可以变化的，当向某一个元素重新赋值，其长度就可能发生变化。
 *(3) 在字符串数组的每一个元素中存放一个字符串，而不是一个字符，这是字符串数组与字符数组的区别。如果用字符数组存放字符串，一个元素只能存放一个字符，用一个一维字符数组存放一个字符串。
 *(4) 每一个字符串元素中只包含字符串本身的字符而不包括′＼0′。
 *    
 */

//字符串数组
int main(void)
{
    //定义字符串数组 并且初始化
    string str[5] = {"zhangsan", "lis", "wangwu", "uplooking", "cec"}; 

    for (int i = 0; i < 5; i++)
    {
        cout << str[i] << endl;
    }
    //修改字符串对象中的一个字符
    str[0][0] = 'Z';
    cout << str[0] << endl;

    return 0;
}
