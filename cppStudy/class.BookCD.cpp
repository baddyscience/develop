// 设计管理出版物的类
// 某出版社发行图书和光盘，利用继承设计管理出版物的类。
// 要求如下：
// 给出一个基类Publication存储出版物的标题title、出版物名称name、单价price及出版日期date；
// 继承创建Book类和CD类分别管理图书和光盘，它们都从Publication类派生；
// Book类具有保存图书页数的数据成员page，CD类具有保存播放时间的数据成员playtime；
// 每个类都有构造函数、析构函数，且都有用于从标准输入获取数据的成员函数inputData()和用于显示数据的成员函数display()。
// 补充完成以下代码：

#include <iostream>
#include <string>
using namespace std;

// 年月日
struct Date {
   int year;
   int month;
   int day;

   Date( int y = 0, int m = 0, int d = 0 ) {
       year  = y;
       month = m;
       day   = d;
   }

   ~Date(){ }
};

// 时分秒
struct Time {
   int hour;
   int minute;
   int second;

   Time( int h = 0, int m = 0, int s = 0 ) {
       hour   = h;
       minute = m;
       second = s;
   }

   ~Time(){ }
};

// 基类：出版物
class Publication {
private:
   string title; // 出版物的标题
   string name; // 名称
   float price; // 单价
   Date date; // 出版日期

public:
   Publication( string t = "", string n = "", float p = 0, int h = 0, int m = 0, int s = 0 )
       :date( h, m, s ) {
       title = t;
       name  = n;
       price = p;
   }

   ~Publication(){ }

   void inputdata( ) {        
       cin >> title;        
       cin >> name;        
       cin >> price;        
       cin >> date.year >> date.month >> date.day;
   }

   void display() {
       cout << "*****display*****" << endl;
       cout << "title:" << title << endl;
       cout << "name:" << name << endl;
       cout << "price:" << price << endl;
       cout << "year-month-day:" << date.year << "-" << date.month << "-" << date.day << endl;
   }
};

class Book : public Publication {
private:
    int page;

public:
    Book(
        string t = "", 
        string n = "", 
        float p = 0, 
        int y = 0, 
        int m = 0, 
        int d = 0, 
        int pg = 0)
    :   Publication(t, n, p, y, m, d),
        page(pg)
    {}

    ~Book() {}
    
    void inputdata() {
        Publication::inputdata();
        cin >> page;
    }

    void display() {
        Publication::display();
        cout << "pages:" << page << endl;
    }
};

class CD : public Publication {
private:
    Time playtime;

public:
    CD(
        int h = 0, 
        int m = 0, 
        int s = 0, 
        string t = "", 
        string n = "", 
        float p = 0, 
        int y = 0, 
        int mo = 0, 
        int d = 0)
    :   Publication(t, n, p, y, mo, d), playtime(h, m, s) {}


    ~CD() {}

    void inputData() {
        Publication::inputdata();
        cin >> playtime.hour >> playtime.minute >> playtime.second;
    }

    void display() {
        Publication::display();
        cout << "playtime(h:m:s) " << playtime.hour << ":" << playtime.minute << ":" << playtime.second << endl;
    }
};

int main() {
   Book b;
   CD c( 1, 2, 3, "Noname", "肖邦钢琴协奏曲", 61, 2018, 8, 1 );
   b.inputdata();
   b.display();
   c.display();    
   return 0;
}
