/*
	* * * * *
	 * * * *
	  * * *
	   * *
        *
*/

void revPyramid(int height){
	for(int r=0; r<height; r++){
		//space
		for(int c=1; c<=r; c++)
			printf(" ");
		
		//*
		for(int c=1; c <= height-r; c++)
			printf("* ");
		
		//space
		for(int c=1; c<=r; c++)
			printf(" ");

		printf("\n ");
	}
}
