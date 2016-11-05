#include<stdlib.h>

/*
Creates empty matrix of dimension row x col
*/
double ** createMatrix(int row, int col){
	double **matrix;
	
	//get space for matrix items
	matrix = malloc(row*sizeof(double *));
	for(int i=0; i<row; i++)
		matrix[i] = malloc(col*sizeof(double));

	return matrix;
}
