// 一个教学系统至少有 学生 和 教师 两种类型的人员，
//     假设 教师 的数据有 教师编号、姓名、年龄、性别、职称和系别，
//     学生的数据有 学号、姓名、年龄、性别、班级和语文、数学、英语三门课程的成绩。
// 现编程完成学生和教师档案数据的输入和显示。要求如下：
// 设计三个类 Person、Teacher、Student，Person 是 Teacher 和 Student 的基类，具有此二类共有的数据成员姓名、年龄、性别，并具有输入和显示这些数据的成员函数；
// Teacher 类继承了 Person 类的功能，并增加对教师编号、职称和系别等数据成员进行输入和显示的成员函数。Student 类按同样的方法设计。
// 根据题意完成下面的程序：


#include <iostream>
#include <string>
using namespace std;

class Person{
private:
   string name;
   int age;
   string sex;

public:
   Person( string = "", int = 0, string = "" );

   void inputname( ) {
       cin >> name;
   }

   void printname( ) {
       cout << name << endl;
   }

   void inputage( ) {
       cin >> age;
   }

   void printage( ) {
       cout << age << endl;
   }

   void inputsex( ) {
       cin >> sex;
   }

   void printsex( ) {
       cout << sex << endl;
   }

};

Person::Person( string Name, int Age, string Sex ) {
   name = Name;
   age  = Age;
   sex  = Sex;
}

// 继续您的代码：

class Teacher : public Person {
private:
    string id;
    string title;
    string department;

public:
    Teacher(
        string Name = "", 
        int Age = 0, 
        string Sex = "", 
        string Id = "", 
        string Title = "", 
        string Department = "") 
    :   Person(Name, Age, Sex), 
        id(Id), 
        title(Title), 
        department(Department) 
    {}

    void inputid() {
        cin >> id;
    }

    void printid() {
        cout << id << endl;
    }

    void inputtitle() {
        cin >> title;
    }

    void printtitle() {
        cout << title << endl;
    }

    void inputdepartment() {
        cin >> department;
    }

    void printdepartment() {
        cout << department << endl;
    }
};

class Student : public Person {
private:
    string studentNumber;
    string classNumber;
    int chinese;
    int math;
    int english;

public:
    Student(
        string Name = "", 
        int Age = 0, 
        string Sex = "", 
        string StudentNumber = "", 
        string ClassNumber = "", 
        int Chinese = 0, 
        int Math = 0, 
        int English = 0) 
    :   Person(Name, Age, Sex), 
        studentNumber(StudentNumber), 
        classNumber(ClassNumber), 
        chinese(Chinese), 
        math(Math), 
        english(English) 
    {}

    void inputStudentNumber() {
        cin >> studentNumber;
    }

    void printStudentNumber() {
        cout << studentNumber << endl;
    }

    void inputClassNumber() {
        cin >> classNumber;
    }

    void printClassNumber() {
        cout << classNumber << endl;
    }

    void inputChinese() {
        cin >> chinese;
    }

    void printChinese() {
        cout << chinese << endl;
    }

    void inputMath() {
        cin >> math;
    }

    void printMath() {
        cout << math << endl;
    }

    void inputEnglish() {
        cin >> english;
    }

    void printEnglish() {
        cout << english << endl;
    }
};


int main( ) {
   Teacher t1, t2( "张明", 33, "男", "T001", "讲师",   "计算机科学与软件学院" );
   Student s1, s2( "陈晓梅", 19, "女", "S001", "0309201", 90, 92, 98 );

   t1.inputname();
   t1.inputage();

   s1.inputChinese();
   s1.inputname();

   t1.printname();
   t1.printage();

   s1.printname();
   s1.printage();

   t2.printname();
   t2.printage();

   s2.printname();
   s2.printage();

   return 0;
}
