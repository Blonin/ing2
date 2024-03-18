/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 05-03-2024 15:13:30
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
#define N 40

void sum(int* p, int n, int d[]){
    *p=0;
    for (int i = 0; i < n; ++i)
    {
        *p += d[i];
    }
    
}


int main(int argc, char const *argv[])
{

    int data [N];
    for (int i = 0; i < N; ++i)
    {
        data[i] = i;
    }

    int accum = 0;
    sum(&accum,N,data);
    cout << "Sume is : "<< accum << endl;
    
    return 0;
}
