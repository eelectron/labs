#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "in-out.c"

/*
  Exchanges two rows of a matrix*/
bool exchangeRow(double **m,int row, int col, int r){
	int newRow = -1;
	double temp;
	
	//find row which has non-zero item in column r
	for(int i=r; i<row; i++){
		if(m[i][r] != 0){
			newRow = i;
			break;
		}
	}
	
	//if every item of that col is zero then dont perform exchange
	if(newRow == -1)
		return false;
	
	//exchange row
	for(int i=0; i<col; i++){
		temp = m[r][i];
		m[r][i] = m[newRow][i];
		m[newRow][i] = temp;
	}
	
	return true;		
}

/*
	This function reduces other rows using r'th row.
*/
void reduce(double **m, int row, int col, int p, int q){
	//pivot
	double pivot = m[p][q];

	//divide r'th row by m[r][r]	
	for(int j=0; j<col; j++)
		m[p][j] = m[p][j]/pivot;
	
	
	for(int i=0; i<row; i++){
		//reduce other rows leaving given row p.
			if(i != p){
				float term = m[i][q];		//coefficient of var which must be made to zero
				for(int j=0; j<col; j++){
					m[i][j] = m[i][j] - m[p][j]*term;
				}
			}	
	}

	//print 
	printMatrix(m, row, col);
}


/*
  input: A m x n matrix
  output: A m x n matrix in row reduced echelon form.
*/
void rref(double **m, int row, int col){
	double pivot;
	int lead;
	for(int i=0; i<row; i++){
		lead = i;					//lead will ALWAYS be >= i
		pivot = m[i][lead];
		while(pivot == 0 && lead < col){
			//perform exchange
			if(exchangeRow(m, row, col, i)){
				break;	
			}
			else{
				lead++;					//new lead
				pivot = m[i][lead];		//new pivot	
			}	
		}
		
		if(lead < row)					//reduce using row which has atleast 1 non-zero item
			reduce(m, row, col, i, lead);
	}
}

void main(){
	double **mx;
	int m,n;
	printf("Enter m = ");
	scanf("%i", &m);
	
	printf("Enter n = ");
	scanf("%i", &n);
	
	//get space
	mx = malloc(m*sizeof(double *));
	for(int i=0; i<m; i++)
		mx[i] = malloc(n*sizeof(double));
		
	scanMatrix(mx, m, n);
	rref(mx, m, n);
	printMatrix(mx , m, n);
}
