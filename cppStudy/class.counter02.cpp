// 重载单目运算符：前后自增自减
// 设计屏幕上的点 Point类，实现：
// 1、私有数据成员：x坐标值，y坐标值，均取非负值，x不超过4096，y不超过2160
// 2、默认构造函数
// 3、两个整形参数的构造函数
// 4、前、后自增运算符，重载为成员函数
// 5、前、后自减运算符，重载为友元函数
// 6、流插入运算符
// 请补充完成以下程序：

#include <iostream>
using namespace std;

class Point {
		int x;
		int y;

	public:
		Point(int a, int b) : x(a), y(b) {}

		Point() : x(0), y(0) {}

		~Point() {}

		Point &operator++() {
			x++;
			y++;
			x %= 4090;
			y %= 2160;
			return *this;
		}

		Point operator++(int) {
			Point temp = *this;
			++*this;
			return temp;
		}

		friend Point &operator--(Point& point) {
            point.x--;
            point.y--;
            if (point.x == -1)
                point.x %= 4090;
            if (point.y == -1)
                point.y %= 2160;
            return point;
		}

		friend Point operator--(Point& point, int) {
			Point temp = point;
            --point;
            return temp;
		}

		friend ostream &operator<<(ostream &os, const Point &cnt) {
			os << " (" << cnt.x << "," << cnt.y << ")";
			return os;
		}

};



int main() {
	Point p1(10, 10), p2(150, 150), p3(20, 20), p4(160, 160), p5;

	cout << "p1 = " << p1 << endl;

	/// 测试前置自增
	++p1;
	cout << "++p1 = " << p1 << endl;

	cout << "p3 = " << p3 << endl;
	/// 测试后置自增
	p5 = p3++;
	cout << "p5 = p3++ ,  p3 : " << p3 << "   p5 : " << p5 << endl;

	cout << "p2 = " << p2 << endl;

	/// 测试前置自减
	--p2;
	cout << "--p2 = " << p2 << endl;

	cout << "p4 = " << p4 << endl;
	/// 测试后置自增
	p5 = p4--;
	cout << "p5 = p4-- ,  p4 : " << p4 << "   p5 : " << p5 << endl;

	return 0;
}
