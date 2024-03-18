#ifndef __GUIRLANDE_HPP__
#define __GUIRLANDE_HPP__

#include "Light.hpp"
#include "Electrique.hpp"
#include <vector>
using namespace std;


class Guirlande :public Electrique
{
private:
    vector<Light> lights;
public:
    Guirlande(vector<Light> lights);

    float puissance() const override;

    void afficher() const;
    void toggle();
    void alternate();
    void eteindre();
    ~Guirlande(){}
};

Guirlande::Guirlande(vector<Light> lights):Electrique(200,0){
    this->lights = lights;
    for (Light &light : lights)
    {
        intensite += light.getIntensite();
    }
}

void Guirlande :: toggle(){
    for (Light &light :lights){
        light.toggle();
    }
}
/*
void Guirlande :: eteindre(){
    for (Light &light :lights){
        light.toggle(false);
    }
}
*/
void Guirlande :: alternate(){
    for (Light &light :lights){
        light.toggle();
    }
}

void Guirlande ::afficher()const{
    for (const Light &light : lights)
    {
        light.afficher();
    }
    cout <<endl;
    
}


float Guirlande :: puissance() const {
    float puissanceTotale = 0;
    for (const Light &light : lights){
        puissanceTotale += light.puissance();
    }
    return puissanceTotale;
}


#endif // GUIRLANDE_HPP