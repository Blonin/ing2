/**
 * @name: fileName
 * @access: public
 * @path: filePath
 * @author: Richter Gustave
 * @createtime: 19-03-2024 15:02:33
 * @email: richtergustave@gmail.com
 * @description:
 * @argument: NULL
 * @input: NULL
 * @output: NULL
 * @return: NULL
 * @copyright: Richter Gustave
 * @modifiedby: Name
 * @modifiedtime: 19-03-2024
 */
using namespace std;
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>

#include "Electrique.hpp"
#include "Light.hpp"
#include "Guirlande.hpp"

int main(int argc, char const *argv[])
{
    Light l1(0.1,false);
    Light l2(0.05,true);
    Light l3(0.1,false);
    Light l4(0.05,true);
    Light l5(0.1,false);

    vector<Light> l = {l1,l2,l3,l4,l5};
    //essaye de faire un vecteur en demandant a l'utilisateur
    Guirlande guirlande(l);

    //essaie de lecture du fichier
    //creation du flux de lecture
    ifstream ifs("Guirlande.txt");
    //verification si le flux a bien était créer
    if (ifs)
    {   
        std::string line;
        std::string name;
        int numLights, numBigLights;

        while (std::getline(ifs, line)) 
        {   
            std::stringstream ss(line);
            std::getline(data,name,);
            ss >> numLights >> numBigLights;  // Extract numbers after comma

            // Create a Street object and add it to the vector
            streets.push_back({name, numLights, numBigLights});
        }           
              
    }
    
    
    return 0;
}
