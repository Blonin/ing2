#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__

#include "Electrique.hpp"

using namespace std;
#include <iostream>

class Light : public Electrique
{ 
  private:

  protected:

  public:  
    Light (float intensite = 0);  // Makes a new light

    float puissance() const override;
    void afficher() const;
    float getIntensite() const;
    void setIntensite(float intensite);

    ~Light(){
        cout << "deleting Light" << endl;
    };

};

Light::Light(float intensite) : Electrique(220, intensite) {}

float Light::puissance() const {
    return tension * intensite;
}

void Light::afficher() const {
    if (intensite == 0) {
        cout << ".";
    }else if(intensite <0.1){
        cout << "o";
    } else {
        cout << "O";
    }
}

float Light::getIntensite() const {
    return intensite;
}

void Light::setIntensite(float intensite) {
    this->intensite = intensite;
}


#endif
