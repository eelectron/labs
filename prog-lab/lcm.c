#include<stdio.h>
#include<stdbool.h>
/*This function returns the lcm of two positive integer.
  For ex. lcm of 7 and 12 is 84*/
int lcm(int m, int n){
	
	int lcm=n,i=1;
	while(true){
		//got our LCM :)
		if(lcm%m == 0)
			return lcm;
		i++;
		lcm = n*i;	//next multiple of n
	}
}


void main(){
	int m,n,tmp;
	printf("Enter two integer:");
	scanf("%i%i",&m,&n);
	if(m>n){
		tmp = m;
		m = n;
		n  = tmp;
	}
	
	int val = lcm(m, n);
	printf("%i\n",val);
	
}
