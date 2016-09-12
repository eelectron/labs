/* This program gives the solution of a System of Consistent Linear Equation.
For Ex:
Input: 	x1 + 2x2 + x3   = 4
	x1 + 3x2  + 2x3 = 6
	2x + 4y + 3x3 = 9
Output: x=1, y=1, z=1
*/

#include "reducedRowEchelon.c"



/*This function takes a augmented matrix and its row  and col.
output : matrix in its rref form.*/
double ** solOfConsystem(double **m, int r, int c){	
	rref(m, r, c);		//convert the given augmented matrix in reduced row echelon form
	return m;
}


void main(){
	double **mx;
	int m,n;
	printf("Enter m = ");
	scanf("%i", &m);
	
	printf("Enter n = ");
	scanf("%i", &n);
	
	//get space for storing matrix item
	mx = malloc(m*sizeof(double *));
	for(int i=0; i<m; i++)
		mx[i] = malloc(n*sizeof(double));
		
	scanMatrix(mx, m, n);
	double **sol = solOfConsystem(mx, m, n);		
	printMatrix(sol , m, n);		//get the solution of sys of consistent linear eq.

	printf("Number of equations = %i\n",m);
	printf("Number of variables = %i\n",n-1);

	//print solution
	for(int i=0; i<m; i++){
		printf("x%i = %.2f\n",i+1, sol[i][n-1]);
	}
	
}
