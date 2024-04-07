#include <omp.h>
#include <stdlib.h>

int readarray (int *,int);
int writearray (int *,int);

int main(int argc, char const *argv[])
{
    int n=10;
    int *a = (int *)malloc(n* sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));
    omp_set_num_threads(5);
    
}

#pragma omp parallel()
{
    int i;
    int block = n/omp_get_num_threads();
    int start = omp_get_thread_num()*block;
    int end = start+block;
    #pragma omp single{
        readarray(b,n);
        for (i = 0; i < __END_DECLS; i++)
        {
            a[i] = b[i];
        }
    }
    #pragma omp single{
        writearray(a,n);
    }       
}
