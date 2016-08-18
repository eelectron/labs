/*This function printf the terms of fibonacci series upto given n.
 Input : no. of terms you want .
 Output: prints first n terms of fibonacci series.*/
void fibonacci(int n){
	if(n == 0)
		return;
	if(n == 1){
		printf("0\n");
		return;
	}
	
	if(n >= 2){
		printf("0 1 ");
	}

	int a=0,b=1,c;
	for(int i=3; i<=n; i++){
		c=a+b;
		printf("%i ",c);
		a=b;
		b=c;
	}
}
