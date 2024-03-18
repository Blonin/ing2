/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 18-03-2024 23:20:32
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 18-03-2024
 */

#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__

using namespace std;
#include <iostream>

class Light : public Electrique
{ 
  private:

  protected:
    bool on;
    
  public:  
    Light ();  // Makes a new light

    void toggle();
    bool isOn() const;
    ~Light(){}
};

Light::Light(){
    on = false;
} 

void Light::toggle() {
    on = !on;
}

bool Light::isOn() const{
    return on;
}

#endif
