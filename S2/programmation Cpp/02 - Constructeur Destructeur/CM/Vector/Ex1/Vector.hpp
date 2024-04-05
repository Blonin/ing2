/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 03-04-2024 12:08:40
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 03-04-2024
 */
#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

class Vector
{
private:
    double* elem; //elements du vecteur
    int sz; //size
public:
    //constructeur
    Vector(int s);
    Vector(const Vector&v );
    Vector& operator = (const Vector& v);

    //size getter
    int size();
    //elem getter
    double &operator[](unsigned int i);

    ~Vector();
};

Vector::Vector(int s) : elem {new double[s]}, sz{sz}
{   
}

Vector::Vector (const Vector&v ) :elem {new double[v.sz]},sz{v.sz}
{
    for (int i = 0; i < sz; i++)
    {
        elem[i] = v.elem[i];
    }
}

int Vector::size(){
    return sz;
}

double& Vector::operator[](unsigned int i ){
    if (i>=sz || i<0)
    {
        cerr<<"Array index out of bounds"<<endl;
        exit(-1);
    }
    
    return elem[i];
}


Vector::~Vector()
{
}


#endif