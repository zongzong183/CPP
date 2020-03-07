#include<iostream>
#include<FIb.hpp>
#define Rank int

using namespace std;

int bin_search(int A[],int target,int lo,int hi);

int main()
{
    int nums[] = {18,85,48,45,64};
    int n = bin_search(nums,48,0,4);
    cout << n << endl;
    system("pause");
    return 0;
}

template <typename T>
static Rank binsearch(T* A,T const & e,Rank lo, Rank hi) 
{
    while(lo < hi) {
        Rank mi = (lo + hi) >> 1;
        if(e < A[mi]) hi = mi;
        else if(A[mi] < e) lo = mi;
        else return mi;
    }
    return -1;
}

int bin_search(int A[],int target,int lo,int hi)
{
    while(lo < hi) {
        int mi = (lo + hi) >> 1;
        if(target < A[mi]) bin_search(A,target,lo,mi );
        else if(A[mi] < mi) bin_search(A,target, mi,hi);
        else return mi;
    }
    return -1;
}

