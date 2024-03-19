/**
 * @ name: Fraction.hpp
 * @ access: public
 * @ Author: Richter Gustave
 * @ Create Time: 19-03-2024 12:10:49
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


#ifndef __FRACTION_HPP__
#define __FRACTION_HPP__
#include <iostream>
using namespace std;


class Fraction
{
private:
    int numerateur = 0;
    int denominateur = 1;
public:
    Fraction();
    Fraction(int n);
    Fraction(int n, int d);

    ~Fraction();

    void setNum(int n);
    int getNum();
    void setDeno(int n);
    int getDeno();

    friend ostream& operator << (ostream& out, const Fraction& f);
    friend istream& operator >>(istream& in, Fraction& f);  

};

Fraction::Fraction()
{
    numerateur=0;
    denominateur=1;
}

Fraction::Fraction(int n)
{
    numerateur=n;
    denominateur=1;
}

Fraction::Fraction(int n, int d)
{
    numerateur=n;
    denominateur=d;
}

Fraction::~Fraction()
{
    cout << "destroying Fraction : " <<this->numerateur<< "/" << this->denominateur<< endl;
}


void Fraction::setNum(int n) {
    numerateur = n;
}


int Fraction::getNum(){
    return denominateur;
}

void Fraction::setDeno(int d){
    denominateur = d;
}

int Fraction::getDeno(){
    return denominateur;
}

ostream& operator <<(ostream& out, const Fraction& f){
    out <<f.numerateur<<"/"<< f.denominateur<< endl;
    return out;
}

istream& operator >>(istream& in, Fraction & f){
    char c;
    if ( !(in >>f.numerateur>> c >> f.denominateur) || (c!='/'))
    {
        in.setstate(ios::failbit);
    }
    return in;
}

#endif