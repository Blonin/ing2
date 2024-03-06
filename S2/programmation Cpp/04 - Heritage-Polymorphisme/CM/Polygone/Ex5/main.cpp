using namespace std;

#include <iostream>
#include "../Ex4/Polygon.hpp"

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
  vector <const Polygon  *>  vp ;
  Polygon *p1 = new Rectangle(4,5);
  Polygon *p2 = new Triangle(4,5);

  // Ici le code a ajouter

  // n�oubliez pas delete !

  return EXIT_SUCCESS;
}
