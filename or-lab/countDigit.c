int countDigit(int n){
	int i = 0;
	
	//run until n becomes zero
	while(n > 0){
		n /= 10;
		i++;
	}
	return i;
}
