// 迭代器遍历set
// 读入若干个整数，将这些数据保存到 set 容器中。采用正向迭代器和反向迭代器分别遍历 set 中的元素并输出。

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> numbers;
    int number;

    while (cin >> number) {
        numbers.insert(number);
    }

    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (auto rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    return 0;
}
