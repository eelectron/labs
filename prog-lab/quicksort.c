
void exch(int a[], int i, int j){
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}


int partition(int a[], int lb, int ub){
	int v= a[lb];		//first item of array is pivot
	int i = lb+1, j = ub;
	
	while(1){
		while(a[i] <= v){
			i++;
			if(i > ub)break;
		}
		
		while(a[j] >= v){
			j--;
			if(j < lb+1)break;
		}
		
		if(i >= j)break;
		
		//exchange i and j
		exch(a, i, j);	
	}
	
	//exchange lb-1 , j
	exch(a, lb, j);
	
	return j;
}


void quicksort(int a[], int lb, int ub){
	if(lb >= ub)
		return;
	
	int p = partition(a, lb, ub);
	
	quicksort(a, lb, p-1);
	quicksort(a, p+1, ub);
}
