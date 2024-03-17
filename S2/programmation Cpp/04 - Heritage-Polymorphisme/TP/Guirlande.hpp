#ifndef GUIRLANDE_HPP
#define GUIRLANDE_HPP

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
    void allumer();
    void eteindre();
    ~Guirlande()
    {
        cout << "Deleting Guirland" << endl;
    };
};

Guirlande::Guirlande(vector<Light> lights):Electrique(200,0){
    this->lights = lights;
    for (Light &light : lights)
    {
        intensite += light.getIntensite();
    }
}

void Guirlande :: allumer(){
    for (Light &light :lights){
        light.setIntensite(0.1);
    }
}

void Guirlande :: eteindre(){
    for (Light &light :lights){
        light.setIntensite(0);
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