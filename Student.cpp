#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
    string name;
    string number;
    char X;
    int year;
    Student(void);
    Student(string,string,char,int);      //构造函数声明
    void xianshi(void);     //用于输出类成员的值
};

Student::Student(void)
{
    cout << "对象创建了";
}
//成员函数定义，包括构造函数
Student::Student(string N,string n,char x,int y)    //利用构造函数给类的成员赋值
{
    name = N;
    number = n;
    X = x;
    year = y;
}

void Student::xianshi()     //输出成员的值
{
    cout<<name<<endl;
    cout<<number<<endl;
    cout<<X<<endl;
    cout<<year<<endl;
}

int main()                             //主函数
{
    cout<<"输入姓名：";
    string N;
    cin>>N;
    cout<<"输入学号：";
    string n;
    cin>>n;
    cout<<"输入性别（M 或 W）:";
    char x;
    cin>>x;
    cout<<"输入年龄：";
    int y;
    cin>>y;
    Student S(N,n,x,y);               //定义对象并对构造函数赋值
    S.xianshi();                           //引用输出函数
    return 0;
}