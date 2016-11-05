/*
This program finds the optimum value of a LPP
given in matrix form.
For ex:
	Max z = 3x0 + 5x1
	 st
	x0			<= 4
	2x1			<= 12
	3x0	+ 2x1	<= 18
	
	soln - x0 = 2 , x1 = 6
	
	
	Convert constraint to equality
	z - 3x0 - 5x1					= 0
		x0        + x2 		 		= 4
		      2x1      +  x3  		= 12
		3x0 + 2x1            + x4 	= 18
		
	The initial table corresponding to above LPP,
	which will be used to start simplex process is as below
	-3	-5	0	0	0	0
	1	0	1	0	0	4
	0	2	0	1	0	12
	3	2	0	0	1	18
*/

#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#include<math.h>
#include "in-out.c"
/*
Check if current table is optimal .
*/
bool isOptimal(double **m, int p, int q){
	float small = -0.00001;
	//check if optimal solution reached
	for(int j=0; j<q-1; j++){
		if(m[0][j] < small){
			return false;
		}
	}
	return true;
}


/*
Returns index of entering var.
*/
int findEnteringVar(double **m, int p, int q){
	int i = 0;		//index of largest absolute coefficient of var
	float minCoe = m[0][0];		//intialize min coe

	for(int j=0; j<q-1; j++){
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
int findLeavingVar(double **m, int p, int q, int ev){
	float min = INT_MAX;		//minimum ratio among all
	int index = -1;				//
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
int saveEnteringVar(int bv[], int p, int ev , int lv){
	bv[lv] = ev;
	return lv;
}


/*
	This function reduces other rows using r'th row.
*/
void reduce(double **m, int row, int col, int p, int q){
	//pivot
	double pivot = m[p][q];

	//divide r'th row by m[r][r]	
	for(int j=0; j<col; j++)
		m[p][j] = m[p][j]/pivot;
	
	
	for(int i=0; i<row; i++){
		//reduce other rows leaving given row p.
			if(i != p){
				float term = m[i][q];		//coefficient of var which must be made to zero
				for(int j=0; j<col; j++){
					m[i][j] = m[i][j] - m[p][j]*term;
					if(m[i][j] == 0.0)
						m[i][j] = 0.0;		//save -0.0 as 0.0
				}
			}	
	}
}



/*
This function takes a LPP in matrix form with its dimension.
*/

bool simplex(double **m, int p, int q){	
	int nbv = (q-1) - (p-1);		//no. of non-basic var

	//stores current basic var
	int bv[p];

	//initial basic var
	for(int i = 1; i<p; i++)
		bv[i] = (i-1) + nbv;

	
	int ev;		//index of entering var
	int ilv;		//index of leaving var
	while(!isOptimal(m, p, q)){
		//find entering var
		ev = findEnteringVar(m, p, q);

		//find index of leaving var
		ilv = findLeavingVar(m, p, q, ev);
		
		printf("\n ev = %i  ilv = %i \n", ev , ilv);
		
		//save ev in basic var array
		saveEnteringVar(bv, p, ev, ilv);

		//reduce using row
		reduce(m, p, q, ilv, ev);
		
		//print table after each reduction
		printMatrix(m, p, q);	
	}	
	
	//values of final basic variables
	for(int i=1; i<p; i++){
		printf("x%i = %lf\n", bv[i], m[i][q-1]);
	}
	
	//Z value
	printf("Z = %lf\n",m[0][q-1]);
}
