#include<stdio.h>
#include "fibonacci.c"
#include "swap-xor.c"
#include "reversePyramid.c"
#include "printStar.c"
#include "quicksort.c"
#include "searching.c"


/*
void main(){
	int n;
	printf("How many terms of fibonacci you want:");
	scanf("%i", &n);
	
	fibonacci(n);
}
*/

/*
void main(){
	int a,b;
	printf("Enter two no.");
	scanf("%i %i", &a, &b);
	swap(&a, &b);
        printf("a= %i b=%i \n", a, b);
}
*/

/*
void main(){
	int h;
	printf("Enter height");
	scanf("%i",&h);
	printStar(h);
	revPyramid(h-1);
	
}
*/

/*Sort
void main(){
	int a[] = {4,1,2,8,9,7};
	int size = sizeof(a)/sizeof(a[0]);
	quicksort(a, 0, size-1);
	for(int i=0; i<size; i++)
		printf("%i ",a[i]);	
}
*/

//search
void main(){
	int a[] = {4,1,2,8,9};
	int size = sizeof(a)/sizeof(a[0]);
	quicksort(a, 0, size-1);
	for(int i=0; i<size; i++)
		printf("%i ",a[i]);
	
	int loc = binarySearch(a, 0, size-1, 4);
	printf("%i \n", loc);	
}
