#include<iostream>
using namespace std;

int sum(int  A[],int lo,int hi);

int main()
{
    
}

int sum(int  A[],int lo,int hi)
{
    if(lo == hi) return A[lo];
    int mi = (lo + hi) >> 1;
    return sum(A,lo,mi) + sum(A,mi + 1,hi);
}
