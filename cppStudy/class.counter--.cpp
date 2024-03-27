// 实现计数器的前自减、后自减运算
// 设计一个计算器类Counter，它只有一个用于计数的数据成员cnt，该计数器的有效计数范围是0-65535，实现计数器的前自减、后自减运算。
// 补充完成以下程序：

#include <iostream>
using namespace std;

class Counter {
    int cnt;

public:
    Counter(int n) : cnt(n) {}

    ~Counter() {}

    Counter& operator--() {
        cnt--;
        if(cnt == -1)
            cnt = 65535;
        return *this;
    }

    Counter operator--(int) {
        cnt--;
        if(cnt == -1)
            cnt = 65535;
        return *this;
    }

    void display() {
        cout << "counter = " << cnt << endl;
    }
};

int main() {
    Counter a(200);
    ----a;
    a.display();

    for( int i = 0; i < 100; i++ )
        a--;
    a.display();

    return 0;
}

