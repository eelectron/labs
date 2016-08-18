#include<stdio.h>

void swap(int *a, int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void main(){
	int a,b;
	printf("Enter two integers:");
	scanf("%i %i", &a, &b);

	swap(&a, &b);

	printf("%i %i\n", a, b);
}
