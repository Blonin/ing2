/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 19-03-2024 13:12:26
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 19-03-2024
 */

#include <iostream>
using namespace std;
#include <fstream>

#include "Fraction.hpp"

int main(int argc, char const *argv[])
{
    
    Fraction f1(4,5);
    Fraction f2(3,11);
    
    Fraction f;
    cout <<"Entrez une fraction :" <<endl;
    cin >> f;
    cout << f << endl;

    //2
    //on ouvre le fichier txt
    ofstream ofs("Fraction.txt",ios::out);
    //on écris la fraction f1 dedans puis la fraction f2
    ofs << f1;
    ofs << f2;
    //on oublie pas de refermer le flux d'écriture
    ofs.close();

    //3
    //ouverture du flux de lecture du fichier txt
    ifstream ifs("Fraction.txt");
    //verification s'il est ouvert
    if (ifs)
    {
        //création de la fraction
        Fraction f;
        //tant que l'on est pas a la fin du fichier on continuer cette boucle
        while (!ifs.eof())
        {
            //on enregistre ce qu'il y a dans le flux dans la fraction f
            ifs >> f;
            //s'il n'y a pas d'erreur on affiche la fraction f
            if (!ifs.fail())
            {
                cout<<f;
            }
        
        }
        //on oublie pas de refermer le flux de lecture
        ifs.close();
    //erreur lors de l'ouverture du flux 
    }else{
        cerr <<"Impossible d'ouvrir le fichier" << endl;
    }

    //4
    //gestion des exceptions du type 5/0 ce qui est impossible
    /*throw 0;
    throw string("Erreur de calcul");
    throw MonException();*/
    #include <exception>
    try
    {
        Fraction f3(5,0);
        
    }
    catch(int code)
    {
        cerr << "Exception" << code << endl;
    }catch(exception& e){
        cout<<e.what()<<endl;
    }/*catch(){
        cout << "Attrape toutes les exceptions";
    }*/
    
    

    return 0;
}

class MonException
{
    virtual const char* what() const throw(){
        return "oups ! Mon Exception";
    }
};

