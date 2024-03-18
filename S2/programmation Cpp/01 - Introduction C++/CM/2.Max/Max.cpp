/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 18-03-2024
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

#include <iostream>
using namespace std;

#define MAX(a,b) a<b?a:b

int main(int argc, char const *argv[])
{
    int i;
    i = MAX(2,3) + 5;
    cout << i << endl;
    int j ;
    j = MAX(3,2)+5;
    cout << j << endl;

    return 0;
}
