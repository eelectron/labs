#include<stdio.h>
#include<math.h>
#include<stdbool.h>

/*
This function takes a integer as input and returns true if itis a prime.
The main idea is if a integer is divisible by any integer
between 2 and sqrt(n) then its NOT A PRIME!
*/
bool isPrime(int n){
	for(int i=2; i<=sqrt(n); i++){
		if(n%i == 0){
                        //n is not a prime
			return false;
                }
	}
        
        //n is prime
        return true;
}

void main(){
	int x;
	printf("Enter a Integer:");
	scanf("%i",&x);

	bool a = isPrime(x);
        if(a == true)
                printf("%i is a prime. \n",x);
        else
                printf("%i is not a prime. \n",x);
}



