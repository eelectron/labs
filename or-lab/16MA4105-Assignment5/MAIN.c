#include <stdio.h>
#include <stdlib.h>
#include "Floyd.c"
#include "printAndScanMatrix.c"
#define INF 100000000
void main(){
	double **graph;
	int m,n;
	printf("Enter m = ");
	scanf("%i", &m);
	
	printf("Enter n = ");
	scanf("%i", &n);
	
	//get space
	graph = malloc(m*sizeof(double *));
	for(int i=0; i<m; i++)
		graph[i] = malloc(n*sizeof(double));
		
	scanMatrix(graph, m, n);

	floyd(graph, m);
}
