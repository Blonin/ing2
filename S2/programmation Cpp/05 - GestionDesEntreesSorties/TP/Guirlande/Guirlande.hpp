#ifndef __GUIRLANDE_HPP__
#define __GUIRLANDE_HPP__

#include "Light.hpp"
#include "Electrique.hpp"
#include <vector>
using namespace std;


class Guirlande :public Electrique
{
protected:
    int price;
private:
    vector<Light> lights;
public:
    Guirlande(vector<Light> lights);

    float puissance() const override;

    void afficher() const;
    void toggle();
    void allumer();
    void eteindre();
    ~Guirlande(){}
};

Guirlande::Guirlande(vector<Light> lights):Electrique(200,0){
    this->lights = lights;
    for (Light &light : lights)
    {
        intensite += light.getIntensite();
    }
    for (Light &light : lights)
    {
        if (light.getIntensite()==0.1)
        {
            this->price+=20;
        }else
        {
            this->price+=10;
        }
    }
}

//permet d'alterner les lumières eteint et allumer
void Guirlande :: toggle(){
    for (Light &light :lights){
        light.toggle();
    }
}

//allume toutes les lumière de la guirlande
void Guirlande ::allumer(){
    for (Light &light : lights)
    {
        light.toggle(true);
    }
}

// Eteint toutes les light de la guirlande
void Guirlande :: eteindre(){
    for (Light &light :lights){
        light.toggle(false);
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