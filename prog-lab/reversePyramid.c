/*
	* * * * *
	 * * * *
	  * * *
	   * *
            *
*/

void reversePyramid(int height){
	for(int r=0; r<height; r++){
		//space
		for(int c=0; c<r; c++)
			printf(" ");
		
		//*
		for(int c=1; c <= height-r; c++)
			printf("* ");
		
		printf("\n");
	}
}
