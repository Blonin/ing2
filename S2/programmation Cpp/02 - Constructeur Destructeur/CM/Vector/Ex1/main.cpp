using namespace std;

#include <iostream>
#include "Vector.hpp"

void bad_copy(Vector v1) {
	Vector v2 = v1;
	v1[0] = 2;
	cout << "v1[0]" << v1[0] << endl;
	cout << "v2[0]" << v2[0] << endl;
	v2[0] = 3;
	cout << "v1[0]" << v1[0] << endl;
	cout << "v2[0]" << v2[0] << endl;
}

void bad_copy2(Vector v1){
	Vector v2 = v1;
	v1[0] = 2;
	cout << "v1[0]" << v1[0] << endl;
	cout << "v2[0]" << v2[0] << endl;
	v2[0] = 2;
	cout << "v1[0]" << v1[0] << endl;
	cout << "v2[0]" << v2[0] << endl;

}


int main(int argc, char const *argv[])
{
	Vector v = Vector(5);
	for (int i = 0; i < v.size(); i++)
	{
		v[i]=i;
	}
	cout << "badcopy(v) : " <<endl;
	bad_copy(v);
	cout << "badcopy2(v): " << endl;
	bad_copy2(2);

	
	return 0;
}
