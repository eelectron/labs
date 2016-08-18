#include<stdio.h>
#include "fibonacci.c"

void main(){
	int n;
	printf("How many terms of fibonacci you want:");
	scanf("%i", &n);
	
	fibonacci(n);
}
