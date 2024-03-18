/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 17-03-2024
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 18-03-2024
 */

#ifndef __ELECTRIQUE_HPP__
#define __ELECTRIQUE_HPP__

using namespace std;
#include <iostream>

class Electrique
{
protected:
    float tension, intensite;
public:
    Electrique(float tension =220, float intensite = 0);
    virtual float puissance() const =0;
    void afficher() const;

    ~Electrique(){}
};

Electrique::Electrique(float tension, float intensite){
    this->intensite=intensite;
    this->tension=tension;
}

void Electrique::afficher() const {
    cout << "Tension : " << tension << "V" << endl;
    cout << "Intensite : " << intensite << "A" << endl;
}


#endif
