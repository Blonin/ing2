using namespace std;

#include <iostream>
#include "Fraction.hpp"

int main()
{
  Fraction f1(4,5);
  Fraction f2(3,11);

  f1 *= f2;
  cout << f1;

  return EXIT_SUCCESS;
}
