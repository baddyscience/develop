// 定义并实现一个矩形类 rectangle，有长(length)、宽(wide) 两个属性，
// 成员函数 area() 计算矩形的面积，成员函数 setlength()、getlength()、setwide()、getwide() 分别设置和获取 length 或者 wide 的值，
// 成员函数 display() 输出矩形的信息（长，宽，面积），
// 要求定义构造函数、拷贝构造函数、赋值运算符函数，能使用对象数组。
// 请补充完成以下程序：

#include <iostream>
using namespace std;

class rectangle {
private:
    int length;
    int wide;

public:
    rectangle() : length(0), wide(0) {}

    rectangle(int l, int w) : length(l), wide(w) {}

    ~rectangle() {}

    rectangle(rectangle& other) : length(other.length), wide(other.wide) {}

    rectangle& operator = (rectangle& other) {
        if (this != &other) {
            length = other.length;
            wide = other.wide;
        }
        return *this;
    }

    void setlength(int l) {
        length = l;
    }

    int getlength() {
        return length;
    }

    void setwide(int w) {
        wide = w;
    }

    int getwide() {
        return wide;
    }

    int area() {
        return length * wide;
    }

    void display() {
        cout << "message of the rectangle:length=" << length << " wide=" << wide << " area=" << area() << endl;
    }
};

int main( ) {
   rectangle r1( 3, 4 );     // 定义一个矩形 r1，长为 3，宽为 4
   r1.display();     // 输出矩形r1的有关信息

   rectangle r2;     // 定义一个矩形r2
   r2 = r1;
   r2.display();     // 输出矩形 r2 的有关信息
   r2.setlength( 10 );   // 把矩形 r2 的长 length 改为 10
   r2.setwide( 20 );     // 把矩形 r2 的宽 wide 改为 20
   r2.display();     // 再输出矩形 r2 的有关信息

   rectangle r3( r1 );
   r3.display();     // 输出矩形 r3 的有关信息

   rectangle r4[4];     // 定义矩形数组 r4
   for( int i = 0; i < 4; i ++ )     // 输出矩形数组 r4 中各个矩形的信息
       r4[i].display();

   return 0;
}
