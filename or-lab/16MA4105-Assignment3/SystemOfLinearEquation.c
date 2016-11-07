/* This program gives the solution of a System of Consistent Linear Equation.
For Ex:
Input: 	 x0  + 2x1  +  x2   = 4
		 x0  + 3x1  + 2x2   = 6
		2x0  + 4x1  + 3x2 	= 9
Output: x0=1, x1=1, x2=1
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
		printf("x%i = %.2f\n", i, sol[i][n-1]);
	}
}
