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
 * @ Modified time: 19-03-2024
 */

using namespace std;

#include <iostream>
#include <fstream>
#include "Fraction.hpp"

void Fraction::operator*=(const Fraction& autre){
  numerateur *= autre.numerateur;
  denominateur *= autre.denominateur;
}


int main()
{
  Fraction f1(4,5);
  Fraction f2(3,11);
  
  f1 *= f2;
  cout << f1;

  return EXIT_SUCCESS;
}
