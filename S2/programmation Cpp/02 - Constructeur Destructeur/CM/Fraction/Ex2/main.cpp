/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 03-04-2024 11:50:18
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
    //création d'un pointeur vers une fraction
    Fraction *pf;
    //attribution de valeurs
    pf = new Fraction(7,5);
    //affichage de la fraction
    cout <<*pf;
    //suppression de la fraction
    delete pf;

    return 0;
}


