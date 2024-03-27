// 流插入运算符重载：编写一个stack类.part.4
// 编写一个 stack栈类，在上一题的基础上：
// 取消 output()函数，重载运算符 << ：第一行输出当前栈内元素个数，如果栈空，输出 0；
// 如果栈不空，第二行自栈底到栈顶，输出栈内元素，每个元素后跟一个空格。
// 如果栈空，第二行没有输出。
//     输入描述
// 在上一题的基础上增加一类指令：
// 8 ：表示使用运算符<< 输出当前的栈对象
// 第一行是一个整数m，表示创建一个容量为m的栈对象。
// 第二行是命令的数量n
// 接下来n行，每行是一条命令
//     输出描述
// 对第3、4、8类命令，输出一行或两行：该命令对应取得的结果

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

    friend ostream& operator<<(ostream& os, const Stack& s);

    // void output() {
    //     for (int i = 0; i <= tt; i++) {
    //         cout << data[i] << " "; 
    //     }
    //     if (tt >= 0) {
    //         cout << endl;
    //     }
    // }
};

ostream& operator<<(ostream& os, const Stack& s) {
    if (s.tt >= 0) {
        for (int i = 0; i <= s.tt; i++) {
            os << s.data[i] << " ";
        }
        os << endl;
    } else {
        os << "Stack is empty" << endl;
    }
    return os;
}

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
        } else if (commend == 8) {
            cout << stack.size() << endl;
            if (stack.size() != 0)
            	cout << stack;
        }
    }

    return 0;
}
