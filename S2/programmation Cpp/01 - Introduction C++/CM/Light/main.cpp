using namespace std;

#include <iostream>
#include "light.hpp"

//////////////////////////////////////////////////////////////////////////
// Programme : main.cpp                                                 //
// Acces     : Public                                                   //
// But       : Utilisation de la classe light                           //
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

int main() 
{ 
  Light Ampoule;

  cout << Ampoule.isOn() << endl;
  Ampoule.toggle();
  cout << Ampoule.isOn() << endl;

  return EXIT_SUCCESS;  
}
