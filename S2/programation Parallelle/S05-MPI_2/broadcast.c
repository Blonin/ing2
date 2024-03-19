/**
 * @ name: fileName
 * @ access: public
 * @ Path: filePath
 * @ Author: Richter Gustave
 * @ Create Time: 19-03-2024 16:27:03
 * @ email: richtergustave@gmail.com
 * @ description:
 * @ argument: NULL
 * @ input: NULL
 * @ output: NULL
 * @ return: NULL
 * @ copyright: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 19-03-2024
 */
# include <mpi.h>
# include <stdio.h>
# include <string.h>
#include <stdlib.h>

#define SIZE 10
#define MASTER 0


int main(int argc, char *argv[])
{   
    int	numtasks,              /* number of tasks in partition */
        taskid,                /* a task identifier */
        numworkers,            /* number of worker tasks */
        source,                /* task id of message source */
        dest,                  /* task id of message destination */
        mtype,                 /* message type */
        rows,                  /* rows of matrix A sent to each worker */
        averow, extra, offset, /* used to determine rows sent to each worker */
        i, j, k, rc;           /* misc */

    int ids[SIZE] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

    double **a,                   /* matrix A[NRA][NCA] to be multiplied */
        **b,                   /* matrix B[NCA][NCB] to be multiplied */
        **c,                   /* result matrix C[NRA][NCB] */
    	aval,bval,cval,        /* init values for each matrix */
        err, errsq;            /* error and square error of the matrix product */

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&taskid);  
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);

    if (taskid == MASTER)
    {
        //making the matrix
        a = (double**)malloc(SIZE*sizeof(double*));
        double *ta = (double *)malloc(SIZE * SIZE * sizeof(double));	

        for (i=0;i<SIZE;i++)
        {
            a[i] = &(ta[i*SIZE]);
        }

        b = (double**)malloc(SIZE*sizeof(double*));	
        double *tb = (double *)malloc(SIZE * SIZE * sizeof(double));	

        for (i=0;i<SIZE;i++)
        {
            b[i] = &(tb[i*SIZE]);
        }

        aval = 3.0;
        bval = 2.0;

        for (i=0; i<SIZE; i++)
            for (j=0; j<SIZE; j++)
                a[i][j]= aval;

        for (i=0; i<SIZE; i++)
            for (j=0; j<SIZE; j++)
                b[i][j]= bval;
    }
    
    
   // Broadcast 
   if (taskid == 0) {
	   printf("\n========================================\n");
	   printf(" Starting MPI_Bcast...");
	   printf("\n========================================\n");
   }
   MPI_Barrier(MPI_COMM_WORLD);
   printf("Before broadcast -- I am rank %d. message: %f\n",taskid,(b[0][0]));

   // si je suis le 0 je fais le broadcast les autres enregistre le message dans la var message
   MPI_Bcast(&(b[0][0]), SIZE*SIZE, MPI_CHAR, 0,MPI_COMM_WORLD);
   MPI_Barrier(MPI_COMM_WORLD);
   

	for (i=0; i<SIZE; i++) ids[i]=i;
	printf("I am rank %d. ids: ",taskid);
	for (i=0; i<SIZE; i++) printf("%d, ",ids[i]);
	printf("\n");

    
   printf("After broadcast -- I am rank %d. rxids: ",taskid);
    for (i=0; i<SIZE; i++)
        for (j=0; j<SIZE; j++)
            printf("%f",b[i][j]);
    

    
    return 0;
}
