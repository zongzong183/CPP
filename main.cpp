#include<iostream>
using namespace std;
int main()
{
    int arrays[] {15,25,78,45,89};
    int * ptr_array_start = arrays;
    int * ptr_array_end = arrays + 4;
    
    while(*ptr_array_start != *ptr_array_end)
    {
        int temp = *ptr_array_start;
        *ptr_array_start = *ptr_array_end;
        *ptr_array_end = temp;
        ptr_array_start--;
        ptr_array_end++;
    }

    for(int i = 0;i < 5; i++) {
        cout << *(arrays + i)<< endl;
    }
    system("pause");
    return 0;
}