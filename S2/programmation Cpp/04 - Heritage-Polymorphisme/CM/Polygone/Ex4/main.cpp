using namespace std;

#include <iostream>
#include "Polygon.hpp"

//////////////////////////////////////////////////////////////////////////
// Programme : main.cpp                                                 //
// Acces     : Public                                                   //
// But       : Utilisation de la classe Etudiant                        //
//                                                                      //
// Arguments                                                            //
// - IN      : neant                                                    //
// - IN/OUT  : neant                                                    //
// - OUT     : neant                                                    //
// Retour    : EXIT_SUCCESS Execution OK                                //
//             EXIT_FAILURE Execution KO                                //
//                                                                      //
// Historique                       Date        Version  par            //
// Ajout main.cpp                   20/02/2024  1.0.00   Alain BERTAILS //
//////////////////////////////////////////////////////////////////////////

int main()
{
  Rectangle rect(5, 3);
  cout << "Aire du rectangle :"  << rect.getArea() << endl;

  Triangle tri(4, 6);
  cout << "Aire du triangle : " << tri.getArea() << endl;

  return EXIT_SUCCESS;
}
