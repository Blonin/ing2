/**
 * @ name: compte_argc.c
 * @ access: public
 * @ Author: Richter Gustave
 * @ Create Time: 09-02-2024
 * @ email: richtergustave@gmail.com
 * @ description: programme qui prend en argument une liste d’entier et qui af-
fiche la somme de ces entiers
 * @ argument: NULL
 * @ input: Liste d'entier
 * @ output: affiche la somme
 * @ return: 0
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 09-02-2024
 */


#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n=0;
    if (argc<1)
    {
        printf("Erreur");
        return -1;
    }else{
        for (int i = 0; i < argc; i++)
        {
            n += atoi(argv[i]);
        }
        printf(n);
    }
    
    return 0;
}
