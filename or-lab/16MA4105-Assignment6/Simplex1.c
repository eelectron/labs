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

/*
Check if current table is optimal .
*/
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
Returns index of leaving var using minimum ratio test.
Returns -1 , if no leaving var is present.
*/
int findLeavingVar(float **m, int p, int q, int ev){
	float min = INT_MAX;
	int index = -1;	
	//iterate vertically starting with index 1
	for(int i=1; i<p; i++){
		//item must be  > 0 
		if(m[i][ev] > 0){
			//get ratio
			float ratio = m[i][q-1]/m[i][ev];
			if(ratio < min){
				min = ratio;
				index = i;
			}
		}
	}
	return index;
}

/*
Save entering var in basic var array.
*/
void saveEnteringVar(int bv[], int p, int ev , int lv){
	int pos;	
	for(int i=1; i<p; i++){
		if(bv[i] == lv){
			bv[i] = ev;
			pos = i;
		}		
	}

	return pos;
}


/*
This function takes a LPP in matrix form with its dimension.
*/

bool simplex(float **m, int p, int q){
	int var[q];	//stores current position of basic var 
			//-1 at var[i] denote i'th var is currently non-basic
	
	int nbv = q - (p-1);		//no. of non basic var

	//array of basic var
	int bv[p];

	//initial basic var
	for(int i = 1; i<p; i++)
		bv[i] = i + nbv - 1;

	
	int ev;		//index of entering var
	int lv;		//index of leaving var
	while(!isOptimal(float **m, int p, int q)){
		//find entering var
		ev = findEnteringVar(**m, p, q);

		//find index of leaving var
		lv = findLeavingVar(**m, p, q, ev);

		//save ev in basic var array
		int row = saveEnteringVar(bv, ev, lv);

		//reduce using row
		
	}	
}
