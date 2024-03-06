#include <iostream>
#include "../Ex1/Personne.hpp"

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
{ Etudiant Alain("BERTAILS","Alain");
  
  Alain.setId("0001");
  Alain.afficher();
  
  Alain.setId("0002");
  Alain.setNom("TERRIEUR");
  Alain.afficher();

  return EXIT_SUCCESS;
}
