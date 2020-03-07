#ifndef _POINT_H    

#define _POINT_H

class Point {
    //Definition of base class Point class
    public:
        //public fucntion members
        void initPoint(float x = 0, float y = 0) {
            this -> x = x;
            this -> y = y;
        }
        void move(float offx, float offy) {
            x += offx;
            y += offy;
        }
        float getX() const{ return x; }
        float getY() const{ return y; }
    private:
        //private Data members
        int x,y;
};

#endif _POINT_H   
