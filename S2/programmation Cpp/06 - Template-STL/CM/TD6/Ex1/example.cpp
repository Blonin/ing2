#include <iostream>
using namespace std;
#include "Fraction.hpp"

template <typename T>
T mini (const T& a, const T& b){
    return (a < b ? a : b);
}

int main(){
    double dmin,d1{5.1},d2{9.8};
    int imin,i1{9},i2{4};

    dmin = mini(d1,d2);
    imin = mini<int>(i1,i2);

    Fraction f1(1,2),f2(2,3);
    Fraction f3(dmin,imin);
    

    cout << f3;
    cout << mini(f1,f2);
    cout << mini(f1,f3);
    return 0;
}