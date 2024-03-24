// 实现两个计数器相加减的运算
// 设计一个计数器类 Counter，它只有一个用于计数的数据成员 cnt，该计数器的有效计数范围是 0 ~ 65535，实现两个计数器相加减的运算。
// 完成以下代码：

#include <iostream>
using namespace std;

//你写的代码放在这里
class Counter {
private:
    int cnt;

public:
    Counter() : cnt(0) {}

    Counter(int n) : cnt(n) {}

    ~Counter() {}

    Counter operator+ (Counter &a) {
        int New = (cnt + a.cnt) % 65535;
        Counter Newa(New);
        return Newa;
    }

    Counter operator- (Counter &a) {
        int New = (cnt - a.cnt) % 65535;
        Counter Newa(New);
        return Newa;
    }

    void display() {
        cout << "counter = " << cnt << endl;
    }
};

int main() {
    Counter a(100), b(200), c, d;

    c = a + b;
    c.display();

    d = b - a;
    d.display();

    return 0;
}
