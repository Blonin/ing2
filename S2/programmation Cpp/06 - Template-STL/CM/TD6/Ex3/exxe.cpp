 /**
  * @ name: fileName
  * @ access: public
  * @ Path: filePath
  * @ Author: Richter Gustave
  * @ Create Time: 27-03-2024 12:44:25
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
 
using namespace std;
 
#include <iostream>
#include <list>
#include "Vector.hpp"
 
int main(void)
{
  Vector<char> vc(314);
 
  std::cout << "Vector (char): [";
/*
  for (unsigned int i = 0; i < vc.size() - 1; ++i) { std::cout << vc[i] << ", "; }
  std::cout << vc[vc.size() - 1] << "]" << std::endl;
*/
  Vector<string> vs(42);
  for (unsigned int i = 0; i < vs.size() - 1; ++i) { std::cout << vs[i] << ", "; }
  std::cout << vs[vs.size() - 1] << "]" << std::endl;
 
  Vector<list<int>> vli(74);
 
  return EXIT_SUCCESS;
}