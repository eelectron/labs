/*
Binary search
*/

int binarySearch(int a[], int lo, int hi, int x){
	int mid ;
	
	while(lo <= hi){
		mid = (lo+hi)/2;
		if(a[mid] == x)
			return mid;
		else if(x < a[mid])
			hi = mid-1;
		else
			lo = mid+1;
	}
	return -1;
}
