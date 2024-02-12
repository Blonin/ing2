/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 12-02-2024
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 12-02-2024
 */

using namespace std;

#include <iostream>
#include "Vector.hpp"

Vector::Vector(unsigned int s){
    sz=s;
    elements = new double[s];
    for (unsigned int i = 0; i < s; i++)
    {
        elements[i]=0;
    }
}

Vector::~Vector(){}

unsigned int Vector::size() const {
    return (sz);
}

double& Vector ::operator[](unsigned int i){
    if (i>=sz)
    {
        cerr<<"Array index out of bounds"<<endl;
        exit(-1);
    }
    return(elements[i]);
}

void bad_copy1(Vector v1) {
  // Constructeur par copie
  Vector v2 = v1;

  // v1[0] est aussi 2
  cout << "v1 [0] = " << v1[0] << endl;

  // v2[0] est aussi 2
  cout << "v2[0] = " << v2[0] << endl;

  v1[0] = 2; // v2[0] reste inchangé

  // v1[0] est maintenant 3
  cout << "v1 [0] = " << v1[0] << endl;

  // v2[0] est toujours 2
  cout << "v2[0] = " << v2[0] << endl;
}

void bad_copy2(Vector v1) {
  // Opérateur d'affectation
  Vector v2(5);

  v2 = v1;

  // v1[0] est aussi 2
  cout << "v1 [0] = " << v1[0] << endl;

  // v2[0] est aussi 2
  cout << "v2[0] = " << v2[0] << endl;

  v1[0] = 2; // v2[0] reste inchangé

  // v1[0] est maintenant 3
  cout << "v1 [0] = " << v1[0] << endl;

  // v2[0] est toujours 2
  cout << "v2[0] = " << v2[0] << endl;
}

Vector &Vector::operator=(const Vector&v){
    sz=v.sz;
    delete[] elements;
    elements = new double [sz];
    for (int  i = 0; i < sz; i++)
    {
        elements[i]=v.elements[i];
    }
    return * this;
    
}

int main(void) {
  Vector v(5);
  for (unsigned int i = 0; i < v.size(); i++) v[i] = 1;

  cout << "bad_copy1(v) (constructeur par copie):" << endl;
  bad_copy1(v);

  cout << "bad_copy2(v) (opérateur d'affectation):" << endl;
  bad_copy2(v);

    //tester la création des vecteurs par cop
  

  return EXIT_SUCCESS;
}
