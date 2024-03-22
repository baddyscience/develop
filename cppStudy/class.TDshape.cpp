// 用抽象类设计计算二维平面图形面积的程序，在基类 TDshape 中设计纯虚函数 area() 和 printName() 。
// area() 用于计算几何图形的面积，printName() 用于打印输出几何图形的类名，如 Triangle 类的对象就打印输出“Triangle”。
// 每个具体形状的类则从抽象类 TDshape 派生，各自定义其独有的数据成员和成员函数，并定义 area() 和 printName() 的具体实现代码。
// 函数 fp 和函数 fr 是以 TDshape 为接口的函数，借以访问具体类如 Triangle 和 Rectangle 类的成员函数 area() 和 printName() 。

#include <iostream>
using namespace std;

// 抽象基类 TDshape
class TDshape {
public:
    // 纯虚函数
    virtual double area() const = 0;
    virtual void printName() const = 0;
    virtual ~TDshape() {} // 提供虚析构函数以确保派生类对象的正确析构
};

// Triangle 类定义
class Triangle : public TDshape {
private:
    double width;
    double height;
public:
    Triangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height / 2;
    }
    void printName() const override {
        cout << "Triangle" << endl;
    }
};

// Rectangle 类定义
class Rectangle : public TDshape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    void setWidth(double w) {
        width = w;
    }
    double area() const override {
        return width * height;
    }
    void printName() const override {
        cout << "Rectangle" << endl;
    }
};

void fp(TDshape *p) {
    cout << "area:" << p->area() << endl;
    p->printName();
}

void fr(TDshape &r) {
    cout << "area:" << r.area() << endl;
    r.printName();
}

int main() {
    Triangle triangle(3, 4); // width为3, height为4
    Rectangle rectangle(4, 9); // width为4, height为9
    rectangle.setWidth(10);

    cout << "******from fp:" << endl;
    fp(&triangle);
    fp(&rectangle);

    cout << "******from fr:" << endl;
    fr(triangle);
    fr(rectangle);

    return 0;
}