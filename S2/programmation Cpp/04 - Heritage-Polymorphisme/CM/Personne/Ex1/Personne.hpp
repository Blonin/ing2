/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 05-03-2024
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 06-03-2024
 */


#ifndef __PERSONNE_HPP__
#define __PERSONNE_HPP__

#include <string>
using namespace std;

class Personne
{
private:
    string nom;
    string prenom;
public:
    
    //Constructeur
    Personne(const string& nom,const string& prenom) {
        this->nom = nom;
        this->prenom =prenom;
    }

    //getter & setter
    string getNom()const {return this->nom;}
    void setNom(string nom){ this->nom = nom;}

    string getPrenom()const {return this->prenom;}
    void setPrenom(string prenom){ this->prenom = prenom;}


    //afficher
    void afficher () const {cout << nom << prenom << endl;}

    //destructeur
    ~Personne() {};
};


class Etudiant : public Personne
{
private:
    string id;
public:
    //getter & setter
    string getId() const {return id;}
    void setId(const string& id){}

    //affichage
    void afficher() const {
        Personne::afficher();
        cout<< id << endl;
    }
    
    //constructeur
    Etudiant(const string& nom, const string& prenom) :
        Personne(nom,prenom),
        id(NULL){}
    Etudiant(const string& id, const string& nom, const string& prenom) :
        Personne(nom,prenom),
        id(id){}
    
    //destructeur
    ~Etudiant(){};
};


#endif
