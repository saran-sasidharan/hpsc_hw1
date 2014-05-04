// Serial code to multiply two matrix of dimension N*N

#include<stdio.h>
//#include<omp.h> // Just for finding run time
#include<time.h>
#define N 800
double a[N][N],b[N][N],c[N][N];
int main()
{
	double t1,t2,t;
	t1 = clock();

	double temp;
	
	// feeding the two intial matrix with a_val & b_val
	int i,j,k;
	for(j=0;j<N;j++){
		for(i=0;i<N;i++){
			a[j][i] = i+j;
			b[j][i] = i*j;
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

	t2 = clock();
	t = (double)(t2-t1)/CLOCKS_PER_SEC;

	/*		
	printf("\n");
	for(j=0;j<N;j++){
		printf("\n");
		for(i=0;i<N;i++){
			printf("%f \t",c[j][i]);
		}
	}*/
	printf("Time taken %f \n",t);
//return 0;
}
		
		
