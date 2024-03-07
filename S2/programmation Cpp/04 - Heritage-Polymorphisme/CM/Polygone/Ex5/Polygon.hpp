

#ifndef __POLYGON_HPP__
#define __POLYGON_HPP__

using namespace std;

#include <iostream>
#include <vector>

class Polygon
{
protected:
    int width, height;
public:
    Polygon(const int width, const int height){
        this->width=width;
        this->height=height;
    };

    int getWidth(){return width;}
    int getHeight(){return height;}
    void setWidth(const int width){this->width=width;}
    void setHeight(const int height){this->height=height;}

    virtual int getArea()const {return 0;}

    //destructeur
    ~Polygon(){
        cout << "deleting Polygon" << endl;
    }
};


class Rectangle : public Polygon
{
private:
    
public:
    Rectangle(const int width, const int height) : Polygon(width,height){};
    
    //override
    int getArea()const override{return width*height;}

    ~Rectangle() {
        cout << "deleting Rectangle" << endl;
    }
    
};


class Triangle : public Polygon
{
private:
    
public:
    Triangle(const int width, const int height) : Polygon(width,height){};

    int getArea()const override{return width*height/2;}

    ~Triangle() {
        cout << "deleting Triangle" << endl;
    }
};

#endif
