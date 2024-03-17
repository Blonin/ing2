/**
 * @name: main.cpp 
 * @access: public
 * @author: Richter Gustave
 * @createtime: 17-03-2024
 * @email: richtergustave@gmail.com
 * @description: 
 * @argument: NULL
 * @input: NULL
 * @output: NULL
 * @return:    EXIT_SUCCESS Execution OK 
                EXIT_FAILURE Execution KO   
 * @copyright: Richter Gustave

 * @modifiedby: 
 * @modifiedtime: 
 */


#include <iostream>
using namespace std;

#include "Electrique.hpp"
#include "Guirlande.hpp"
#include "Light.hpp"

//Je ne comprend pas Pourquoi il supprime autant de "Light" et "Electrique"
// lors de l'éxécution du programme ni pourquoi il affiche "0.11" pas trouvé d'où sors le 11 il s'agit de la puissance

int main(int argc, char const *argv[])
{
    Light *l1 = new Light(0.05);
    Light *l2= new Light(0.1);

    vector<Light> l = {l1,l2};
    Guirlande guirlande(l);

    guirlande.afficher();
    cout << "puissance de la guirlande : " << guirlande.puissance() << endl;
    
    guirlande.allumer();
    guirlande.afficher();
    cout << "puissance de la guirlande : " << guirlande.puissance() <<endl;

    guirlande.eteindre();
    guirlande.afficher();

    delete l1;
    delete l2;
    return 0;
}
