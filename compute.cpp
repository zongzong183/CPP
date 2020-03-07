#include<iostream>

using namespace std;

int compute(int a,int b,int (*func)(int,int))
{
    return func(a,b);
}

int max(int a,int b)
{
    return a > b ? a : b;
}

int min(int a,int b) {
    return a < b ? a : b;
}

int sum(int a,int b)
{
    return a + b;
}

int main()
{
    cout<<"";
    int a,b,res;
    cout <<"请输入整数a:"; 
    cin >> a;
    cout <<"请输入整数b:"; 
    cin >> b;

    res = compute(a,b,&max);
    system("pause");
    
    
}