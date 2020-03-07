#include<iostream>
#include <map>

using namespace std;

int getClimbWays(int n);
int getClimbWays(int n,map<int,int> map);

/**
 * this is recursion way
 * @author Norway183
 */
int getClimbWays(int n)
{
    if(n < 1) {
        return -1;
    }
    if(n == 1) {
        return 1;
    }
    if(n == 2) {
        return 2;
    }
    return getClimbWays(n -1) + getClimbWays(n - 2);
}

/**
 * use memo C++
 * this way needed refrenece STL library like map 
 * map is the Key-Value library collection
 * @author Norway183
 */

int getClimbWays(int n,map<int,int> map)
{
    if(n < 1) {
        return -1;
    }
    if(n == 1) {
        return 1;
    }
    if(n == 2) {
        return 2;
    }
}


/**
 * 
 */
int getClimbWays(int n)
{
    if(n < 1) {
        return -1;
    }
    if(n == 1) {
        return 1;
    }
    if(n == 2) {
        return 2;
    }
    int a = 1;
    int b = 2;
    int temp = 0;

    for(int i = 3;i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return temp;
}   