#include<stdio.h>

int gcd(int m, int n){
	if(n%m == 0)
		return m;
	else
		return gcd(n%m, m);	
}

void main(){
	int m,n;
	printf("Enter two positive no.");
	scanf("%i %i", &m, &n);
	printf("%i\n", gcd(m, n));
}
