/**
 * @ name: Fraction.cpp
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 13-02-2024
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 13-02-2024
 */

#include <iostream>
#include "Fraction.hpp"

//Constructeur
Fraction::Fraction():Fraction(0,1){}
Fraction::Fraction(int n){
    numerateur=n;
    denominateur=1;
}
Fraction::Fraction(int n,int d){
    numerateur=n;
    denominateur=d;
}

//Destructeur
Fraction::~Fraction(){}

std::ostream&operator << (std::ostream& out ,const Fraction&f){
    out << "Fraction : " <<f.numerateur<<"/"<<f.denominateur<<std::endl;
    return(out);
}

void Fraction::operator*=(const Fraction& autre){
  numerateur *= autre.numerateur;
  denominateur *= autre.denominateur;
}

//création de la fonction pour l'opérateur *
Fraction Fraction::operator*(const Fraction& autre) const{
    return Fraction(numerateur*autre.numerateur,
                    denominateur*autre.denominateur);
}

Fraction operator* (const Fraction& f1, const Fraction& f2){
    return Fraction(f1.getNum()*f2.getNum(),
                    f1.getDen()*f2.getDen());
}

//EXO 3 Réutilisation
void Fraction::operator*=(const Fraction& f){
    numerateur*= f.getNum();
    denominateur*= f.getDen();
}

Fraction& Fraction

int Fraction::getNum()const{
    return numerateur;
}

int Fraction::getDen()const{
    return denominateur;
}