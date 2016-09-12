#include<stdio.h>
#include "getString.c"

void strrev(char *s){
	int n = strlen(s);
	for(int i=n-1; i>=0; i--)
		printf("%c", s[i]);
	printf("\n");
}


void main(){
	char *str = getString();
	strrev(str); '\n'	
}
