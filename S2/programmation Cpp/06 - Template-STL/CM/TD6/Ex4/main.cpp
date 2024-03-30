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
 * @ Modified time: 29-03-2024
 */

#include <list>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

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

    return 0;
}
