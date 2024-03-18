/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 18-03-2024 23:55:41
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 18-03-2024
 */

using namespace std;

#include <iostream>
#include "light.hpp"

int main(int argc, char const *argv[])
{
  Light Ampoule;

  cout << Ampoule.isOn() << endl;
  Ampoule.toggle();
  cout << Ampoule.isOn() << endl;

  return EXIT_SUCCESS;  
}
