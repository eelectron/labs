#include<stdio.h>
#include "createMatrix.c"
#include "Simplex.c"


void main(){
	int p,q;
	printf("Enter dimension of initial Simplex table.");
	scanf("%i %i", &p, &q);
	  
	double **m = createMatrix(p, q);
	scanMatrix(m, p, q);
	
	//START SIMPLEX
	simplex(m, p, q);
}
