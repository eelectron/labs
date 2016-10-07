
/* Gives factorial of given int
   For ex: 4! = 4*3*2*1 = 24
*/
int factorial(int x){
	int value = 1;
	while(x > 1){
		value = value*x;
		x--;
	}
	return value;
}
