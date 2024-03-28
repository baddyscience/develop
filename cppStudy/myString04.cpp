// 字符串类的实现 4
// 在《字符串类的实现 3》的基础上，增加 myString字符串类 的方法：
//     重载 小于比较运算符 < ： a 和 b 两个字符串对象，从头到尾比较a和b的对应位置字符，当 this->data[i] < b.data[i] 时，表达式 a < b 为真
//     重载 大于比较运算符 > ： a 和 b 两个字符串对象，从头到尾比较a和b的对应位置字符，当 this->data[i] > b.data[i] 时，表达式 a > b 为真
//     重载 不等于运算符 != ： a 和 b 两个字符串对象，从头到尾比较a和b的对应位置字符，当 this->data[i] != b.data[i] 时，表达式 a != b 为真
//     重载 等于比较运算符 == ： 当 a 和 b 含字符个数相同且对应位置的字符相等时，表达式 a == b 为真
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

    // 小于比较运算符重载
    bool operator<(const myString& other) const {
        int minLen = this->len < other.len ? this->len : other.len;
        for (int i = 0; i < minLen; ++i) {
            if (this->data[i] < other.data[i]) return true;
            else if (this->data[i] > other.data[i]) return false;
        }
        return this->len < other.len;
    }

    // 大于比较运算符重载
    bool operator>(const myString& other) const {
        return other < *this;
    }

    // 不等于运算符重载
    bool operator!=(const myString& other) const {
        if (this->len != other.len) return true;
        for (int i = 0; i < this->len; i++) {
            if (this->data[i] != other.data[i]) return true;
        }
        return false;
    }

    // 等于比较运算符重载
    bool operator==(const myString& other) const {
        if (this->len != other.len) return false;
        for (int i = 0; i < this->len; i++) {
            if (this->data[i] != other.data[i]) return false;
        }
        return true;
    }
};

int main() {
    myString a, b;

    cin >> a;
    cin >> b;

    if ( a == b ) {
        cout << "a == b" << endl;
    }
    else {
        if ( a > b ) {
            cout << "a > b" << endl;
        }
        else {
            if ( a < b ) {
                cout << "a < b" << endl;  
            }
        }
     }   

    return 0;
}
