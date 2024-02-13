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
 * @ Modified time: 13-02-2024
 */

using namespace std;

#include <iostream>
#include "Fraction.hpp"

int main()
{
  /*
  //vérif exo 1
  Fraction f1(4,5);
  Fraction f2(3,11);
  cout << f1<<endl;
  cout << f2<<endl;

  f1 *= f2;
  cout << f1;

  //vérif exo 2
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
*/
  //verif exo3
  Fraction f1(4,5);
  Fraction res = 2*f1;
  cout << "res exo3 : " << res;

  return EXIT_SUCCESS;
}
