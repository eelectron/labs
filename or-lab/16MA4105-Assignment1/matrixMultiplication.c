#include<stdio.h>

int p,q,r;

/*Fill a m x n matrix.*/
void scanMatrix(int *a, int m, int n ){
	for(int i=0; i<m*n; i++)
		scanf("%i",&a[i]);
}

/*Print a m x n matrix on screen.*/
void printMatrix(int *a, int m, int n ){
	for(int i=0; i<m*n; i++){
		if(i%n == 0)
			printf("\n");
		printf("%i ",a[i]);
	}
}

void main(){
	
	printf("Enter value of p,q,r");
	scanf("%i %i %i", &p, &q, &r);

	int x[p][q],y[q][r],z[p][r];
	
	//take matrix value from user
	scanMatrix(&x[0][0], p, q);
	scanMatrix(&y[0][0], q, r);

	for(int i=0; i<p; i++){
		for(int j=0; j<r; j++){
			z[i][j]=0;
			for(int k=0; k<q; k++){
				z[i][j] += x[i][k]*y[k][j];
			}
		}
	}
	
	printf("Matrix Multiplication result:\n");
	printMatrix(&z[0][0], p, r);
}
