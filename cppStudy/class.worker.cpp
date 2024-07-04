// 设计工人类 Worker，它具有姓名 name，年龄 age，工作部门 Dept，工资 salary，等数据成员。
// 其中，salary 是 Salary 类的一个对象。
// 下面的程序拟完成 Worker 类的设计并用静态成员统计工人的人数，请把程序补充完整。
// 提示：这里成员函数 setXX() 用于设置各分项数据，成员函数 getXX() 用于获取各分项数据，XX 代表数据成员，如 age 对应的成员函数则为 setAge() 和 getAge() 。

#include <iostream>
#include <string>
using namespace std;

class Salary {
private:
    double Wage; // 基本工资
    double Subsidy; // 岗位工资
    double Rent; // 房租
    double WaterFee; // 水费
    double ElecFee; // 电费

public:
    // 初始化工资数据的各分项
    Salary(double i1 = 0, double i2 = 0, double i3 = 0, double i4 = 0, double i5 = 0) : Wage(i1), Subsidy(i2), Rent(i3), WaterFee(i4), ElecFee(i5) {}

    void setWage(double f) {
        Wage = f;
    }

    double getWage() {
        return Wage;
    }

    void setSubsidy(double f) {
        Subsidy = f;
    }

    double getSubsidy() {
        return Subsidy;
    }

    void setRent(double f) {
        Rent = f;
    }

    double getRent() {
        return Rent;
    }

    void setWaterFee(double f) {
        WaterFee = f;
    }

    double getWaterFee() {
        return WaterFee;
    }

    void setElecFee(double f) {
        ElecFee = f;
    }

    double getElecFee() {
        return ElecFee;
    }

    // 计算实发工资, 实发工资 = Wage + Subsidy - Rent - WaterFee - ElecFee
    double RealSalary() {
        return Wage + Subsidy - Rent - WaterFee - ElecFee;
    }
};

class Worker {
private:
    string name;
    int age;
    string Dept;
    Salary salary;
    static int numOfWorkers;

public:
    Worker(string name = "", int age = 0, string Dept = "") : name(name), age(age), Dept(Dept) {
        numOfWorkers++;
    }

    ~Worker() {
        numOfWorkers--;
    }

    void setName(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void setAge(int a) {
        age = a;
    }

    int getAge() {
        return age;
    }

    void setDept(string d) {
        Dept = d;
    }

    string getDept() {
        return Dept;
    }

    void setSalary(double Wage, double Subsidy, double Rent, double WaterFee, double ElecFee) {
        salary = Salary(Wage, Subsidy, Rent, WaterFee, ElecFee);
    }

    double getSalary() {
        return salary.RealSalary();
    }

    static int getNum() {
        return numOfWorkers;
    }
};

int Worker::numOfWorkers = 0;

int main() {
    Worker w1("John", 30, "design");
    cout << w1.getSalary() << endl;

    Worker w2;
    cout << "the total num is: " << Worker::getNum() << endl;
    w2.setName("Linda");
    cout << "in w2 the name is: " << w2.getName() << endl;

    // 基本工资  岗位工资  房租  水费  电费
    w2.setSalary(100000, 400, 300, 200, 100);
    cout << w2.getSalary() << endl;

    return 0;
}
