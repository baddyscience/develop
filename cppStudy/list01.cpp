// 合并链表-list
// 给出 2 组个数分别是 n 和 m 的整数，将这两组数据分别存储在 list 容器中，并将两个链表合并，合并之后删除重复元素，对链表中的值从小到大排序。
#include <iostream>
#include <list>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    list<int> list1, list2;
    int value;

    for (int i = 0; i < n; ++i) {
        cin >> value;
        list1.push_back(value);
    }

    for (int i = 0; i < m; ++i) {
        cin >> value;
        list2.push_back(value);
    }

    list1.insert(list1.end(), list2.begin(), list2.end());

    set<int> unique_sorted(list1.begin(), list1.end());

    list1.assign(unique_sorted.begin(), unique_sorted.end());

    for (int num : list1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
