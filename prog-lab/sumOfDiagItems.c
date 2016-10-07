/*
This program prints sum of all diagonal elements.

 2  -1
-1  10

SUM of diagonal items= 12
*/

 double sumOfDiagItems(double **m, int row, int col){
	double sum =0;
	for(int i=0; i<row; i++)
		sum = sum + m[i][i];

	return sum;
}
