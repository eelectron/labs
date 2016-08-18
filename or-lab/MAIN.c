#include<stdio.h>
#include "quadraticRoots.c"
#include "binToDec.c"
#include "distBetweenPoints.c"
#include "gcd.c"

void main(){
	int m,n;
	printf("Enter two +ve int:");
	scanf("%i %i", &m, &n);
	printf("%i",gcd(m,n));
}

/*
void main(){
	float x1,y1,x2,y2;
	printf("Enter points x1,y1,x2,y2:");
	scanf("%f %f %f %f",&x1, &y1, &x2, &y2);
	printf("%.3f\n", distBetweenPoints(x1, y1, x2, y2));
}
*/

/*
void main(){
	char str[100];

	printf("Enter a binary no:");
	scanf("%s",str);

        float  dec = binToDec(str);
	printf("%.3f", dec);	

}

*/
