#include<iostream>
#include<stack>
using namespace std;

bool paren(const char exp[], int lo, int hi) { //exp[lo,hi)
    stack<char> S; //create a stack datastructes use stack 

    for(int i = lo;i < hi; i++) {
        if ( '(' == exp[i] ) {
            S.push(exp[i]);
        } else if ( !S.empty() ) {
            S.pop();
        } else return false;
    }

    return S.empty();
}

bool parsen(const char exp[], int lo, int hi) {
    int  count = 0;

    for(int i = lo;i < hi; i++) {
        if('(' == exp[i]) {
            count++;
        } else if (')' == exp[i]) {
            count--;
        }
    }

    if(count == 0) {
        return true;
    } else {
        return false;
    }
   
}

int main()
{
    char str[] = {"()())"};
    bool b = paren(str,0,4);
    bool a = parsen(str,0,4);
    cout << b << endl;
    cout << a << endl;
    system("pause");
    return 0; 
}