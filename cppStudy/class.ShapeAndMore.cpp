// 定义一个基类 Shape，在此基础上派生出 Rectangle 和 Circle，两者都有 getArea() 函数计算对象的面积。使用 Rectangle 类创建一个派生类 Square。
// 1、在 Rectangle 类中有长和宽两个数据成员，在 Circle 类中有一个数据成员即半径。
// 2、本题圆周率使用3.14
// 请完善下面的程序。

#include <iostream>
using namespace std;

class Shape {
public:
   virtual float getArea() = 0;
   virtual ~Shape() { }
};

class Rectangle : public Shape {
private:
    float loong;
    float weight;

public:
    Rectangle(float l, float w) : loong(l), weight(w) {}

    ~Rectangle() {}

    virtual float getArea() override {
        return weight * loong;
    }
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : radius(r) {}

    ~Circle() {} 

    virtual float getArea() override {
        return 3.14 * radius * radius;
    }
};

class Square : public Rectangle {
public:
    Square(float side) : Rectangle(side, side) { }

};

int main( ) {
   Shape *ps;
   ps = new Circle( 5 );
   cout << "The area of the Circle is " << ps->getArea() << endl;
   delete ps;

   Rectangle *pr;
   pr = new Rectangle( 5, 6 );
   cout << "The area of the Rectagle is " << pr->getArea() << endl;
   delete pr;

   Square s( 8 );
   pr = &s;
   cout << "The area of the Square is " << pr->getArea() << endl;
   // delete pr;  这里不能 delete 。为什么？
   //因为 pr 此时指向的是一个栈上的对象（即 Square s(8); 创建的对象），它会在其作用域结束时自动被销毁
   
   return 0;
}
