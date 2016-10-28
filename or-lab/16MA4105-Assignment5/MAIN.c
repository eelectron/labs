#include <stdio.h>
#include <stdlib.h>
#include "Floyd.c"
#include "printAndScanMatrix.c"
#define INF 100000000

#include "Dijkstra.c"
/* Floyd warshall's all pair shortest path.
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

*/

//Unit test Dijkstra
void main(){

	int V,s;
	printf("Enter no. of vertices and src vertex:");
	scanf("%i %i", &V, &s);
	
	initialize(V,s);
	
	//initialize Min PQ
	initializeMinPQ(V+1);
	
	//build graph
	int u,v,weight,e;
	printf("No of edges:");
	scanf("%i",&e);
	while(e != 0){
		scanf("%i %i %i", &u, &v, &weight); 
		addEdge(u,v,weight);
		e--;
	}
	
	printGraph();

	Dijkstra(s);
	pathTo(1);	
}
