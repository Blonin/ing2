/**
 * @ name: Fraction.hpp
 * @ access: public
 * @ Author: Richter Gustave
 * @ Create Time: 09-02-2024
 * @ email: richtergustave@gmail.com
 * @ description: 
 * 
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return:    EXIT_SUCCESS Exection OK
 *              EXIT_FAILURE Execution KO
 * 
 * @ copyright: Richter Gustave
 * 
 * @ Modified by: 
 * @ Modified time: 
 */

#ifndef __FRACTION_HPP__
#define __FRACTION_HPP__

class Fraction
{
  private:
    int numerateur;
    int denominateur;
  
  protected:

  public:
    // Constructeur
    Fraction ();
    Fraction (int n);
    Fraction (int n,int d);
    // Destructeur
    ~Fraction();
    // C’est une fonction AMIE, pas une methode membre
    friend std::ostream&operator << (std::ostream&out,const Fraction &f);
};

#endif