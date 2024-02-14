/**
 * @ name: Light.cpp
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 14-02-2024
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 14-02-2024
 */

#include <iostream>
#include "Light.hpp"

/**
 * @brief Construct a new Light:: Light object
 * 
 */
Ligth::Ligth(){
    on=false;
}

/**
 * @brief Destroy the Light:: Light object
 * 
 */
Ligth::~Ligth(){}

/**
 * @brief Switch the light on and off
 * 
 */
void Ligth::toggle(){
    on= !on;
}

/**
 * @brief return if the light is on or not
 * 
 * @return true 
 * @return false 
 */
bool Ligth::isOn(){
    return on;
}

/**
 * @brief Friend function printing O or . if the light in on or not
 * 
 * @param out 
 * @param l 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Ligth& l){
    if (l.on)
    {
        out << "O";
    }else
    {
        out <<".";
    }
    return out ;
}

