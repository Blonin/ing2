/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 18-03-2024 23:13:28
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

using namespace std;
#include <iostream>

void swap (int * i, int* j){
    int tmp =*i;
    *i = *j;
    *j = tmp;
}

void swap_double(double* i, double*j){
    double tmp =*i;
    *i = *j;
    *j = tmp;
}


int main(int argc, char const *argv[])
{
    int m=5, n=10;
    cout << "m="<<m<<" n="<<n<<endl;
    swap(&m,&n);
    cout << "m="<<m<<" n="<<n<<endl;

    double x=5.3, y=10.6;
    cout << "x="<<x<<" y="<<y<<endl;
    swap_double(&x,&y);
    cout << "x="<<x<<" y="<<y<<endl;

    return 0;
}
