/*
This program finds the optimum value of a LPP
given in matrix form.
For ex:
	Max z = 3x1 + 5x2
	 st
	x1			<= 4
	2x2			<= 12
	3x1	+ 2x2	<= 18
	
	soln - x1 = 2 , x2 = 6
	
	
	Convert constraint to equality
	z - 3x1 - 5x2					= 0
		x1        + x3 		 		= 4
		      2x2      +  x4  		= 12
		3x1 + 2x2            + x5 	= 18
*/

#include<stdio.h>

bool isOptimal(float **m, int p, int q){
	//check if optimal solution reached
	for(int i=0; i<q; i++){
		if(m[0][i] < 0){
			return false;
		}
	}
	return true;
}


/*
Returns index of entering var.
*/
int findEnteringVar(float **m, int p, int q){
	int i = 0;
	float minCoe = m[0][0];

	for(int j=0; j<q; j++){
		if(m[0][j] < minCoe){
			minCoe = m[0][j];
			i = j;
		}
	}
	return i;
}


/*
This function takes a LPP in matrix form with its dimension.
*/

bool simplex(float **m, int p, int q){
	int var[q];	//stores current position of basic var 
			//-1 at var[i] denote i'th var is currently non-basic
	
	int nbv = q - (p-1);		//no. of non basic var
	for(int i=0; i < nbv; i++)
		var[i] = -1;
	
	//initial basic var
	for(int i = nbv; i<q; i++)
		var[i] = i - nbv + 1;

	
	int ev;		//index of entering var
	int lv;		//index of leaving var
	while(!isOptimal(float **m, int p, int q)){
		//find entering var
		ev = findEnteringVar(float **m, int p, int q);

		//find index of leaving var
	}
		
	
}
