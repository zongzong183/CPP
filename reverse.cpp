#include<iostream>
#include<string>
/**
 * 任意数组A[0,n),将其前后的颠倒 //更一般的子区间A[lo,hi]'
 * 减而治之
 */
using namespace std;

void reverse(int *,int,int);

int main()
{
    int array[] {45,78,98,65,18};
    reverse(array,0,4);
    for(int i = 0;i < 5;i++)
    {
        cout << *(array + i) <<endl;
    }
    system("pause");
    return 0; 
}

/**
 *  问题规模的奇偶性不变，需要两个递归基
 *  实际上是一个双向指针的思路
 **/

void reverse(int * A,int lo,int hi)
{
    if(lo < hi) 
    {
        swap(A[lo],A[hi]);
        reverse(A,lo + 1,hi - 1);
    }
    else return;  //base case
}

/**
 * 迭代版
 */
void resverse1(int * A,int lo,int hi)
{
    next:
        swap(A[lo],A[hi]);
        lo++;
        hi--;
        goto next;
}

/**
 * 迭代精简版
 */
void reverse2(int * A,int lo,int hi)
{
    while(lo < hi)
    {
        swap(A[lo++],A[hi--]);
    }
}
