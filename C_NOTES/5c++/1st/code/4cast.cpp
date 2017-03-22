#include <iostream>
using namespace std;


/*
 *
 *    强制类型转换的一般形式为
 *    （类型名）（表达式）
 *    注意： 如果要进行强制类型转换的对象是一个变量，该变量可以不用括号括起来。如果要进行强制类型转换的对象是一个包含多项的表达式，则表达式应该用括号括起来。
 *    
 *    C++把它保留了下来，以利于兼容。C++还增加了以下形式： 
 *    类型名（表达式）
 *    如int(x)  或 int(x+y)
 *    类型名不加括号，而变量或表达式用括号括起来。这种形式类似于函数调用。但许多人仍习惯于用第一种形式，把类型名包在括号内，这样比较清楚。
 *    需要说明的是在强制类型转换时，得到一个所需类型的中间变量，但原来变量的类型未发生变化。
 *
 */

int main(void)
{
    float f1 = 3.1415926;
    int i = 3333;
    //C语言风格
    cout << "i + f1 = " << (int)(i + f1) << endl;
    
    //C++风格
    cout << "i + f1 = " << int(i + f1) << endl;


    return 0;
}