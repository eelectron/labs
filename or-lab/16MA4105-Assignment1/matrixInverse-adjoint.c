#include "../determinant.c"
#include "../createMatrix.c"

/*This returns a cofactor matrix of a given nxn matrix*/
double ** cofactor(double **a, int n){
	double **c = malloc(n*sizeof(double *));
	for(int i=0; i<n; i++)
		c[i] = malloc(n*sizeof(double));

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			c[i][j] = power(-1,i+j)*determinant(getMinor(a, n, i, j), n-1);
	
	//return the resultant cofactor matrix
	return c;
}

/*Transpose of given matrix*/
void transpose(double **a, int n){
	double tmp;
	for(int i=1; i<n; i++)
		for(int j=0; j<i; j++){
			tmp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = tmp;	
		}
}

double ** matrixInverse(double **a, int n){
	//Inverse not possible if determinant is zero
	double det = determinant(a, n);
	printf("det = %.2lf\n",det);

	if(det == 0){
		printf("Inverse not possible because determinant is 0. :(\n");
		return NULL;
	}

	//find cofactor matrix
	double **c = cofactor(a, n);

	//get the transpose of cofactor matrix
	transpose(c, n);

	//divide the transposed matrix by determinant 
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			c[i][j] /= det;
	
	//return inverted matrix
	return c;
}

void main(){
        double **a;
        int n;
        printf("Enter order of matrix:");
        scanf("%i",&n);
		a = createMatrix(n, n);

        //user input
        scanMatrix(a, n, n);
	double **i = matrixInverse(a, n);
	
	//GOT INVERSE 
	if(i != NULL)	
		printMatrix(i, n, n);
	
	freeMinor(a, n);
}

