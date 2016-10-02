/*
This program prints the first n terms of fibonacci series.
For n=5
0 1 1 2 3
*/

void fibonacci(int n){
	if(n == 1){
		printf("0 ");
		return;
	}
	
	if(n >= 2){
		printf("0 1 ");
	}

	int pt1 = 0, pt2 = 1, ct;
	for(int i = 3; i <= n; i++){
		ct = pt1 + pt2;		//sum of previous term
		printf("%i ", ct);
		
		pt1 = pt2;		//update prev terms
		pt2 = ct;
	}
}
