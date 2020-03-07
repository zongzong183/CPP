#include <iostream>
#include <cmath>

using namespace std;

#include "Rectangle.hpp"

int main()
{
    Rectangle rect;

    rect.initRectangle(2, 3, 20, 10);
    cout << "The Data of rect(x,y,w,h)" << endl;
    cout << rect.getX() << ", "
         << rect.getY() << ", "
         << rect.getW() << ", "
         << rect.getH() << endl;
    return 0;
}