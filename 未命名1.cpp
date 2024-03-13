#include <iostream>
#include <string>
using namespace std;

class Salary {
private:
    double Wage; // ��������
    double Subsidy; // ��λ����
    double Rent; // ����
    double WaterFee; // ˮ��
    double ElecFee; // ���

public:
    // ��ʼ���������ݵĸ�����
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

    // ����ʵ������, ʵ������ = Wage + Subsidy - Rent - WaterFee - ElecFee
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

int Worker::numOfWorkers = 0; // ��ʼ����̬��Ա����

int main() {
    Worker w1("John", 30, "design");
    cout << w1.getSalary() << endl;

    Worker w2;
    cout << "the total num is: " << Worker::getNum() << endl;
    w2.setName("Linda");
    cout << "in w2 the name is: " << w2.getName() << endl;

    // ��������  ��λ����  ����  ˮ��  ���
    w2.setSalary(100000, 400, 300, 200, 100);
    cout << w2.getSalary() << endl;

    return 0;
}

