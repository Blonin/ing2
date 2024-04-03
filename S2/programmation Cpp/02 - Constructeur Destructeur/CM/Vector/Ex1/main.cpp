using namespace std;

#include <iostream>
#include "vector.hpp"

void bad_copy(Vector v1) {
	vector v2 = v1;
	v1[0] = 2;
	cout << "v1[0]" << v1[0] << endl;
	cout << "v2[0]" << v2[0] << endl;

}
