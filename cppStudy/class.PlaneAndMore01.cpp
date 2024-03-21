// 设计一个飞机Plane类，由它派生出歼击机Fighter类和轰炸机Bomber类，歼击机Fighter类和轰炸机Bomber类又共同派生出歼轰机（多用途战斗机）Fighter_Bomber类。用虚函数和虚基类描述飞机类及其派生的类族。
// 约定：
// 1、Plane类有数据成员：wing（机翼长度），body（机身长度），tail（尾翼长度），voyage（航程），guest（旅客人数）；成员函数display，用于显示数据成员的值；
// 2、Fighter类（歼击机类）有新的数据成员missile（导弹数），重定义了display函数，新定义了fight函数（输出"Fight!"）；
// 3、Bomber类（轰炸机类）有新的数据成员bomb（载弹量），重定义display函数，新定义attack函数（输出"Attack!"）、getbomb函数。
// 4、Fighter_Bomber类（歼轰机类）, 重定义了display函数。
// 5、Plane类（飞机类）为虚基类。
// 6、display为虚函数。
// 补充完成以下代码：

#include <iostream>
using namespace std;

// 基类：飞机
class Plane {
private:
   float wing;    //机翼长度
   float body;    //机身长度
   float tail;    //尾翼长度
   float voyage;  //航程
   int guest;     //旅客人数
public:
   Plane( float w, float b, float t, float v, int n ) {
       wing = w;
       body = b;
       tail = t;
       voyage = v;
       guest = n;
   }

    virtual void display() const {
       cout << "Plane:wing:" << wing << " body:" << body << " tail:" << tail << " voyage:" << voyage << " guest:" << guest << endl;
   }
};

// 歼击机
class Fighter : virtual public Plane {
protected:
   int missile;
public:
   Fighter(float w, float b, float t, float v, int n, int m) : Plane(w, b, t, v, n), missile(m) {}

   void display() const override {
       cout << "This is a fighter!" << endl;
       Plane::display();
       cout << "missile:" << missile << endl;
   }

   void fight() const {
       cout << "Fight!" << endl;
   }
};

// 轰炸机
class Bomber : virtual public Plane {
protected:
   int bomb;
public:
   Bomber(float w, float b, float t, float v, int n, int bmb) : Plane(w, b, t, v, n), bomb(bmb) {}

   void display() const override {
       cout << "This is a bomber!" << endl;
       Plane::display();
       cout << "bomb:" << bomb << endl;
   }

   void attack() const {
       cout << "Attack!" << endl;
   }

   int getbomb() const {
       return bomb;
   }
};

// 歼轰机
class Fighter_Bomber : public Fighter, public Bomber {
public:
   Fighter_Bomber(float w, float b, float t, float v, int n, int m, int bmb) : Plane(w, b, t, v, n), Fighter(w, b, t, v, n, m), Bomber(w, b, t, v, n, bmb) {}

   void display() const override {
       cout << "This is a fighter_bomber!" << endl;
       cout << "This is a fighter!" << endl;
       Plane::display();
       cout << "missile:" << missile << endl;
       cout << "bomb:" << bomb << endl;
       fight();
       attack();
   }
};


int main() {
   Plane *p;

   Fighter f( 10.0, 6.0, 2.5, 1800, 1, 8 );  // 歼击机

   Bomber b( 30, 9, 6, 12000, 12, 6000 );  // 轰炸机

   Fighter_Bomber fb( 20, 7, 3.2, 4000, 2, 6, 2500 );  // 歼轰机

   p = &f;
   cout << "********p=&f" << endl;
   p->display();

   p = &b;
   cout << "\n********p=&b" << endl;
   p->display();

   p = &fb;
   cout << "\n********p=&fb" << endl;
   p->display();

   return 0;
}
