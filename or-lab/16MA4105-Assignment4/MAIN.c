#include<stdio.h>
#include<stdlib.h>
#include "minMaxHelper.h"
#include "minAndMax.c"
#include "in-out.c"
//#include "eachRowMaxMin.c"
#include "eachColMinMax.c"
#include "frequency.c"

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
	frequency(mx, m, n);
}


/*
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
	eachColMinMax(mx, m, n);
}
*/

/* Unit test for eachRowMaxMin.
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
	eachRowMaxMin(mx, m, n);
}
*/

/* Unit test of minAndMax
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
	minAndMax(mx, m, n);
}
*/

/* Unit test of gcd.
void main(){
	int m,n;
	printf("Enter two +ve int:");
	scanf("%i %i", &m, &n);
	printf("%i",gcd(m,n));
}

*/

/* Unit test of distBetweenPoints.c.
void main(){
	float x1,y1,x2,y2;
	printf("Enter points x1,y1,x2,y2:");
	scanf("%f %f %f %f",&x1, &y1, &x2, &y2);
	printf("%.3f\n", distBetweenPoints(x1, y1, x2, y2));
}
*/

/* Unit test of binary to decimal .
void main(){
	char str[100];

	printf("Enter a binary no:");
	scanf("%s",str);

        float  dec = binToDec(str);
	printf("%.3f", dec);	

}

*/
