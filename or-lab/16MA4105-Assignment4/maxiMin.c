/*
This program finds the maximum and minimum of each row with its position.
Then it also finds maxmin and minmax.
*/



/*
Returns: index of max item.
*/		
int maxiMin(struct item mins[], int n){
	int max = mins[0].data;		//initial max
	int index = 0;
	for(int i=0; i<n; i++){
		if(mins[i].data > max){
			max = mins[i].data;
			index = i;		//remember the index of max item
		}
	}
	return index;
}
