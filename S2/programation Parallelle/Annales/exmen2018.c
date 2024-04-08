#include <omp.h>
#include <stdlib.h>

int readarray (int *,int);
int writearray (int *,int);

int main(int argc, char const *argv[])
{
    omp_set_num_threads(8);
    printf("num thread : %d \n",omp_get_num_threads());

    #pragma omp parallel num_threads(4){
        int id = omp_get_thread_num();
        printf("id : %d",id);
        printf("cb de thread : %d",omp_get_num_threads());
    }
    
}

