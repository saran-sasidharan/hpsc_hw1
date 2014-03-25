// Serial code to multiply two matrix of dimension N*N

#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#define N 100  //Should be a multiple of number of processes
double a[N][N],b[N][N],d[N][N];
int main(int argc, char *argv[])
{
	MPI_Status status;
	MPI_Init(&argc,&argv);

	double t1,t2;
	t1 = MPI_Wtime();

	int ID,NP,i,j,k,n,tag=1,count=0;
	MPI_Comm_rank(MPI_COMM_WORLD,&ID);
 	MPI_Comm_size(MPI_COMM_WORLD,&NP);
	n = N/NP;
	
	double *c;
	c = (double*)calloc(n*N,sizeof(double));
	double temp;
	
	// Assigning values to matrix
	for(j=0;j<N;j++){
		for(i=0;i<N;i++){
			a[j][i] = i+j;
			b[j][i] = i*j;
		}
	}
	
	// Multiplication of matrices
	for(j=0;j<n;j++){
		for(i=0;i<N;i++){
			temp = 0.0;
			for(k=0;k<N;k++){
				temp = temp + a[j+ID*n][k]*b[k][i];
			}
			c[count] = temp;
			count = count+1;
			if (ID==0) d[j][i] = temp;
		}
	}
	if (ID > 0){
		MPI_Send(c,n*N,MPI_DOUBLE,0,tag,MPI_COMM_WORLD);
	}
	
	if (ID == 0){
	for (i=1;i<NP;i++){
		MPI_Recv(c,n*N,MPI_DOUBLE,i,tag,MPI_COMM_WORLD,&status);
		count = 0;
		for (j=0;j<n;j++){
			for (k=0;k<N;k++){
				d[j+i*n][k] = c[count];
				count = count+1;
			}
		}
	}

	t2 = MPI_Wtime()-t1;
	/*
	printf("\n");
	for(j=0;j<N;j++){
		printf("\n");
		for(i=0;i<N;i++){
			printf("%f \t",d[j][i]);
		}
	}*/

	printf("Time taken %f \n",t2);
	}
free(c);
MPI_Finalize();
return 0;
}
		
		
