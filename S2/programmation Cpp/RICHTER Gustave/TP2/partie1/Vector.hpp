#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

class Vector {
  private:
    double* elements;
    unsigned int sz;
  protected:
  public:
    //Constructeur dynamique
    Vector(unsigned int s);
    //Constructeur par copie
    Vector(const Vector &v);
    //destructeur
    ~Vector();
    //Affectation
    Vector &operator =(const Vector &v);

    unsigned int size() const;
    double& operator[](unsigned int i);
};

#endif

