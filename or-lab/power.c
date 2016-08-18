#include<stdlib.h>

double power(double base, int exponent){
	double value = 1;
	int n = abs(exponent);	//make exponent positive

	for(int i=1; i<=n; i++)
		value *= base;

	if(exponent >= 0)
		return value;
	else
		return 1.0/value;
}
