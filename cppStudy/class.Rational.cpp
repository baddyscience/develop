// 运算符重载练习3：Rational
// 完成以下代码，实现 有理数 Rational 类 的 + 加法 和 - 减法

#include <cmath>
#include <iostream>
using namespace std;

/// 声明有理数类
class Rational {
public:
    /// 带默认参数的构造函数
    Rational ( int x = 0, int y = 1 ) : num(x), den(y) { }

    void Print( );

    Rational operator+ ( Rational &a );  /// 重载运算符"+"

    Rational operator- ( Rational &a );  /// 重载运算符"-"

private:
    int  num, /// 分子
         den; /// 分母
    void Optimi();  /// 分数化简
};

void Rational::Optimi() {
    if( num == 0 ) { /// 若分子为0，则置分母为1后返回
         den = 1;
         return;
    }

    /// 初值
    int gcd = (abs(num) > abs(den) ? abs(num) : abs(den));
    /// 若为0，则返回
    if( gcd == 0 )
          return;

    int i;
    /// 用循环找最大公约数
    for( i = gcd; i > 1;  i -- )
        if( ( num % i == 0 ) && ( den % i == 0 ) )
            break;

    /// i为最大公约数，将分子、分母均整除它，重新赋值
    num /= i;
    den /= i;
    /// 若分子和分母均为负数，则结果为正，所以均改为正
    if( num < 0 && den < 0 ) {
         num = -num;
         den = -den;
    }
    else if( num < 0 || den < 0 )  {
         /// 若分子和分母中只有一个为负数，则调整为分子取负，分母取正
         num =- abs(num);
         den = abs(den);
    }
}

/// 输出有理数
void Rational::Print( ) {
    cout << num;
    /// 当分子不为0且分母不为1时才显示"/分母"
    if( num != 0 && den != 1 )
        cout << "/" << den ;
}

//你写的代码在这里
Rational Rational::operator+ (Rational &a) {
    int newNum = num * a.den + den * a.num;
    int newDen = den * a.den;
    Rational result(newNum, newDen);
    result.Optimi();
    return result;
}

Rational Rational::operator- (Rational &a) {
    int newNum = num * a.den - den * a.num;
    int newDen = den * a.den;
    Rational result(newNum, newDen);
    result.Optimi();
    return result;
}

int main() {
    Rational r1(3, 14), r2(9, 15), r3, r4;
    r1.Print();
    cout << endl;

    r2.Print();
    cout << endl;

    r3 = r1 + r2; /// 使用重载了的运算符“+”
    r3.Print();
    cout << endl;

    r4 = r1 - r2; /// 使用重载了的运算符“-”
    r4.Print();
    cout << endl;

    return 0;
}
