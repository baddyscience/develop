// 某公司有老板Boss、雇员Employee、小时工HourlyWorker和营销人员CommWorker，他们的薪金计算方法如下：
// 老板实行年薪制，如一年15万；雇员按月计酬，方法是基本工资+奖金；小时工按工作时间计算报酬，方法是工作小时每小时单价；营销人员按月计酬，方法是基本工资+销售利润5% 。
// 每类人员都有姓名、职工编号、年龄、性别、工资等数据。设计计算各类人员报酬的程序，用虚函数getPay()计算各类人员的应得报酬，用虚函数print()打印输出各位工作人员的基本数据。
// 约定：
// 1、将各类人员都有的共有的属性和行为抽象在类Person中，包括姓名、职工编号、年龄、性别等，以及函数getPay()和print()。
// 2、getPay()设计为纯虚函数，将print()设计成一般虚函数，其余类从Person类派生，各类再定义getPay()的实现方法，并重定义函数print()输出具体数据。
// 3、每个类还需要根据实际情况定义相应的成员函数，获取诸如工作时间、基本工资、销售利润之类的基础数据。
// 补充完成以下程序：
#include <iostream>
using namespace std;
 
class Person {
private:
   string name;  // 姓名
   string no;  // 职工编号
   int age;  // 年龄
   string sex;  // 性别
   float salary;  // 工资
 
public:
   Person( string s1, string s2, int Age, string Sex, float Salary=0 );
 
   virtual double getPay() = 0;
 
   virtual void print();
};
 
Person::Person( string s1, string s2, int Age, string Sex, float Salary ) {
   name   = s1;
   no     = s2;
   age    = Age;
   sex    = Sex;
   salary = Salary;
}
 
void Person::print() {
   cout << "姓名：" << name << endl << "职工编号：" << no <<  endl << "年龄：" << age << endl << "性别：" << sex << endl;
}
 
class Boss:virtual public Person{
public:
	Boss(string s1, string s2, int Age, string Sex) : Person(s1, s2, Age, Sex) {}
	
	double getPay() {
		return 15;
	}
	void print() {
		cout << "********************老板********************" << endl;
		Person::print();
		cout << "年薪：15万元" << endl;
	}
};
 
class Employee:virtual public Person{
	float wage,bonus;
public:
	Employee(string s1, string s2, int Age, string Sex) : Person(s1, s2, Age, Sex), wage(0), bonus(0) {}
	
	void setBWage(int w) {
		wage = w;
	}
	void setBonus(int b) {
		bonus = b;
	}
	
	double getPay() {
		return wage + bonus;
	} 
	void print() {
		cout << "********************雇员********************" << endl;
		Person::print();
		cout << "基本工资：" << wage << endl;
		cout << "奖金：" << bonus << endl;
		cout << "月薪：" << getPay() << "元" << endl;
	}
};
 
class HourlyWorker:virtual public Person{
	float wage,bonus;
	
public:
	HourlyWorker(string s1, string s2, int Age, string Sex) : Person(s1, s2, Age, Sex), wage(0), bonus(0) {}
	
	void settime_Hours(int h) {
		wage = h;
	}
	
	void setUHPrice(int n) {
		bonus = n;
	}
	
	double getPay() {
		return wage*bonus;
	} 
	
	void print() {
		cout << "********************小时工********************" << endl;
		Person::print();
		cout << "每小时单价：" << bonus << "元" << endl;
		cout << "工作时间：" << wage << "小时" << endl;		
		cout << "报酬：" << getPay() << "元" << endl;
	}
};
 
class CommWorker:virtual public Person{
	float wage, bonus;
	
public:
	CommWorker(string s1, string s2, int Age, string Sex) : Person(s1, s2, Age, Sex), wage(0), bonus(0) {}
	
	void setBWage(int w){
		wage = w;
	}
	void setinterest(int n){
		bonus = n;
	}

	double getPay(){
		return wage + bonus * 0.05;
	} 
	void print(){
		cout << "********************营销人员********************" << endl;
		Person::print();
		cout << "基本工资："<< wage << "元" << endl;
		cout << "销售利润："<< bonus << "元" << endl;		
		cout << "月酬：" << getPay() << "元" << endl;
	}
};
 
int main(){
   Boss b( "张华", "N001", 30, "男" );
   b.print();
 
 
   Employee e( "李明", "N002", 40, "男" );
   e.setBWage( 900 );   
   e.setBonus( 1000 );
   e.print();
 
 
   HourlyWorker hw( "向力", "N003", 38, "男" );
   hw.settime_Hours( 30 );
   hw.setUHPrice( 60 );
   hw.print();
 
 
   CommWorker cw( "刘晓云", "N004", 28, "女" );
   cw.setBWage( 1600 );
   cw.setinterest( 10000 );
   cw.print();
 
   return 0;
}