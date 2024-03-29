/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 27-03-2024 11:45:32
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 27-03-2024
 */

#include <iostream>
using namespace std;

template < typename T1, typename T2>
T2 calculerMoyenne(T1 tableau[],int taille){
    T2 somme = 0;
    for (int i = 0; i < taille; i++)
    {
        somme += tableau[i];
    }
    return somme/taille;
}

int main(int argc, char const *argv[])
{
    //ajout du var size pour simplifier la modification
    int size = 5;
    //création du tableau
    int tab[size];
    //
    for (int i = 0; i < size; i++)
    {
        tab[i]=i+1;
    }

    cout << "Moyenne : " << calculerMoyenne<int,double>(tab,size) << " pour la série : ";
    
    for (int i = 0; i < size; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
    return 0;
}
