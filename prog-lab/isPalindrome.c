#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool isPalindrome(char *string){
	int n = strlen(string);
	int ub = n-1;
	
	for(int i=0; i<n/2; i++,ub--){
		if(string[i] != string[ub]){
			return false;
		}
	}
	return true;
}

void main(){
	char s[20];
	printf("Enter a word: ");
	scanf("%s",s);
	
	if(isPalindrome(s))
		printf("%s is a PALINDROME.\n",s);
	else
		printf("%s is not a PALINDROME.\n",s);
}
