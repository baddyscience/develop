// 请按要求实现一个 MyStack 类模板，要求实现数据的封装和各种常用操作。
// 约定：
// 数据成员为私有属性，包括：
//     data ：一个指针，指向存放栈元素的空间，栈元素类型为 T
//     tt ： 指示栈顶位置
//     siz : 当前栈空间的大小
// 成员函数为公有属性，包括：
//     默认构造函数，完成初始化动作，栈空间的默认大小是 100 。
//     带一个参数 s 的构造函数，s 表示栈空间的初始大小。
//     析构函数：负责释放动态申请的内存。
//     拷贝构造函数，实现深拷贝。
//     top( &v )，函数返回如果为真，参数 v 带回栈顶元素的值；函数返回如果为假，参数 v 的值没有变化。
//     pop()，如果栈不空，弹走栈顶元素；如果栈空，没有动作。
//     push( v )，如果栈已满，没有动作；如果栈未满，参数 v 的值进栈。
//     size()，返回当前栈内元素个数，如果栈空，返回 0 。
//     重载 流插入运算符 << ：如果栈不空，自栈底到栈顶，输出栈内元素，每个元素后跟一个空格；如果栈空，没有输出。
//     重载 赋值运算符 = ：将一个栈对象赋值给另一个栈对象，要实现深拷贝
//     重载 等于比较运算符 == ： a 和 b 两个栈对象，当栈 a 的元素 与 栈 b 的元素个数相同且所有对应位置的元素相等时，表达式 a == b 为真
// 请实现上述功能。
// 完成 MyStack类 的 数据成员 以及 各成员函数 的实现。
#include <cstdio>
#include <iostream>
using namespace std;

template<typename T>
class MyStack {
public:
    // 无参默认构造函数
    MyStack() : siz(100), tt(-1), data(new T[100]) {}

    // 带一个参数 int s 的构造函数
    MyStack( unsigned s ) : siz(s), tt(-1), data(new T[s]) {}

    // 拷贝构造函数
    MyStack( const MyStack &b ) : siz(b.siz), tt(b.tt), data(new T[b.siz]) {
        for (int i = 0; i < b.siz; i++) {
            data[i] = b.data[i];
        }
    }

    // 析构函数
    ~MyStack() {
        delete[] data;
    }

    // 读取栈顶元素的值，赋值给 v
    bool top( T& v ) {
        if (tt == -1) {
            return false;
        }
        v = data[tt];
        return true;
    }

    // 弹出栈顶元素
    void pop() {
        if (tt >= 0)
            tt--;
    }

    // 压v进栈
    bool push( const T& v ) {
        if (tt >= siz-1)
            return false;
        tt++;
        data[tt] = v;
        return true;
    }

    // 当前栈内元素个数
    unsigned size() {
        return tt+1;
    }

    // 重载 流插入运算符 <<
    friend ostream & operator<< ( ostream &out, const MyStack& a ) {
        for (int i = 0; i <= a.tt; i++) {
            out << a.data[i] << ' ';
        }
        if (a.tt >= 0) out << endl;
        return out;
    }

    // 重载 赋值运算符 =
    MyStack & operator = ( const MyStack& b ) {
        if (this != &b) {
            T* newData = new T[b.siz];
            delete[] data;
            data = newData;
            siz = b.siz;
            tt = b.tt;
            for (int i = 0; i <= tt; i++) {
                data[i] = b.data[i];
            }
        }
        return *this;
    }

    // 等于 比较运算符 ==
    bool operator == ( const MyStack& b ) {
        if (tt != b.tt) return false;
        for (int i = 0; i <= tt; i++) {
            if (data[i] != b.data[i]) return false;
        }
        return true;
    }

private:
    // 此处定义数据成员
    T* data;
    int tt;
    int siz;
};

int main() {

    int si;
    cin >> si;
    MyStack<int> s1( si );  // 创建一个栈空间大小为 si 的栈 s1

    int command;
    int c, v;

    cin >> command;  // 读入命令个数
    while( command -- ) {
        cin >> c;  // 读入一条命令
        switch( c ) {
        case 1:  // 进栈
            cin >> v;
            s1.push( v );
            break;
        case 2:  // 出栈
            s1.pop();
            break;
        case 3:  // 读取栈顶元素
            if( s1.top( v ) )  // 如果返回为真，说明成功读取栈顶元素
                cout << v << endl;  // 输出之
            break;
        case 4:  // 栈内元素的个数
            cout << s1.size() << endl;
            break;
        case 5:  // 利用重载的 流插入运算符 输出 栈s1
            cout << s1; // 笔记：换行符要放在 operator<<运算符重载函数里面输出，否则会造成PE
            break;
        }
    }

    MyStack<int> s2( s1 );  // 利用拷贝构造函数创建一个新对象 s2
    cin >> command;
    while( command -- ) {
        cin >> c;
        switch( c ) {
        case 1:  // 进栈
            cin >> v;
            s2.push( v );
            break;
        case 2:  // 出栈
            s2.pop();
            break;
        case 3:  // 读取栈顶元素
            if( s2.top( v ) )  // 如果返回为真，说明成功读取栈顶元素
                cout << v << endl;  // 输出之
            break;
        case 4:  // 栈内元素的个数
            cout << s2.size() << endl;
            break;
        case 5:  // 利用重载的 流插入运算符 输出 栈s2
            cout << s2;
            break;
        }
    }

    if( s1 == s2 )  // 利用重载的 等于比较运算符 判断 s1 == s2 是否为真
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    MyStack<int> s3;  // 调用默认构造函数创建一个新对象 s3
    s3 = s1;  // 赋值运算符

    if( s3 == s1 )  // 利用重载的 等于比较运算符 判断 s3 == s1 是否为真
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    cin >> command;
    while( command -- ) {
        cin >> c;
        switch( c ) {
        case 1:  // 进栈
            cin >> v;
            s3.push( v );
            break;
        case 2:  // 出栈
            s3.pop();
            break;
        case 3:  // 读取栈顶元素
            if( s3.top( v ) )  // 如果返回为真，说明成功读取栈顶元素
                cout << v << endl;  // 输出之
            break;
        case 4:  // 栈内元素的个数
            cout << s3.size() << endl;
            break;
        case 5:  // 利用重载的 流插入运算符 输出 栈s3
            cout << s3;
            break;
        }
    }

    return 0;
}
