// 在《字符串类的实现1》的基础上，增加 myString字符串类 的方法：

// size()，返回当前对象含字符的个数，如果不含字符串，返回0
// int set( char s[] )，逐字符拷贝 s[] 到 data[]，len 也要相应改变。返回值是新的字符个数，即 len
// 重载 赋值运算符 myString &operator= ( const myString &b ) ：将右侧运算对象 myString对象赋值给 左侧运算对象 myString对象。
// 注意：1. 如果左侧运算对象的data非空，要先释放；2. 要实现深拷贝。 关于深拷贝，可参考最下方的附录
// 重载 +运算符 myString operator+ ( const myString &b ) ：把右侧运算对象 b 的 data 追加到左侧运算对象 a 的 data 后面，返回一个新对象的引用
// 取子串函数 sub( int start, int l )：返回一个 myString 对象，其 data 为当前对象的 data[start, start + l]。注意：当开始位置 start 大于当前对象的字符个数时，返回一个 data 为空的对象；当 start + l 大于当前对象字符总数时，取到末尾
// 补充完成以下程序：

#include <iostream>
#include <cstring>
using namespace std;

class myString {
private:
    char *data;
    int len;

public:
    myString() : data(new char[1]), len(0) {
        data[0] = '\0';
    }

    myString(char *s) {
        len = strlen(s);
        data = new char[len + 1];
        strcpy(data, s);
    }

    myString(const myString &b) {
        len = b.len;
        data = new char[len + 1];
        strcpy(data, b.data);
    }

    ~myString() {
        delete[] data;
    }

    myString &operator=(const myString &b) {
        if (this != &b) {
            delete[] data;
            len = b.len;
            data = new char[len + 1];
            strcpy(data, b.data);
        }
        return *this;
    }

    myString operator+(const myString &b) {
        myString temp;
        temp.len = len + b.len;
        temp.data = new char[temp.len + 1];
        strcpy(temp.data, data);
        strcat(temp.data, b.data);
        return temp;
    }

    int set(char *s) {
        delete[] data;
        len = strlen(s);
        data = new char[len + 1];
        strcpy(data, s);
        return len;
    }

    int size() const {
        return len;
    }

    myString sub( int start, int l ) {
			myString ms;
			myString temp;
			if(start > len) {
			    ms.len = 0;
			    return ms;
			}
			if(start + l <= len) {
			    temp.len = l;
				temp.data = new char[l];
				for(int i = 0; i < l; i++)
				temp.data[i] = data[start + i - 1];
			}
			if(start + l > len) {
				temp.len = len - start + 1;
				temp.data = new char[temp.len];
				for(int i = 0; i < temp.len; i++)
				temp.data[i] = data[start + i - 1];
			}
		return temp;
    }

    void output() {
        if (data) {
            cout << data;
        }
    }
};

int main() {
    myString tmp;
    cout << tmp.size() << endl;  // 预期输出：0

    char s1[] = "abcd";
    myString a(s1);
    a.output();  // 预期输出：abcd
    cout << endl;
    cout << a.size() << endl;  // 预期输出：4

    char s2[] = "1234";
    myString b(s2);
    b.output();  // 预期输出：1234
    cout << endl;

    myString c;
    c = a;  // 赋值运算符
    c.output();  // 预期输出：abcd
    cout << endl;
    cout << c.size() << endl;  // 预期输出：4

    c = a + b;
    c.output();  // 预期输出：abcd1234
    cout << endl;
    cout << c.size() << endl;  // 预期输出：8

    b = c.sub(3, 4);
    b.output();  // 预期输出：cd12
    cout << endl;

    b = c.sub(6, 10);  // 从第6个位置至末尾，最多只有3个字符，全部取完
    b.output();  // 预期输出：234
    cout << endl;
    
    b = c.sub(9, 2);  // 第9个位置已经超越c的长度，取得空字符串
    b.output();  // 预期没有字符输出
    cout << endl;
    
    char s3[] = "77777777777777777777";
    c.set(s3);
    c.output();  // 预期输出20个7
    cout << endl;
    return 0;
}
