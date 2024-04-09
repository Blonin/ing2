/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 29-03-2024 12:36:43
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 09-04-2024
 */

#include <list>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#include "Vector.hpp"

int main(int argc, char const *argv[])
{
    //Conteneur séquentiel list
    list <int> l;
    for (int i = 0; i < 5; i++)
    {
        l.push_back((10+2*i)%5+i);  // {0,3,6,4,7}
    }
    l.sort();
    l.reverse();
    cout << l.front() << " " << l.back() << endl;
    cout << "\n|---------------------|\n|---------MAP---------|\n|---------------------|"<<endl ;

    //Conteneur associatif map
    map <string,string> repertoire;
    repertoire ["Jean Martin"] = "01.02.03.04.05";
    repertoire ["Robert"] = "02.04.06.08.10";
    repertoire ["GUIGUI"] = "01.56.65.23.49";
    repertoire.insert(pair<string,string>("Louis Martin","04.05.06.07.08"));

    cout << "\n|---------------------|\n|------ITERATOR-------|\n|---------------------|"<<endl ;
    //STL Iterator
    int myints[] = {32,71,12,45,26,80,53,33};
    //
    vector<int> myvector (myints,myints+8);
    for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    {
        cout << ' ' << *it;
    }
    cout <<endl;

    cout << "\n|---------------------|\n|--------AUTO---------|\n|---------------------|"<<endl ;

    for (auto it = myvector.begin(); it!=myvector.end(); ++it)
    {
        cout << ' ' << *it;
    }
    cout <<endl;

    cout << "\n|---------------------|\n|--------ALGO---------|\n|---------------------|"<<endl ;

    vector <int> v;
    //compte le nombre d'occurences d'une valeur
    int n = count(v.begin(),v.end(),1);
    //mélange des valeurs
    random_shuffle(myvector.begin(),myvector.end());
    
    for (auto it = v.begin(); it!=v.end(); ++it)
    {
        cout << ' ' << *it;
    }
    cout <<endl;

    cout << "\n|---------------------|\n|--------FONC---------|\n|---------------------|"<<endl ;

    

    // Jeu de test pour Foncteur (fonction objet)
    int numbers[] = {54,63,15,65,89,55,1,8,155,23};
    sort(numbers,numbers+5,plusGrand<int>());
    
    cout << "\nFoncteur (Function Object):\n";
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Jeu de test pour lambda-expression & for-each
    Vector<int> v(6) = {10, 20, 40, 50, 10, 30};

    cout << "\nLambda-expression & for-each:\n";
    for_each(v.begin(), v.end(), [](int num) { 
        cout << num * 2 << " "; 
        });
    cout << endl;

    return 0;
}

template <typename T>
class plusGrand
{
private:
public:
    bool operator() (const T& x, const T& y) const{
        return x >y;
    }
    plusGrand();
    ~plusGrand();
};

template <typename T>
plusGrand<T>::plusGrand()
{
}

template <typename T>
plusGrand<T>::~plusGrand()
{
}
