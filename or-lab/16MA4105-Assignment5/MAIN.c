#include <stdio.h>
#include <stdlib.h>
#include "Floyd.c"
#include "printAndScanMatrix.c"
#define INF 100000000

#include "Dijkstra.c"
/* Unit testing Floyd warshall's all pair shortest path.
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
void main(int argc, char *argv[]){
	if(argc != 2){
		printf("Please run your program as : ./a.out graph.txt \n"
			", where in graph.txt's first line gives total no. vertex in graph,\n"
			 " second line gives src vertex , \n"
			" destination vertex and rest of lines give edges with their weights.\n");
		return ;
	}

	init(argv[1]);	//pass graph.txt file t init	
}
