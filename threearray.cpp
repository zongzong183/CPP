#include<iostream>

using namespace std;

int main()
{
    /**
     * create a 3d array
     */
    int (*cp)[9][8] = new int[7][9][8];

    /**
     * for loop through 3d array print number in array
     */
    for(int i = 0;i < 7; i++) {
        for(int j = 0;j < 9 ; j++) {
            for(int k = 0;k < 8; k++) {
                *(*(*(cp + i) + j) + k) = (i * 100 + j * 10 + k);
            }
        }
    } 

    for(int i = 0;i < 7; i++) {
        for(int j = 0;j < 9; j++) {
            for(int k = 0;k < 8; k++) {
                cout << cp[i][j][k] << " " << endl;
            }
        }
        cout << endl;
    }
    delete[] cp;
    getchar();
    return 0;
}