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
	FILE *fp = fopen("graph2.txt","r");
	if(fp == NULL){
		printf("Not able to read file.");
		return ;
	}
	printf("Enter no. of vertices and src vertex:");
	fscanf(fp,"%i %i", &V, &s);
	
	initialize(V,s);
	
	//initialize Min PQ
	initializeMinPQ(V+1);
	
	//build graph
	int u,v,weight;
	while(fscanf(fp,"%i %i %i",&u,&v,&weight) != EOF){
		addEdge(u,v,weight);
	}
	
	printGraph();

	Dijkstra(s);
	pathTo(2);	
}
