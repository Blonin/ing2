#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__

#include "Electrique.hpp"

using namespace std;
#include <iostream>

class Light : public Electrique
{ 
  private:

  protected:
    bool on;
    
  public:  
    Light (float intensite,bool on);  // Makes a new light

    void toggle();
    void toggle(bool t);
    bool isOn() const;

    float puissance() const override;
    void afficher() const;
    float getIntensite() const;
    void setIntensite(float intensite);

    ~Light(){}

};

Light::Light(float intensite,bool on) : Electrique(220, intensite) {
    on = on;
} 

float Light::puissance() const {
    return tension * intensite;
}

void Light::afficher() const {
    if (isOn()==true)
    {
        if(intensite <0.1){
        cout << "o";
        } else {
            cout << "O";
        }
    }else
    {
        cout<<".";
    }
}

void Light::toggle() {
    on = !on;
}

void Light::toggle(bool t){
    on = t;
}


float Light::getIntensite() const {
    return intensite;
}

void Light::setIntensite(float intensite) {
    this->intensite = intensite;
}

bool Light::isOn() const{
    return on;
}

#endif
