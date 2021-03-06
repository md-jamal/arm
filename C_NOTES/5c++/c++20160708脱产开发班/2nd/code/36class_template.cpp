#include <iostream>
#include <string>

using namespace std;

//范型编程
//类模板
//T1是虚拟的类型
template <typename T1>
class Compare{
public:
    Compare();
    Compare(T1 x, T1 y);
    
    ~Compare();
    T1 max(void);
    T1 min(void);
private:
    T1 x;
    T1 y;
};

//在类外定义成员函数
template <typename T1>
Compare<T1>::Compare()
{
    x = 0; 
    y = 0;
    cout << "empty constructor" << endl;
}

template <typename T1>
Compare<T1>::Compare(T1 x, T1 y)
{
    this->x = x;
    this->y = y;
    cout << "constructor" << endl;
}

template <typename T1>
Compare<T1>::~Compare()
{
    cout << "destructor" << endl;
}

template <typename T1>
T1 Compare<T1>::max(void)
{
    return x > y ? x : y; 
}

template <typename T1>
T1 Compare<T1>::min(void)
{
    return x > y ? y : x; 
}



int main(void)
{
    //Compare是抽象的类
    //Compare<int>是具体的类
    Compare<int> c(3, 4);
    cout << "int max: " << c.max() << " int min: " << c.min() << endl;;

    Compare<float> c1(3.3, 44.4);
    cout << "float max: " << c1.max() << " float min: " << c1.min() << endl;;

    Compare<string> c2("uplooling", "shenzhen");
    cout << "string max: " << c2.max() << " string min: " << c2.min() << endl;;

    return 0;
}
