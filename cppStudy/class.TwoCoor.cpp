// 实现两坐标点的加、减运算
// 建立一个二维坐标系的类TwoCoor，用x、y表示坐标值，均为整型。请实现两坐标点的加、减运算。
// 完成以下代码：

#include <iostream>
using namespace std;

//你写的代码放在这里
class TwoCoor {
private:
    int x,
        y;

public:
    TwoCoor() : x(0), y(0) {}

    TwoCoor(int x1, int y1) : x(x1), y(y1) {}

    ~TwoCoor() {}

    TwoCoor operator+ (TwoCoor &a) {
        int newx = x + a.x;
        int newy = y + a.y;
        TwoCoor New(newx, newy);
        return New;
    }

    TwoCoor operator- (TwoCoor &a) {
        int newx = x - a.x;
        int newy = y - a.y;
        TwoCoor New(newx, newy);
        return New;
    }

    void display() {
        cout << "(" << x << "," << y << ")" << endl;
    }
}; 

int main() {
   TwoCoor p1(1, 2), p2(-1, 1), p3, p4;

   p3 = p1 + p2;
   p4 = p1 - p2;

   p3.display();
   p4.display();

   return 0;
}
