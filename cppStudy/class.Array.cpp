// 请实现一个模版类 Array ，实现可以直接访问的线性群体，包括：
// 私有数据成员：
//     T* list;    /// 用于存放动态分配的数组内存首地址
//     int siz;    /// 数组大小。为了避免与 size 同名而高亮显示，特意减少一个字符
// 成员函数：
//     构造函数 ： Array( int sz = 10 )
//     拷贝构造函数 ： Array( const Array<T> &a )
//     析构函数 ： ~Array()
//     重载赋值运算符 operator = ： operator = ( const Array<T> &rhs )
//     重载 下标运算符[] ，用于 左值： operator [] ( int i )
//     重载 下标运算符[] 常函数，用于 右值 ： operator [] ( int i ) const
//     重载到 T* 类型的转换 ：operator T * ()
//     取数组的大小 ： getSize()
//     修改数组的大小 ： resize( int sz )
// 补充完整以下程序：
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

template<typename T>
class Array {
private:
    T* list;
    int size;

public:
    Array(int sz = 10) : size(sz), list(new T[sz]) {}

    Array(const Array<T> &a) : size(a.size), list(new T[a.size]) {
        for (int i = 0; i < a.size; i++) {
            list[i] = a.list[i];
        }
    }

    ~Array() {
        delete[] list;
    }

    Array<T>& operator=(const Array<T>& rhs) {
        if (this != &rhs) {
            delete[] list;
            size = rhs.siz;
            list = new T[size];
            for (int i = 0; i < size; i++) {
                list[i] = rhs.list[i];
            }
        }
        return *this;
    }

    T& operator[](int i) {
        assert(i >= 0 && i < size);
        return list[i];
    }

    const T& operator[](int i) const {
        assert(i >= 0 && i < size);
        return list[i];
    }

    operator T* () {
        return list;
    }

    int getSize() const {
        return size;
    }

    void resize(int sz) {
        T* newList = new T[sz];
        int minSize = (sz < size) ? sz : size;
        for (int i = 0; i < minSize; i++) {
            newList[i] = list[i];
        }
        delete[] list;
        list = newList;
        size = sz;
    }
};

/// read() 用于验证 重载的指针转换运算符
void read( double *p, int n ) {
    for ( int i = 0; i < n; i++ )
        cin >> p[i];
}

int main() {
    int n;
    cin >> n;
    
    Array<double> da(n);    /// 创建一个 double类型元素 的 对象da
    read( da, n );
    
    /// 输出 Array类的 对象da 全部元素
    for ( int i = 0; i < da.getSize(); i++ )
        cout << da[i] << ' ';
    cout << endl;
    
    Array<int> prime(5);    /// 创建一个 int类型元素 的 对象prime
    /// 求 [2, n] 的全部素数，存放到 prime 中

    int cnt = 0; /// 统计当前找到的素数的个数
    cin >> n;  /// 读入范围

    for ( int i = 2; i <= n; i ++ ) {   /// 检查 i 是否能被比它小的素数整除
        bool isPrime = true;
        for ( int j = 0; j < cnt; j ++ )
            /// 若 i 被 prime[j] 整除，说明 i 不是质数
            if ( i % prime[j] == 0 ) {
                isPrime = false;
                break;
            }

        if ( isPrime ) {
            if ( cnt == prime.getSize() )   /// 当装满了
                prime.resize( cnt * 2 );    /// 空间扩大一倍
            prime[ cnt ++ ] = i;
        }
    }
    
    for ( int i = 0; i < cnt; i ++ )
        cout << setw(8) << prime[i];
    cout << endl;
    
    return 0;
}
