/**
 * @ name: Fraction.hpp
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 13-02-2024
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
    
    //déclaration de la méthode pour l'opérateur =*
    void operator*=(const Fraction& autre);
    
    //déclaration de la méthode pour l'opérateur *
    Fraction operator* (const Fraction& autre) const;
    
    int getDen()const;
    int getNum()const;

};

  
    /**
     * @brief 
     * 
     * @param f1 
     * @param f2 
     * @return Fraction 
     */
    Fraction operator* (const Fraction& f1, const Fraction& f2);
  



#endif