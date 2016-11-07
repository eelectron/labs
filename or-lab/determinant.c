#include<stdio.h>
#include<limits.h>
#include<unistd.h>
#include<stdlib.h>
#include "power.c"
#include "in-out.c"


/* a[][](original) ----> m[][](minor) */
double ** getMinor(double **a, int order,int row, int col){
	//create a empty matrix
	//order of minor is 1 less than order of given matrix
	double **m = malloc((order-1)*sizeof(double *));
	for(int i=0; i<order-1; i++){
		m[i] = malloc((order-1)*sizeof(double));
	}
	
	//Fill m[][] matrix with the minor of a[0][col]
	
	//p,q keeps track of position in m[][]
	int p=0,q=0;

	//iterate over original matrix
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(i != row && j != col){		//get item whose row and col are diff from row 
				m[p][q] = a[i][j];			//and col of a[0][col]
				q++;	
			}
		}
		q=0;	//reset q
		//increase p only if q is greater than 0
		if(q > 0)
			p++;
	}
	
	//return minor
	return m;
}

void freeMinor(double **m, int row){
	for(int i=0; i<row; i++)
		free(m[i]);
	free(m);
}

double determinant(double **a, int n){
	if(n < 1){
		printf("Order of matrix should be more than zero!!");
		return -1000;
	}	
	
	if(n == 1)
		return a[0][0];
	
	if(n == 2){
		return a[0][0] * a[1][1] - a[1][0] * a[0][1]; 
	}
	
	double det = 0;
	//expand along first row to get determinant
	for(int col=0; col<n;col++){
		double **minor = getMinor(a, n, 0, col); 			//get minor of a[0][col] item
		det += power(-1,col) * a[0][col] * determinant(minor, n-1);	
		freeMinor(minor, n-1);					//free space occupied by minor
	}
	return det;
}
