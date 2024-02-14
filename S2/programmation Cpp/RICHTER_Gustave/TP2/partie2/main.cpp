#include <iostream>
#include "Light.hpp"
using namespace std;

/*
void pair1(){

	Pair p(15,16);
	Pair q {p};
	cout << p << q;

	Pair *hp = new Pair(23,42);
	cout << *hp;
	delete hp;
}
*/

/**
 * @brief function to test the ligth
 * 
 */
void ligth1()  
{ 
	Ligth Ampoule; 
  	cout << Ampoule << endl ;
  	Ampoule.toggle();
  	cout << Ampoule << endl ;
}

int main()
{
	//pair1();
	ligth1();
	return EXIT_SUCCESS;
}
