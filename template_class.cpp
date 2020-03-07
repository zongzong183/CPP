#include<iostream>
#include<stdlib.h>
using namespace std;

/**
 *设计一个类模板，其中包括数据成员T a[n]以及在其中进行查找数据元素的函数int search(T)模板参数 T可实例化成字符串。
 */
template <typename T,int n> class A{
	int size;
	T* element;
	public:
	A();
	~A();
	int Search(T);
	void SetElement(int index,const T& value);
};

template <typename T, int n> A<T,n> :: A()
{
	size = n > 1 ? n : 1;
	element = new T[size];
}

template <typename T, int n> A<T,n> :: ~A()
{
	delete[] element;
}

template <typename T, int n> int A<T,n> :: Search(T t)
{
	for(int i = 0;i < size ;i++) {
		if(element[i] == t)
		{
			return i;
		}else {
			return -1;
		}
	}
}

template <typename T,int n> void A<T,n> :: SetElement(int index,const T& value)
{
	element[index] = value;
}

int main()
{
	A<int, 5> intAry;
	
	return 0;
}