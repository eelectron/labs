
/*
Returns: index of min item.
*/		
int minMax(struct item maxs[], int n){
	int min = maxs[0].data;		//initial min
	int index = 0;
	for(int i=0; i<n; i++){
		if(maxs[i].data < min){
			min = maxs[i].data;
			index = i;		//remember the index of min item
		}
	}
	return index;
}
