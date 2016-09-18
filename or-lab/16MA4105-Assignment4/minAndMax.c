/* This program prints the min and max item of a matrix
   together with its position.
*/


/*
Input: A matrix with its row and col. count.
Output: min item with its position,
		max item with its position.
*/
void minAndMax(double **m, int r, int c){
	int min = m[0][0],p=0,q=0;
	int max = m[0][0],s=0,t=0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(m[i][j] < min){		//finding min
				min = m[i][j];
				p = i;
				q = j;
			}
			
			if(m[i][j] > max){		//finding max
				max = m[i][j];
				s = i;
				t = j;
			}
		}
	}
	
	printf("Minimum item = %i at %i, %i\n", min, p, q);
	printf("Maximum item = %i at %i, %i\n", max, s, t);
}
