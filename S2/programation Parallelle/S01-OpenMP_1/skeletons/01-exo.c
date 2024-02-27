#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    
    double start;
    start = omp_get_wtime();
    for (int i = 0; i < 10; i++)
    {
        printf("%d \n",i);
    }
    double end = omp_get_wtime();
    printf("Execution time =%f \n",end-start);
    return 0;
}

