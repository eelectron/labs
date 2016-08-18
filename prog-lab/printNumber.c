/*input: 12345
 output 5 4 3 2 1*/
#include<stdio.h>
#include "countDigit.c"

void printNum(int n){
	int digitCount = countDigit(n);
	int a[digitCount];	//to store individual digit
	
	for(int i=digitCount-1; i>=0; i--){
		//extract last digit and store in array
		a[i] = n%10;

		//remove last digit
		n /= 10;
		
	}

	//print number
	for(int i=digitCount-1; i>=0; i--)
		printf("%i ",a[i]);
}



void main(){
	int n;
	printf("Enter a INTEGER:");
	scanf("%i",&n);
	printNum(n);
	printf("\n");
}
