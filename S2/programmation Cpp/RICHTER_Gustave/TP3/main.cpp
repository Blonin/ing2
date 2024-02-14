/**
 * @ name: Main.cpp
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 13-02-2024
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 14-02-2024
 */

using namespace std;

#include <iostream>
#include "Fraction.hpp"

void exo1(){
  //vérif exo 1
  Fraction f1(4,5);
  Fraction f2(3,4);
  cout << f1<<endl;
  cout << f2<<endl;

  f1 *= f2;
  cout << f1;


}

void exo2(){

  //vérif exo 2
  Fraction f2(3,11);
  Fraction f3(13,3);
  Fraction res = f2*f3;
  cout << res;
  
  res = f2*f3*res;
  cout <<" res de f2*f3*res : "<< res<<endl;
  res = f2*3;
  cout << res;
  //code produisant une erreur
  //res = 2*f2;
  //cout << res;
}

void exo3(){
  Fraction f1(4,5);
  Fraction res = 2*f1;
  cout << "res exo3 : " << res;
  
  Fraction f1(4,5);
  Fraction f2(3,11);
  Fraction f=f1*f2;
  cout << f;
  f=f1*f2*f;
  cout << f;
  f=f1*2;
  cout << f;
  f=2*f1;
  cout << f;
  
}

int main()
{
  //var juste utilisé pour mettre en pause le programme
  char n;
  exo1();
  printf("Pause appuyer sur une touche pour passer a l'exo 2");
  scanf("%c",&n);
  exo2();
  printf("Pause appuyer sur une touche pour passer a l'exo 3");
  scanf("%c",&n);
  exo3();

  return EXIT_SUCCESS;
}
