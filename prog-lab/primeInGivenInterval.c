/*
Find all prime numbers between given interval.
Example: lb=9 , ub=20
primes: 11, 13, 17, 19 .

compile : gcc -std=c99 primeInGivenInterval.c -lm 
*/

#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool isPrime(int n){
	//1 is not prime
	if(n == 1)
		return false;

	for(int i=2; i<=sqrt(n); i++){
		if(n%i == 0){
                        //n is not a prime
			return false;
                }
	}
        
        //n is prime
        return true;
}


void primeInInterval(int lb, int ub){
	for(int i = lb; i <= ub; i++){
		if(isPrime(i) == true)
			printf("%i ",i);
	}
	printf("\n");
}

void main(){
	int lb,ub;

	printf("Enter your interval.\n");
	
	printf("Give your lower bound:");
	scanf("%i",&lb);

	printf("Give your upper bound:");
	scanf("%i",&ub);

	primeInInterval(lb, ub);
} 
