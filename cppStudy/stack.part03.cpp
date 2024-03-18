// 描述
//     编写一个 stack栈类，在上一题的基础上：
//     增加：拷贝构造函数，实现深拷贝。拷贝函数最后要输出一行：copy constructor

// 输入描述
//     两部分：第一部分是作用在第一个栈对象的 n 条命令，第二部分是作用在第二个栈对象的 m 条命令。
//     第一行是一个整数 S，表示创建一个容量为 S 的栈对象。
//     接下来一行是一个整数 n，表示接下来 n 行是作用在第一个栈对象的 n 条命令
//     接下来 n 行，每行是一条命令
//     然后在 main 函数中，用拷贝构造函数创建出第二个栈对象
//     接下来是一个整数 m，表示接下来 m 行是作用在第二个栈对象的 m 条命令
//     接下来 m 行，每行是一条命令

// 输出描述
//     对第3、4、5类命令，输出一行：该命令对应取得的结果

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

    Stack(const Stack& other): tt(other.tt), len(other.len) {
        data = new int[len];
        for (int i = 0; i <= tt; i++) {
            data[i] = other.data[i];
        }
        cout << "copy constructor" << endl;
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

    Stack stack1(s);

    for (int i = 0; i < n; i++) {
        int commend;
        cin >> commend;
        if (commend == 1) {
            int a;
            cin >> a;
            stack1.push(a);
        } else if (commend == 2) {
            stack1.pop();
        } else if (commend == 3) {
            int v;
            if (stack1.top(v)) {
                cout << v << endl;
            }
        } else if (commend == 4) {
            cout << stack1.size() << endl;
        } else if (commend == 5) {
            stack1.output();
        }
    }

    Stack stack2 = stack1;

    int m;
    cin >> m;

        for (int i = 0; i < m; i++) {
        int commend;
        cin >> commend;
        if (commend == 1) {
            int a;
            cin >> a;
            stack2.push(a);
        } else if (commend == 2) {
            stack2.pop();
        } else if (commend == 3) {
            int v;
            if (stack2.top(v)) {
                cout << v << endl;
            }
        } else if (commend == 4) {
            cout << stack2.size() << endl;
        } else if (commend == 5) {
            stack2.output();
        }
    }

    return 0;
}

// 4
// 6 
// 1 5
// 1 7
// 1 9
// 4
// 2
// 3 

// 12 
// 2
// 3
// 2
// 2 
// 1 10
// 1 11
// 1 12
// 1 13
// 1 14
// 1 15
// 3 
// 5  