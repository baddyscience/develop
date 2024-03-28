// 字符串类的实现 5
// 在上一题基础上，增加 myString字符串类 的方法：
//     重载 下标运算符[] ： operator [] ( int i ) ，要求作为左操作数，即把一个字符写入数据成员 data[i] 中
//     重载 下标运算符[] ： operator [] ( int i ) ，要求作为右操作数，只读，即读取数据成员 data[i] 的值
//     重载 MyString类 到 char * 类型的转换 ：operator char * () ，这个的目的是给下面的 read() 函数用的
// 请补充完成以下程序：

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

    // 重载下标运算符[]作为左操作数
    char& operator[](int i) {
        if (i >= 0 && i < len) {
            return data[i];
        } else {
            throw std::out_of_range("Index out of bounds");
        }
    }

    // 重载下标运算符[]作为右操作数
    const char& operator[](int i) const {
        if (i >= 0 && i < len) {
            return data[i];
        } else {
            throw std::out_of_range("Index out of bounds");
        }
    }

    // MyString类到char*类型的转换
    operator char* () {
        return data;
    }

    int size() const { return len; }
};

void read( char *p, int n ) {
    for ( int i = 0; i < n; i++ )
        cin >> p[i];
}

int main() {
    myString a;

    cin >> a;   /// 验证 流提取运算符的重载
    cout << a << endl;  /// 验证 流插入运算符的重载

    for ( int i = 0; i < a.size(); i ++ )
        cin >> a[i];   /// 验证下标运算符的重载

    string tmp;
    cin >> tmp; /// 吸收掉上一行剩余的内容，不至影响到下面的 read()

    for ( int i = 0; i < a.size(); i ++ )
        cout << a[i];
    cout << endl;
    
    read( a, 20 );  /// 验证 类型转换的重载

    cout << a << endl;

    return 0;
}