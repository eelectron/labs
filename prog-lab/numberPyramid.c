/*
Prints the below pattern:
		1
      1 2 1
    1 2 3 2 1
  1 2 3 4 3 2 1

*/

/*
Input no. of rows to print.
*/
void pattern(int row){
	int width = row/10 + 1;

	for(int i=1; i<=row; i++){
		//print space
		for(int j=1; j<=row-i; j++ )
			printf("%*c ", width, ' ');
		
		//print no. till mid
		for(int j=1; j<=i; j++){
			printf("%*i ", width, j);	
		}

		//print after mid
		for(int j=i-1; j>=1; j--){
			printf("%*i ", width, j);	
		}

		//print space
		for(int j=1; j<=row-i; j++ )
			printf("%*c ",width, ' ');

		
		//print new line
		printf("\n");
	}
}
