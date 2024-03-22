// 设计基类 Point，数据成员有：坐标值x 和 坐标值y，成员函数有：构造函数，面积函数Area()；
// Point的派生类 Rectangle ，增加数据成员：坐标值x1 和 坐标值y1，同样有构造函数 和 面积函数Area()；
// Point的派生类 Circle，增加数据成员：半径r，同样有构造函数 和 面积函数Area()；
// 请完成以下代码，验证虚函数的使用效果。

#include <iostream>
using namespace std;

class Point {
protected:
    int x;
    int y;

public:
    Point(int X, int Y) : x(X), y(Y) {}

    ~Point() {}

    virtual int Area() {
        cout << "Call Point's Area function." << endl;
        return 0;
    }
};

class Rectangle : public Point {
private:
    int x1;
    int y1;

public:
    Rectangle(int x, int y, int X1, int Y1) : Point(x, y), x1(X1), y1(Y1) {} 

    ~Rectangle() {}

    int Area() override {
        cout << "Call Rectangle's Area function." << endl;
        return abs(x1 - x) * abs(y1 - y);
    }
};

class Circle : public Point {
private:
    double r;

public:
    Circle(int x, int y, int r) : Point(x, y), r(r) {}

    int Area() override {
        cout << "Call Circle's Area function." << endl;
        return 3.14 * r * r;
    }
};

double CalcArea( Point &ref ) {
    return ref.Area( );
}

int main( ) {
    Point p(0, 0);

    Rectangle r(1, 2, 4, 5);

    Circle c( 0, 0, 100 );

    cout << CalcArea( p ) << endl;
    cout << CalcArea( r ) << endl;
    cout << CalcArea( c ) << endl;

    Point *q = &c;
    cout << q->Area() << endl;

    q = &r;
    cout << q->Area() << endl;

    return 0;
}
