/**
 * @ name: Fraction.cpp
 * @ access: public
 * @ Author: Richter Gustave
 * @ Create Time: 09-02-2024
 * @ email: richtergustave@gmail.com
 * @ description: Utilisation de la classe Fraction
 * 
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return:    EXIT_SUCCESS Exection OK
 *              EXIT_FAILURE Execution KO
 * 
 * @ copyright: Richter Gustave
 * 
 * @ Modified by: 
 * @ Modified time: 
 */

using namespace std;

#include <iostream>
#include "Fraction.hpp"



//Fraction
int main(int argc, char const *argv[])
{
    // Exercice 1

    Fraction f1;
    Fraction f2(10);
    Fraction f3(3,7);
    Fraction f(5,6);

    cout<<f<<endl;

    // Exercice 2
    Fraction *pf;
    pf = new Fraction(7,5);
    cout <<*pf;
    delete pf;

    // Exercice 3.1
    cout <<"Nombre de fractions a crer ?" <<endl;
    int n;
    cin >>n;

    Fraction *tf= new Fraction [n];
    for (int i = 0; i < n; ++i)
    {
        tf[i] =Fraction(i,i+1);
        cout << tf[i]; 
    }
    delete[] tf;
    //les fractiion dans le tableau tf sont détruites avant la
    // désallocation de tf

    // Exercice 3.2
    cout <<"Nombre de fractions a creer ?" <<endl;
    int m;
    cin >>m;
    Fraction **ppf= new Fraction*[n];
    for (int i = 0; i < m; ++i)
    {
        ppf[i] = new Fraction(i,i+1);
    }

    for (int i = 0; i < m; ++i)
    {
        cout<<*ppf[i];
    }
    for (int i = 0; i < m; ++i)
    {
        delete ppf[i];
    }
    
    

    return EXIT_SUCCESS;
}

