// 所谓的智能排队系统-deque
// 请设计一个排队程序。用户有 普通客人 和 VIP客人 之分，新增 VIP客人放在队列头部，新增普通客人放入队尾。

#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
    deque<string> queue;
    string name, status;

    while (cin >> name >> status) {
        if (status == "VIP") {
            queue.push_front(name);
        } else {
            queue.push_back(name);
        }
    }

    for (const auto& n : queue) {
        cout << n << endl;
    }

    return 0;
}
