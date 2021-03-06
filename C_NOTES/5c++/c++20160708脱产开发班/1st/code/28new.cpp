#include <iostream>

using namespace std;


#if 0

    new运算符使用的一般格式为
    new 类型 (初值)
    用new分配数组空间时不能指定初值。如果由于内存不足等原因而无法正常分配空间，则new会返回一个空指针NULL，用户可以根据该指针的值判断分配空间是否成功。


    delete运算符使用的一般格式为
    delete [ ] 指针变量
    例如要撤销上面用new开辟的存放单精度数的空间(上面第5个例子)，应该用
    delete  p；
    前面用“new char[10];”开辟的字符数组空间，如果把new返回的指针赋给了指针变量pt，则应该用以下形式的delete运算符撤销该空间： 
    delete [] pt；      //在指针变量前面加一对方括号，表示是对数组空间的操作
#endif
    
    

// new delete都是运算符
int main(void)
{
    int *p = NULL;
    int *p1 = NULL;
    float *p2 = NULL;


    //分配空间  空间大小为sizeof(int)
    p = new int;
    *p = 100;
    cout << "*p = " << *p << endl;

    //分配空间之后 初始化
    p1 = new int(88);
    cout << "*p1 = " << *p1 << endl;

    p2 = new float(3.1415926);
    cout << "*p2 = " << *p2 << endl;

    //释放空间
    delete p;

    delete p1;

    delete p2;

    return 0;
}
