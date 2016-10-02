/*
This program finds the maximum and minimum of each col with its position.
Then it also finds maxmin and minmax.
*/

#include "maxiMin.c"
#include "minMax.c"

void eachColMinMax(double **m, int r, int c){
	struct item mins[c];	//min of each col
	struct item maxs[c];	//max of each col
	

	for(int i=0; i<c; i++){
		//initial values for each row
		int min = m[0][i], p=0, q=i;
		int max = m[0][i], s=0, t=i;

		for(int j=0; j<r; j++){
			if(m[j][i] < min){	
				min = m[j][i];		
				p = j;
				q = i;
			}	
			
			if(m[j][i] > max){	
				max = m[j][i];		
				s = j;
				t = i;
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

		printf("col %i: min = %i at %i,%i \n", i, min, p, q);
		printf("col %i: max = %i at %i,%i \n", i, max, s, t);
	}
	
	int i = maxiMin(mins, r);	
	printf("maximin = %i, at %i,%i \n", mins[i].data, mins[i].i, mins[i].j);

	i = minMax(maxs, r);	
	printf("minMax = %i, at %i,%i \n", maxs[i].data, maxs[i].i, maxs[i].j);
}
