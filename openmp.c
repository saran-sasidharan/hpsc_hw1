// openMP code to multiply two matrix of dimension N*N

#include<stdio.h>
#include<omp.h>
#define N 100
#define NP 2
double a[N][N],b[N][N],c[N][N];
int main()
{
	double t1,t2,t;
	t1 = omp_get_wtime();
	
	// feeding the two intial matrix with a_val & b_val
	int i,j,k;
	for(j=0;j<N;j++){
		for(i=0;i<N;i++){
			a[j][i] = i+j;
			b[j][i] = i*j;
		}
	}
	
	omp_set_num_threads(NP);
	// Multiplication of matrices
	#pragma omp parallel
	{
	int j,i,k; //change here too	
	#pragma omp for
	for(j=0;j<N;j++){
		//#pragma omp for
		for(i=0;i<N;i++){
			for(k=0;k<N;k++){
				c[j][i] = c[j][i] + a[j][k]*b[k][i];
			}
		}
	}
	}

	t2 = omp_get_wtime();
	t = t2-t1;

	/*			
	printf("\n");
	for(j=0;j<N;j++){
		printf("\n");
		for(i=0;i<N;i++){
			printf("%f \t",c[j][i]);
		}
	}*/
	printf("Time taken %f seconds, with %d threads\n",t,NP);
}
		
		
