// 类型转换：Rational
// 实现 有理数 Rational 类 与 int类型、double类型 的相互转换。
// 请补充完成以下代码：

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Rational {
public:
    /// 默认构造函数
    Rational();

    /// 构造函数
    Rational(int x, int y);

    explicit Rational(int x);  /// 转换构造函数

    friend ostream& operator << (ostream& ou, Rational& a );  /// 重载流插入运算符

    Rational operator + ( Rational b );  /// 重载 运算符+
    //friend Rational operator + ( Rational a, Rational b ); 友元函数方式，导致更多地方出现二义性

    operator int();  /// 类型转换函数，相当于 toInt()。 最好加上 explicit

    operator double();  /// 类型转换函数，相当于 toDouble()。 最好加上 explicit

private:
    int nume;  /// 分子
    int deno;  /// 分母
    void optimize();  /// 化简
    int gcd( int m, int n );  /// 求最大公约数
};

/// 类内部函数，求最大公约数
int Rational::gcd( int m, int n ){
    int r = 0;
    while( n ) {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}

/// 类内部函数，分数化简
void Rational::optimize() {
    int n = nume;
    if ( nume < 0 )  /// 负数时
        n = -nume;
    int r = gcd( n, deno );
    nume = nume / r;
    deno = deno / r;

    /// 若分子和分母均为负数，则结果为正，所以均改为正
    if( nume < 0 && deno < 0 ) {
        nume = -nume;
        deno = -deno;
    }
    /// 若分子和分母中只有一个为负数，则调整为分子取负，分母取正
    else if( nume < 0 || deno < 0 ) {
        nume = -abs(nume);
        deno = abs(deno);
   }
}

//你写的代码放在这里，包括 类成员函数、友元函数的实现

Rational::Rational() : nume(0), deno(1) {}

Rational::Rational(int x, int y) : nume(x), deno(y) {
    optimize(); 
}

Rational::Rational(int x) : nume(x), deno(1) {} 

ostream& operator<<(ostream& ou, Rational& a) {
    ou << a.nume << "/" << a.deno;
    return ou;
}

Rational Rational::operator+(Rational b) {
    Rational sum;
    sum.nume = this->nume * b.deno + this->deno * b.nume;
    sum.deno = this->deno * b.deno;
    sum.optimize();
    return sum;
}

Rational::operator int() {
    return nume / deno;
}

Rational::operator double() {
    return double(nume) / deno; 
}


int main() {
    Rational r1(3, 5), r2(9, 4), r3, r4;
    cout << "r1 : " << r1 << endl;
    cout << "r2 : " << r2 << endl;

    int n = 3;
    r3 = r2 + Rational(n);
    //r3 = r2 + n;  /// 禁止了隐式转换构造函数，所以不能使用
    cout << "r3 = r2 + 3 : " << r3 << endl;

    r4 = Rational(n) + r1;  /// 显式调用转换构造函数 Rational(n)
    cout << "r4 = Rational(n) + r1 : " << r4 << endl;

    int a = n + int(r2);  /// 显式调用类型转换函数 int(n)
    //int a = n + r2;  /// 已禁止了隐式调用类型转换函数 Rational(n)
    cout << "a = n + int(r2) : " << a << endl;
    a = Rational(n) + r2;  /// 显式调用转换构造函数 Rantional(n) 转换为 Rational对象 后，再与 r2 运算，然后把结果转成 int 类型，赋值给 a
    cout << "a = Rational(n) + r2 : " << a << endl;

    cout << fixed << setprecision(2);
    double b = 3.14 + double(r2);  /// 显式调用类型转换函数 double(n)
    cout << "b = 3.14 + double(r2) : " << b << endl;
    b = Rational(3.14) + r2;  /// 先显式调用转换构造函数 Rational(3.14) 转换为 Rational对象 后，与 r2 运算，然后把结果转成 int 类型，赋值给 b
    cout << "b = Rational(3.14) + r2 : " << b << endl;

    return 0;
}
