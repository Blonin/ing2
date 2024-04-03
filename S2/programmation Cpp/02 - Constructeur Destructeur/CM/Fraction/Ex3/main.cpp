/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 03-04-2024 11:53:46
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

using namespace std;
#include <iostream>
#include "Fraction.hpp"

int main(int argc, char const *argv[])
{
    cout << "nombre de fractions a créer?"<< endl;
    int n;
    cin >> n;
    
    //Création d'un tableau de fractions
    Fraction *tf = new Fraction[n];
    //attribution des valeurs
    for (int i = 0; i < n; i++)
    {
        tf[i]=Fraction(i,i+1);
        cout <<tf[i];
    }
    delete tf;
    
    Fraction **ppf=new Fraction *[n];
    for (int i = 0; i < n; i++)
    {
        ppf[i] = new Fraction(i,i+1);
        cout << *ppf[i];    
    }


    //on supprime chaque pointeur de fraction
    for (int i = 0; i < n; i++)
    {
        delete ppf[i];
    }
    //puis on surpprime le tableau
    delete [] ppf;
    
    return 0;
}
