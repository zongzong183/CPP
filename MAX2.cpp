#include<iostream>

using namespace std;

void max2(int A[],int lo,int hi,int & x1,int & x2);
void max2_recusion(int A[],int lo,int hi,int & x1,int & x2);
void max2_re(int A[],int lo,int hi,int & x,int & y);
void max2_vector(int A[],int lo,int hi,int & x1,int & x2);

int main()
{
    int x=0,y=0;
	int A[]={0,1,5,6,87,32,43,11,400};
	max2_vector(A,0,9,x,y);
	cout<<"max:"<<A[x]<<"min:"<<A[y];
    system("pause");
	return 0;
}
/**
 * 迭代
 */ 
void max2(int A[],int lo,int hi,int & x1,int & x2)
{   
    /**
     * 扫描的前两个元素的最大值和次大值
     */
    if(A[x1 = lo] < A[x2 = lo + 1]) {
        swap(x1,x2);
    }
    /**
     *
     */
    for(int i = lo + 2;i < hi; i++) {
        if(A[x2] < A[i]){
            if(A[x1] < A[x2 = i]) {
                swap(x1,x2);
            }else {
                continue;
            }
        }else {
            continue;
        }
    }
}
/**
 * 取自CSDN
 * 从中可以考虑到实现的方法
 */
void max2_recusion(int A[],int lo,int hi,int & x1,int & x2)
{
    if(lo+2 == hi){/*只有两个值*/A[lo]>A[hi-1]?x1=lo,x2=hi-1:x1=hi-1,x2=lo; return;}//T(2)=1
	if(lo+3 == hi){/*A中有三个值*/;
		x1=max(A[lo],max(A[lo+1],A[lo+2])); 
		x2=A[lo]+A[lo+1]+A[lo+2]-x1-min(A[lo],min(A[lo+1],A[lo+2]));//寻找最头二值 
		int i=lo;
		for(i=lo;i<hi;i++){
			if(A[i]==x1)
				x1=i;
			else if(A[i]==x2)
				x2=i;
		}
		return;}//T(3)<=3
	int mi=(lo+hi)/2;//divide 
	int x1L,x2L;max2(A,lo,mi,x1L,x2L);
	int x1R,x2R;max2(A,mi,hi,x1R,x2R); 
	if(A[x1L]>A[x1R]){
		x1=x1L;
		x2=(A[x2L]>A[x1R])?x2L:x1R;
	}else{
		x1=x1R;x2=(A[x1L]>A[x2R])?x1L:x2R;
	}//1+1=2
}
/**
 * 自己参考的手写代码
 */
void max2_re(int A[],int lo,int hi,int & x,int & y)
{
    /*这里面三个数*/
    if(lo + 2 == hi) {
        if(A[lo] >= A[hi - 1])  {
            x = A[lo];
            y = A[hi -1];
            return;
        }else {
            x = A[hi - 1];
            y = A[lo];
            return; 
        }
    }
    /*这里面有四个数字*/
    if(lo + 3 == hi) {
        x = max(A[lo], max(A[lo + 1], A[hi - 1]));
        x = A[lo] + A[lo + 1] + A[hi - 1] - x - min(A[lo], min(A[lo + 1], A[hi - 1]));
        return;
    }
    int mi = (lo + hi) >> 1;
    int xL,yL; max2_re(A,lo,mi,xL,yL);
    int xR,yR; max2_re(A,mi,hi,xR,yR);
    if(A[xL] > A[xR]) {
        x = xL;
        y = A[yL] > A[xR] ? yL : xR;
        return;
    } else {
        x = xR;
        y = A[yR] > A[xL] ? yR : xL;
        return;
    }
}
/**
 * 从数组中找出区间A[lo, hi]中找出最大的两个整数A[x1]和A[x2]  //A[x1] >= A[x2]
 */
void max2_vector(int A[],int lo,int hi,int & x1,int & x2)
{
    int i;
    for(x1 = lo, i = lo + 1;i < hi; i++)    //扫描A[lo,hi]找出A[x1]
        if(A[x1] < A[i]) x1 = i;    //hi -lo - 1 = n - 1;
    for(x2 = lo, i = lo + 1;i < x1; i++) 
        if(A[x2] < A[i]) x2 = i;
    for(i = x1 + 1;i < hi; i++) 
        if(A[x2] < A[i]) x2 = i; 
}