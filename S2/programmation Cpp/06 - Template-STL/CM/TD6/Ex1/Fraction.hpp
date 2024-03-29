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
 * @ Modified time: 27-03-2024
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
    double getVal();

    friend bool operator <(Fraction f1, Fraction f2);
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

//

/// @brief Renvoie la valeur de la division de la fraction
/// @return un double
double Fraction::getVal(){
    return (numerateur/denominateur);
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

/// @brief fonction amie de l'opérateur < vrai si f1 est plus petit que f2
/// @param f1 fraction
/// @param f2 fraction
/// @return TRUE/FALSE
bool operator <(Fraction f1, Fraction f2){
    //
    if (f1.getVal() < f2.getVal())
    {
        return true;
    }else{
        return false;
    }
    
    
}


#endif