// 编写一个 stack栈类，在上一题的基础上：

// 增加：带一个参数 s 的构造函数，s 表示栈的初始大小。这个构造函数在最后输出一行：
//     “constructor 2”。它的意思是第2个构造函数，是为了区分第1个构造函数输出的 “constructing”
//     由于栈的存储空间不再固定大小了，请思考是否需要增加一个数据成员以记录当前的空间大小
//     增加：析构函数，如果有动态申请的内存，释放之

// 输入描述

//     在你的 main 函数中，首先使用带参数的构造函数创建一个栈对象，栈的大小由输入的第一行的正整数 s 决定。
//     第二行是命令的数量 n
//     接下来 n 行，每行是一条命令

// 输出描述
//     对第 3、4、5 类命令，输出一行：该命令对应取得的结果

#include <iostream>

using namespace std;

class Stack {
private:
    int* data;
    int tt;
    int len;

public:
    Stack(): tt(-1),len(1000) {
        data = new int[len];
        cout << "constructing" << endl;
    }

    Stack(int s): tt(-1),len(s) {
        data = new int[len];
        cout << "constructor 2" << endl;
    }

    ~Stack() {
        delete[] data;
        cout << "destructing" << endl;
    }

    bool top(int &v) {
        if (tt >= 0) {
            v = data[tt];
            return true;
        }
        return false;
    }

    void pop() {
        if (tt >= 0) {
            tt--;
        }
    }

    void push(int v) {
        if (tt + 1 < len) {
            tt++;
            data[tt] = v;
        }
    }

    int size() {
        return tt + 1;
    }

    void output() {
        for (int i = 0; i <= tt; i++) {
            cout << data[i] << " "; 
        }
        if (tt >= 0) {
            cout << endl;
        }
    }
};

int main() {
    int n,s;
    cin >> s;
    cin >> n;

    Stack stack(s);

    for (int i = 0; i < n; i++) {
        int commend;
        cin >> commend;
        if (commend == 1) {
            int a;
            cin >> a;
            stack.push(a);
        } else if (commend == 2) {
            stack.pop();
        } else if (commend == 3) {
            int v;
            if (stack.top(v)) {
                cout << v << endl;
            }
        } else if (commend == 4) {
            cout << stack.size() << endl;
        } else if (commend == 5) {
            stack.output();
        }
    }

    return 0;
}
