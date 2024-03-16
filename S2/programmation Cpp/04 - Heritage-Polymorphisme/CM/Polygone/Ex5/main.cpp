
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

using namespace std;

#include <iostream>
#include <vector>

#include "Polygon.hpp"

int main(){
  vector <const Polygon  *>  vp ;
  Polygon *p1 = new Rectangle(4,5);
  Polygon *p2 = new Triangle(4,5);
  vp.push_back(p1);
  vp.push_back(p2);
  // n�oubliez pas delete !
  for (auto p : vp)
  {
    cout<< p->getArea() <<endl;
  }
  delete p1;
  delete p2;
  

  return EXIT_SUCCESS;
}
