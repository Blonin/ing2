/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 18-03-2024 23:25:25
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 29-03-2024
 */

#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

template <typename T>
class Vector {
protected:
    T* elem;
    int unsigned sz;
public:
    Vector(unsigned int s);
    ~Vector();
    
    T& operator[](unsigned int i);
    unsigned int size() const;

    const T& operator[](unsigned int i) const;
};

/// @brief Creation d'un vecteur 
/// @tparam T 
/// @param s taille du vecteur
template<typename T>
Vector<T>::Vector(unsigned int s)
{
    //défini la taille
    sz = s;
    //création du vecteur
    elem = new T[sz];
    //verification de la bonne création de ce dernier
    if (!elem)
    {
        throw exception();
    }
    //initialisation de chaque element 
    for (unsigned int i = 0; i < sz; ++i)
    {
        elem[i] = T();
    }
    
}

/// @brief renvoi la taille du vecteur
/// @tparam T vecteur dont on veux la taille
/// @return INT
template<typename T>
unsigned int Vector<T>::size() const {
    return sz;
}


/// @brief renvoi l'element de la position voulu
/// @tparam T le vecteur
/// @param i la position de l'element
/// @return element
template<typename T>
T& Vector<T>:: operator[](unsigned int i ){
    //verification si l'element est dans le vecteur
    if (i>=sz || i<0)
    {
        throw out_of_range("NONONON t'es pas dans le vecteur DOMMAGE");
        exit(-1);
    }
    
    return elem[i];
}

/// @brief renvoi un référence en "const" de l'elem
/// @tparam T Vecteur
/// @param i 
/// @return 
template <typename T>
const T& Vector<T>::operator[](unsigned int i) const {
    //verifie si l'element est dans le vecteur
    if (i >= sz) {
        throw out_of_range{"Vector::operator[]"}; 
    }

    return elem[i];
}

/// @brief Détruction du vecteur
template <typename T>
Vector<T>::~Vector()
{
    //BOOM
    delete[] elem;
}

#endif


