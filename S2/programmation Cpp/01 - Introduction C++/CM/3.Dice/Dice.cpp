/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 18-03-2024 22:57:41
 * @ =email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: 0 if success
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 18-03-2024
 */

#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

const int SIDES=6;
inline int R_SIDES() {return (rand () % SIDES +1) ; } 

int main(int argc, char const *argv[])
{
    int i;
    int n_dice = 2;
    srand(clock());
    cout << "\n Entrer le nombre de jet de dés !" << endl;
    int jet;
    cin >> jet;
    int *outcomes = new int [n_dice *SIDES +1] ;
    for (int i = 0; i < jet; ++i)
    {
        outcomes[R_SIDES() +R_SIDES()]++;
    }
    cout << "probabilité" << endl;
    for (int i = 2; i < n_dice; ++i)
    {
        cout << " i = " << setw(2) << i << " p=" << setw(3) << static_cast<double>(100*outcomes[i]/jet) << "%" <<endl;
    }

    return 0;
}

