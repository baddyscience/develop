// 定义哺乳动物类 Mammal，有 age（int）和 weight（double）两个数据成员，
// 再由此派生出狗类 Dog，有 color（string）。
//创建一个 Dog 类的对象

// 请补充完成以下代码：
#include <iostream>
#include <string>
using namespace std;

class Mammal {
protected:
    int age;
    double weight;

public:
    Mammal(): age(0), weight(0.0) {
        cout << "Constructor in Mammal." << endl;
    }

    ~Mammal() {
        cout << "Destructor in Mammal." << endl;
    }

    void setAge(int a) {
        age = a;
    }

    int getAge() const {
        return age;
    }

    void setWeight(double w) {
        weight = w;
    }

    double getWeight() const {
        return weight;
    }
};

class Dog : public Mammal {
private:
    string color;

public:
    Dog() {
        cout << "Constructor in Dog." << endl;
    }

    ~Dog() {
        cout << "Destructor in Dog." << endl;
    }

    void setColor(string c) {
        color = c;
    }

    string getColor() const {
        return color;
    }

    void speak() const {
        cout << "Dog sound wang,wang,wang!" << endl;
    }
};

int main() {
   Dog d;
   
   d.setAge( 4 );
   d.setWeight( 12 );
   d.setColor( "Black" );
   
   cout << d.getAge() << endl;
   cout << d.getWeight() << endl;
   cout << d.getColor() << endl;
   
   d.speak();
   
   return 0;
}
