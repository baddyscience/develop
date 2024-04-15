// 迭代器遍历容器-vector
// 读入 n 个整数，将这些数据保存到 vector 容器中。调用sort() 非降序排序后，采用正向迭代器和反向迭代器分别遍历 vector 中的元素并输出。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    for (vector<int>::reverse_iterator rit = numbers.rbegin(); rit != numbers.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    return 0;
}
