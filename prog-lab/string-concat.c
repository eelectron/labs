/*
Take first name and last name from user and concatenate them.
Input: "prashant"
       "singh"
Output: "prashant singh"
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

/*
Get memory blocks and returns its starting address.
*/
void * resize(char *ptr, int *n){
	//new string of double capacity
	char *newStr = malloc(2*(*n)*sizeof(char));

	//copy old string to new place
	for(int i=0; i < *n; i++)
		newStr[i] = ptr[i];
	
	*n = (*n)*2;	//update the size

	return newStr;
}

/*
	Store string in "s" of length n.
*/
char * getString(){
	int size = 1;		//initial len of string
	char *s = malloc(1*sizeof(char));
	char c ;	
	int count = 0;
	printf("Enter a string:");
	while(true){
				
		if(count == size)
			s = resize(s, &size);		//increase size 

		scanf("%c", &c);

		if(c == '\n')
			break;

		s[count] = c;
		count++	;		//increment count
	}

	s[count] = '\0';	//end str with null

	return s;
}

/*
 Attach two str.
*/
char * concat(char *s, char *t){
	int m = strlen(s);
	int n = strlen(t);
	char *joinedStr = malloc( m + n + 1) ;
	
	int i;	
	for(i=0; i<m; i++)
		joinedStr[i] = s[i];
	
	int j;	
	for(j=m,i=0; j<m+n; j++,i++)
		joinedStr[j] = t[i];
	
	joinedStr[j] = '\0';
	return joinedStr; 
}
void main(){
		
	char *firstName, *lastName;
	firstName = getString();
	lastName = getString();
	printf("%s", concat(firstName, lastName));		
}
