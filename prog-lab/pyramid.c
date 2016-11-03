/*
Prints the below pattern:
       *
      * * 
     * * * 
    * * * *

*/

/*
Input no. of rows to print.
*/
void pyramid(int row){
	int width = row/10;

	for(int i=1; i<=row; i++){
		//print space
		for(int j=1; j<=row-i; j++ )
			printf(" ");
		
		//print *
		for(int j=1; j <= i; j++){
			printf("* ");	
		}

		//print new line after each row
		printf("\n");
	}
}
