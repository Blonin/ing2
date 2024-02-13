#include <iostream>
#include "Pair.hpp"

int main()
{
	Pair p(15,16);
	Pair q {p};
  std::cout << p << q;

	Pair *hp = new Pair(23,42);
	std::cout << *hp;
	delete hp;

	return EXIT_SUCCESS;
}
