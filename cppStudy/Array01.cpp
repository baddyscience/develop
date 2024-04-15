// 使用 STL容器 array 完成以下操作。
// 创建两个数组 a1, a2。
// 使用正向迭代器遍历 a1，求 a1 的前缀和。
// 使用反向迭代器遍历 a2，求 a2 的元素之和。
// 通过下标[ ]、at()、front()、back()、data()等函数访问array容器内的元素。
// 使用fill()、swap()函数。
// 使用 > < == 等符号对两个array数组容器进行比较。
// 完成以下代码

#include <iostream>
#include <array>
using namespace std;

const int N = 10;

int main() {
    array<int, N> a1, a2;

    for (int i = 0; i < N; ++i) {
        cin >> a1[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> a2[i];
    }

    array<int, N> prefix_sums = a1;
    for (int i = 1; i < N; ++i) {
        prefix_sums[i] += prefix_sums[i - 1];
    }

    for (const int& num : prefix_sums) {
        cout << num << " ";
    }
    cout << endl;

    int sum_a2 = 0;
    for (auto it = a2.rbegin(); it != a2.rend(); ++it) {
        sum_a2 += *it;
    }
    cout << sum_a2 << endl;

    cout << a1.front() << " " << a1.back() << " " << a1.at(N / 2) << " " << static_cast<void*>(a1.data()) << endl;

    if (a1 < a2) {
        cout << "a1 < a2" << endl;
    }
    if (a1 > a2) {
        cout << "a1 > a2" << endl;
    }

    a2 = a1;
    if (a1 == a2) {
        cout << "a1 == a2" << endl;
    }

    a1.fill(1);
    a2.fill(10);
    a1.swap(a2);

    for (const int& num : a1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
