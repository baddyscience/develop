// 编写一个 myString字符串类，实现：

// 1.封装数据和操作

// 2.数据成员为私有属性，包括：
//     一个字符指针 data，指向字符数组
//     一个表示当前字符串含字符个数的整型变量 len

// 3.成员函数为公有属性，包括：
//     默认构造函数 myString()，完成初始化动作：字符指针清空，字符个数为0
//     带一个字符数组参数 s 的构造函数 myString( char s[] )，构造一个 data 为 s 的对象（注意不要复制 s 末尾的’\0’或’\n’或’\r’等字符）
//     拷贝构造函数 myString( myString &b )，实现深拷贝
//     析构函数 ~myString() ，如果有动态申请的内存，释放之
//     输出函数 output()，输出data的内容

#include <iostream>
#include <cstring>

using namespace std;

class myString{
private:
    char *data;
    int len;

public:
    myString() {
        data = nullptr;
        len = 0;
    }

    myString(char s[]) {
        len = strlen(s);
        data = new char(len + 1);
        strcpy(data, s);
    }

    myString(myString &b) {
        len = b.len;
        if (b.data) {
            data = new char[len + 1];
            strcpy(data, b.data);
        } else {
            data = nullptr;
        }
    }

    ~myString() {
        delete[] data;
    }

    void output() {
        if(data) {
            cout << data;
        }
    }
};


int main() {
    char str[] = { "hello, c++" };

    myString a;  // 无参构造函数

    myString b( str );  // 有参构造函数
    b.output();  // 预期输出第一行：hello, c++
    cout << endl;

    {
        myString c( b );  // 拷贝构造函数。把这个对象放在局部代码中，目的是测试深拷贝。
        c.output();  // 预期输出第二行：hello, c++
        cout << endl;
    }

    b.output();  // 预期输出第三行：hello, c++
    cout << endl;

    return 0;
}
