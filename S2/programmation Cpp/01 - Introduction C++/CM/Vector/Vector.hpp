/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 18-03-2024 23:25:25
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 19-03-2024
 */

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <iostream>
using namespace std;

class Vector
{
private:
    double * elements;
    unsigned int sz;
public:
    Vector(unsigned int s);
    unsigned int size() const;
    double &operator[](unsigned int i);
    ~Vector();
};

Vector::Vector(unsigned int s)
{
    sz = s;
    elements = new double[s];
    for (int i = 0; i < sz; i++)
    {
        elements[i] = 0;
    }
    
}

unsigned int Vector::size() const {
    return sz;
}

double& Vector::operator[](unsigned int i ){
    if (i>=sz || i<0)
    {
        cerr<<"Array index out of bounds"<<endl;
        exit(-1);
    }
    
    return elements[i];
}

Vector::~Vector()
{
}

#endif