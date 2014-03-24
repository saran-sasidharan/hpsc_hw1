// Serial code to multiply two matrix of dimension N*N

#include<stdio.h>
#include<omp.h>
#define N 500
double a[N][N],b[N][N],c[N][N];
int main()
{
	double t1,t2,t;
	t1 = omp_get_wtime();

	double a_val=1.0,b_val=2.0;
	double temp;
	
	// feeding the two intial matrix with a_val & b_val
	int i,j,k;
	for(j=0;j<N;j++){
		for(i=0;i<N;i++){
			a[j][i] = a_val;
			b[j][i] = b_val;
		}
	}

	// Multiplication of matrices
	for(j=0;j<N;j++){
		for(i=0;i<N;i++){
			temp = 0.0;
			for(k=0;k<N;k++){
				temp = temp + a[j][k]*b[k][i];
			}
			c[j][i] = temp;
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
	printf("Time taken %f \n",t);
}
		
		
