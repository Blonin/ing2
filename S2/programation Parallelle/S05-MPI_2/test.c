#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(int argc, char *argv[])
{
    int l=3,        // nums of line
        c=4,        // num of columns
        myid,       // Id identifier
        np,         // num of tasks
        numworkers; // number of proc

    double **a,     /*matrix a[l][c]*/
            aval;   //value af a


    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
    if (numtasks < 2 ) {
        printf("Need at least two MPI tasks. Quitting...\n");
        MPI_Abort(MPI_COMM_WORLD, rc);
        exit(1);
    }
    numworkers = numtasks-1;

    //MASTER TASK
    if (myid==0)
    {
        printf("mpi_mm has started with %d tasks.\n",numtasks);

    }
    

    return 0;
}
