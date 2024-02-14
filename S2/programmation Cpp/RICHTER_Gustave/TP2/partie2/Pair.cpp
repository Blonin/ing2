/**
 * @ name: Paire.cpp
 * @ access: public
 * @ Author: Richter Gustave
 * @ Create Time: 09-02-2024
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 */

#include <iostream>
#include "Pair.hpp"

/**
 * @brief Construct a new Pair:: Pair object
 * 
 * @param a 
 * @param b 
 */
Pair::Pair(int a, int b){
    *pa = a;
    *pb = b;
}

/**
 * @brief Construct a new Pair:: Pair object by copying the other one to the new one
 * 
 * @param other 
 */
Pair::Pair(const Pair & other){
    *pa = *other.pa;
    *pb = *other.pb;    
}

/**
 * @brief Destroy the Pair:: Pair object
 * 
 */
Pair::~Pair(){}

std::ostream& operator<<(std::ostream& out, const Pair& p){
    out <<"Pair : ()"<< p.pa << ", " <<p.pb << ")"<<std::endl;
}