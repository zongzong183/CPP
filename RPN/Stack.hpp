#pragma once

#include<iostream>
using namespace std;

template <typename T>
class Stack
{
    private:
        T * stk;      //初始化的大小
        int top;        //栈顶元素
        int MAX_N;      //最大容量
    public:
        Stack(int size);        //构造函数
        ~Stack();       //析构函数
        int push(T x);  //添加元素
        int pop(T *px);  //删除元素
        int getTop();
        int isEmpty() const;
        int isFull() const;
        int size() const;
        bool empty() const; //判空
};

template <typename T> 
Stack<T> :: Stack(int size)
{
    MAX_N = size;
    stk = new T[MAX_N];
    top = -1;
} 

template <typename T> 
Stack<T> :: ~Stack()
{
    delete stk;
}

template <typename T>
int Stack<T> :: push(T x) {
    if(top >= MAX_N - 1) return -1;
    stk[++top] = x;
    return 0;
}

template <typename T>
int Stack<T> :: pop(T *x) {
    if(top == -1) return 0;
    *x = stk[top--];
}

template <typename T>
int Stack<T> :: getTop() {
    if(top = -1) return NULL;
    return stk[top];
}

template <typename T>
int Stack<T>::isEmpty()const {
	return top == -1;
}

template <typename T>
int Stack<T>::isFull()const {
	return top == MAXN - 1;
}

template <typename T>
int Stack<T>::size() const{
	return top;
}

template <typename T>
bool Stack<T> :: empty() const 
{
    return _size <= 0; //判空
} 