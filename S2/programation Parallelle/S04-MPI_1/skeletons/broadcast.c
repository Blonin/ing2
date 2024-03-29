/**
 * @ NAME: Broadcast.c
 * @ ACCESS: public
 * @ AUTHOR: Richter Gustave
 * @ CREATETIEME: 28-03-2024 10:48:28
 * @ EMAIL: richtergustave@gmail.com
 * @ DESCRIPTION:
 * @ COPYRIGHT: Richter Gustave
 * @ Modified by: Name
 * @ Modified time: 29-03-2024
 */

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define NRA 5                 /* number of rows in matrix A */
#define NCA 5                 /* number of columns in matrix A */
#define NCB 5                  /* number of columns in matrix B */
#define SIZE 5                  /* taille de la matrice*/
#define MASTER 0                /* taskid of first task */
#define FROM_MASTER 1           /* setting a message type */
#define FROM_WORKER 2           /* setting a message type */
#define TOL  0.001              /* Error tolerance in matrix product */

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

    double  **a,                   /* matrix A[NRA][NCA] to be multiplied */
            **b,                   /* matrix B[NCA][NCB] to be multiplied */
            **c,                   /* result matrix C[NRA][NCB] */
            aval,bval,cval,        /* init values for each matrix */
            err, errsq;            /* error and square error of the matrix product */


    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &taskid);
    if (numtasks < 2 ) {
        printf("Need at least two MPI tasks. Quitting...\n");
        MPI_Abort(MPI_COMM_WORLD, rc);
        exit(1);
    }
    numworkers = numtasks-1;

/*Creating the matrix*/
    if (taskid == 0) // 0 == MASTER ID
    {
      	printf("mpi_mm has started with %d tasks.\n",numtasks);

	   	a = (double**)malloc(NRA*sizeof(double*));
		double *ta = (double *)malloc(NRA * NCA * sizeof(double));	

		for (i=0;i<NRA;i++)
		{
			a[i] = &(ta[i*NCA]);
		}

	   	b = (double**)malloc(NCA*sizeof(double*));	
		double *tb = (double *)malloc(NCA * NCB * sizeof(double));	

		for (i=0;i<NCA;i++)
		{
			b[i] = &(tb[i*NCB]);
		}

		aval = 3.0;
		bval = 2.0;

        for (i=0; i<NRA; i++)
            for (j=0; j<NCA; j++)
                a[i][j]= aval;

        for (i=0; i<NCA; i++)
            for (j=0; j<NCB; j++)
                b[i][j]= bval;


        for (i=0; i<NRA; i++){
            for (j=0; j<NCA; j++){
                printf(" %f|",a[i][j]);
            }
            printf("\n");
        }
        
/*Sending the matrix*/

		rows=NRA/numworkers;
		
		for ( dest = 1; dest <= numworkers; dest++)
		{
			MPI_Send(&offset, sizeof(int), MPI_INT, dest, 1, MPI_COMM_WORLD);
			MPI_Send(&rows, sizeof(int), MPI_INT, dest, 2, MPI_COMM_WORLD);
		//	MPI_Send(&(a[offset][0]), rows*NCA, MPI_DOUBLE, dest, 3, MPI_COMM_WORLD); //l'adresse de l'offset 
			MPI_Send(&(b[0][0]), NCA*NCB, MPI_DOUBLE, dest, 4, MPI_COMM_WORLD);
			offset+=rows;
		}
    }
    
/*Worker trying to receive the matrix*/
    else
    {
        mtype == FROM_MASTER;
        MPI_Status status;
	    //firstly receiving the offset and the number of rows to make the matrix for each worker  
        MPI_Recv(&offset,sizeof(int),MPI_INT,0,1,MPI_COMM_WORLD, &status);
		MPI_Recv(&rows,sizeof(int),MPI_INT,0,2,MPI_COMM_WORLD, &status);
printf("%d\n",offset);
printf("%d\n",rows);
    
    
       // Allocate space for the chunk of a received and for the whole b matrix
	   /*a = (double**)malloc(rows*sizeof(double*));
		double *t = (double *)malloc(rows * NCA * sizeof(double));	

		for (i=0;i<rows;i++)
		{
			a[i] = &t[i*NCA];
		}*/œ

	   b = (double**)malloc(NCA*sizeof(double*));	
		double *tb = (double *)malloc(NCA * NCB * sizeof(double));	

		for (i=0;i<NCA;i++)
		{
			b[i] = &(tb[i*NCB]);
		}
    
    //receiving the matrix
    //	MPI_Recv(&(a[offset][0]),sizeof(int),MPI_DOUBLE,0,3,MPI_COMM_WORLD, &status);
		MPI_Recv(&(b[0][0]),NCA*NCB,MPI_DOUBLE,0,4,MPI_COMM_WORLD, &status);

        for (i=0; i<NRA; i++){
            for (j=0; j<NCA; j++){
                printf("%f",a[i][j]);
            }
            printf("\n");
        }

    }

    MPI_Finalize();
    return 0;
}