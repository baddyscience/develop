// 字符串类的实现 3
// 在《字符串类的实现 2》的基础上，增加 myString字符串类 的方法：
//     重载运算符 << ：先输出 len ，然后一个空格，一个冒号，再一个空格，然后输出 data 所指字符数组。如果不含字符，则只输出一个 0。
//     重载运算符 >> ：读入字符串，存入 data 所指字符数组。注意：读入的一行字符串长度可能很大，建议先读入到一个 string 对象后再处理。
// 完成以下程序：

#include <iostream>
#include <cstring>
using namespace std;

class myString {
private:
    char* data;
    int len;
public:
    myString() : data(nullptr), len(0) {}

    myString(const myString& str);

    myString& operator=(const myString& str);

    ~myString() {
        delete[] data; 
    }

    friend ostream& operator<<(ostream& os, const myString& str) {
        if (str.len > 0) {
            os << str.len << " : " << str.data;
        } else {
            os << "0";
        }
        return os;
    }

    friend istream& operator>>(istream& is, myString& str) {
        string input;
        getline(is, input);

        delete[] str.data;
        str.len = input.length();
        str.data = new char[str.len + 1];
        strcpy(str.data, input.c_str());

        return is;
    }
};

int main() {

    myString a;

    int n;
    cin >> n;

    // 以下2行没有本质作用，仅用于吸收换行符，就是 n 后面那个换行符
    string tmp;
    getline( cin, tmp );

    for ( int i = 0; i < n; i++ ) {
        cin >> a;
        cout << a << endl;
    }

    return 0;
}
