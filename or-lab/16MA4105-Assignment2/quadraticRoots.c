#include<math.h>

/*
  This function takes the coefficients of quadratic equation
	returns its roots and tells whether its real or imaginary!!
  input:  a=1,b=2,c=1
  output: roots are: -1,-1	
*/
void quadraticRoots(int a, int b, int c){
	int discriminant = b*b - 4*a*c;		//cal. discri.
	
	float rp = (float)-1*b/2*a ; 		//real part ,which is common for real and complex roots
	float ip = 0;				//imaginary part
	if(discriminant >= 0){
		printf("roots are real\n");
		ip = sqrt(discriminant)/2*a;
		printf("%.3f	%.3f\n", rp+ip, rp-ip);
	}
	else{
		printf("roots are imaginary\n");
		ip = sqrt(-1*discriminant)/2*a;
		printf(" %1$.2f + i%2$.2f,	%1$.2f - i%2$.2f\n", rp, ip);
		
	}	
}
