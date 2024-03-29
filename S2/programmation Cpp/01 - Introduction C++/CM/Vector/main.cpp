using namespace std;

//////////////////////////////////////////////////////////////////////////
// Programme : main.cpp                                                 //
// Acces     : Public                                                   //
// But       : Utilisation de la classe Vector                          //
//                                                                      //
// Arguments                                                            //
// - IN      : neant                                                    //
// - IN/OUT  : neant                                                    //
// - OUT     : neant                                                    //
// Retour    : EXIT_SUCCESS Execution OK                                //
//             EXIT_FAILURE Execution KO                                //
//                                                                      //
// Historique                       Date        Version  par            //
// Ajout main.cpp                   25/12/2023  1.0.00   Alain BERTAILS //
//////////////////////////////////////////////////////////////////////////

#include <cmath>
#include "Vector.hpp"
using namespace std;

inline double sum_sqrt(Vector& v)
{
	double sum = 0;
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		sum += sqrt(v[i]);
	}
	return(sum);
}

int main(void)
{
	Vector v = Vector(5);
	for (int i = 0; i < v.size(); i++)
	{
		v[i]=i;
	}
	int sum=0;
	
	sum = sum_sqrt(v);
	cout << sum;

	return EXIT_SUCCESS;
}
