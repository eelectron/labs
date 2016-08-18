/*
1 2 3 4...
  1 2 3...
    1 2...
      1
*/
#include<stdio.h>
#include "countDigit.c"

void picture(int row){
	int width = countDigit(row);
	for(int i=0; i<row; i++){
		//print space
		for(int j=0; j<i; j++){
			printf("%*c ", width, 32);
		
		}
			
		//print num
		for(int j=1; j<=row-i; j++){
			printf("%*i ",width,j);
		}
			
		
			
		//print newline
		printf("\n");
	}
}

void main(){
	int n;
	printf("Enter a positve int:");
	scanf("%i", &n);
	picture(n);
}
