#include<iostream>
#include<stdlib.h>
using namespace std;

/*
    编写一个程序，使用类模板对数组元素进行排序，倒置、查找和求和
    具有对数组元素进行排序，倒置、查找和求和功能，
    然后产生类型实参分别为int型和double型的两个模板类，
    分别对整型数组与双精度数组完成所要求的操作
*/
template <typename T>
void Sort(T* a,int n)
{
    for(int i = 0;i < n - 1;i++) {
        for(int j = 0;j < n - i - 1; j++) {
            //this sort is ascending if array Previous element greater than The latter element
            if(a[j]> a[j + 1]) {
                T t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}


template<typename T>void Print(T* a,int n){
	int i;
	for(i=0;i<n;i++)
		cout<<a[i]<<".";
	cout << endl;
}

int main(){
	string Str[10]={"Zhang","Li","Wang","Qian","Zhao","Wu","Xu","Tang","Shen","Liang"};
	int Int[8]={20,12,0,-5,9,-18,6,11};
	double Dou[7]={3.07,8.12,-0.45,6,10,-9,7.29};
	Sort<string>(Str,10);
	Sort<int>(Int,8);
	Sort<double>(Dou,7);
	Print(Str,10);
	Print(Int,8);
	Print(Dou,7);
    system("pause");
	return 0;
}
