/*
This program finds the maximum and minimum of each row with its position.
Then it also finds maxmin and minmax.
*/
#include "maxiMin.c"
#include "minMax.c"


void eachRowMaxMin(double **m, int r, int c){
	struct item mins[r];	//min of each row
	struct item maxs[r];	//max of each row
	

	for(int i=0; i<r; i++){
		//initial values for each row
		int min = m[i][0], p=i, q=0;
		int max = m[i][0], s=i, t=0;

		for(int j=0; j<c; j++){
			if(m[i][j] < min){	
				min = m[i][j];		
				p = i;
				q = j;
			}	
			
			if(m[i][j] > max){	
				max = m[i][j];		
				s = i;
				t = j;
			}	
				
		}

		//save min 
		mins[i].data = min;
		mins[i].i = p;
		mins[i].j = q;
			
		//save max
		maxs[i].data = max;
		maxs[i].i = s;
		maxs[i].j = t;

		printf("row %i: min = %i at %i,%i \n", i, min, p, q);
		printf("row %i: max = %i at %i,%i \n", i, max, s, t);
	}
	
	int i = maxiMin(mins, r);	
	printf("maximin = %i, at %i,%i \n", mins[i].data, mins[i].i, mins[i].j);

	i = minMax(maxs, r);	
	printf("minMax = %i, at %i,%i \n", maxs[i].data, maxs[i].i, maxs[i].j);
}
