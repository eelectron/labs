/* input: two positive integer.
   output: returns greatest common divisor of given two num.
   Ex: gcd(12, 8) = 4 
   Here, the main idea is that if n completely divides m
   then n is our GCD but if not then we will find 
   gcd of n & m%n because gcd(m, n) = gcd(n, m%n);
*/
int gcd(int m, int n){
	int rem = m%n;
	while(rem != 0){
		m =n;		//new m
		n = rem;	//new n
		rem = m%n;	//again find their rem
	}	
	return n;
}
