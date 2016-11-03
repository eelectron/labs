#include<stdio.h>
#include "pyramid.c"
#include "reversePyramid.c"

void main(){
	int h;
	scanf("%i",&h);
	reversePyramid(h);
}

/*
void main(){
	int n;
	printf("How many terms of fibonacci you want:");
	scanf("%i", &n);
	
	fibonacci(n);
}

*/
