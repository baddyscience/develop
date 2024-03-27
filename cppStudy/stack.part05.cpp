// 赋值运算符、比较运算符重载：编写一个stack类.part.5
// 编写一个 stack栈类，在上一题的基础上：
// 重载 赋值运算符 =  ：将一个栈对象赋值给另一个栈对象，实现深拷贝，最后输出一句：assignment
// 重载 小于比较运算符 <    ： a 和 b 两个栈对象，当栈 a 的元素比栈 b 的元素个数少时，表达式 a < b 为真
// 重载 大于比较运算符 >    ： a 和 b 两个栈对象，当栈 a 的元素比栈 b 的元素个数多时，表达式 a > b 为真
// 重载 不等于运算符 !=      ： a 和 b 两个栈对象，当栈 a 的元素 与 栈 b 的元素个数不相同时；或者元素个数相等，但任意一个对应位置的元素不等时，表达式 a != b 为真
// 重载 等于比较运算符 == ： a 和 b 两个栈对象，当栈 a 的元素 与 栈 b 的元素个数相同且所有对应位置的元素相等时，表达式 a == b 为真
// 注意：如果采用重载友元函数的方式，使用时就变成类似：operator<(s1, s2) 这样。这与习惯上的写法 s1 < s2 差别比较大。所以不提倡友元函数写法。
// 此外，请思考，比较运算符的返回值，应该是什么类型

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

    Stack(const Stack& other) : len(other.len), tt(other.tt) {
        data = new int[len];
        for (int i = 0; i <= tt; i++) {
            data[i] = other.data[i];
        }
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

    int size() const {
        return tt + 1;
    }

    // 在 Stack 类内部添加友元声明
    friend ostream& operator<<(ostream& os, const Stack& s);

    // void output() {
    //     for (int i = 0; i <= tt; i++) {
    //         cout << data[i] << " "; 
    //     }
    //     if (tt >= 0) {
    //         cout << endl;
    //     }
    // }

    // 赋值运算符重载，实现深拷贝
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] data; // 释放当前对象的资源
            len = other.len;
            tt = other.tt;
            data = new int[len];
            for (int i = 0; i <= tt; i++) {
                data[i] = other.data[i];
            }
        }
        cout << "assignment" << endl;
        return *this;
    }

    // 小于比较运算符重载
    bool operator<(const Stack& other) const {
        return this->size() < other.size();
    }

    // 大于比较运算符重载
    bool operator>(const Stack& other) const {
        return this->size() > other.size();
    }

    // 不等于运算符重载
    bool operator!=(const Stack& other) const {
        if (this->size() != other.size()) return true;
        for (int i = 0; i < this->size(); i++) {
            if (this->data[i] != other.data[i]) return true;
        }
        return false;
    }

    // 等于比较运算符重载
    bool operator==(const Stack& other) const {
        if (this->size() != other.size()) return false;
        for (int i = 0; i < this->size(); i++) {
            if (this->data[i] != other.data[i]) return false;
        }
        return true;
    }
};

// 在 Stack 类外部定义重载的 << 运算符
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
    int m, n;
    cin >> m;
    Stack stack1(m);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int command;
        cin >> command;
        if (command == 1) {
            int a;
            cin >> a;
            stack1.push(a);
        } else if (command == 2) {
            stack1.pop();
        } else if (command == 3) {
            int v;
            if (stack1.top(v)) {
                cout << v << endl;
            }
        } else if (command == 4) {
            cout << stack1.size() << endl;
        } else if (command == 8) {
            cout << stack1.size() << endl;
            if(stack1.size() != 0)
                cout << stack1;
        }
    }

    Stack stack2;
    stack2 = stack1;

    cin >> m;
    for (int i = 0; i < m; i++) {
        int command;
        cin >> command;
        if (command == 1) {
            int a;
            cin >> a;
            stack2.push(a);
        } else if (command == 2) {
            stack2.pop();
        } else if (command == 3) {
            int v;
            if (stack2.top(v)) {
                cout << v << endl;
            }
        } else if (command == 4) {
            cout << stack2.size() << endl;
        } else if (command == 8) {
            cout << stack2.size() << endl;
            if(stack2.size() != 0)
                cout << stack2;
        } else if (command == 10) {
            cout << (stack1 < stack2 ? "yes" : "no") << endl;
        } else if (command == 11) {
            cout << (stack1 > stack2 ? "yes" : "no") << endl;
        } else if (command == 12) {
            cout << (stack1 != stack2 ? "yes" : "no") << endl;
        } else if (command == 13) {
            cout << (stack1 == stack2 ? "yes" : "no") << endl;
        }
    }

    return 0;
}
