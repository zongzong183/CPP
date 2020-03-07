#include<iostream>
#include<cmath>
#include<stdlib.h>

using namespace std;
class Point
{
    public: //外部接口
        Point(int x = 0, int y = 0) : x(x),y(y){}
        int getY() { return y; }
        int getX() { return x; }
        friend float dist(Point& a,Point& b);
    private:
        int x,y;
};

float dist(Point& a,Point& b) 
{
    double x = a.x - b.x;
    double y = a.y - b.y;
    return static_cast<float>(sqrt(x * x + y * y));
}

int main()
{
    Point p1(1,1),p2(4,5);
    cout << "The distance is:";
    cout << dist(p1,p2) << endl;
    system("pause");
}