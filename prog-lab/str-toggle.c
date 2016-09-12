#include<stdio.h>
#include<ctype.h>
#include "getString.c"

void strToggle(char *s){
	int n = strlen(s);
	for(int i=0; i < n; i++){
		if(islower(s[i]))
			printf("%c", toupper(s[i]));
		else
			printf("%c", tolower(s[i]));
	}
	printf("\n");
}


void main(){
	char *str = getString();
	strToggle(str); 	
}
