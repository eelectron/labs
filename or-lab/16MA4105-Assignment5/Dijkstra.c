#include "MinPriorityQueue.c"
#include<limits.h>
/*
This program calculates the shortest path between two given
nodes of a directed graph.
*/

struct directedEdge{
	int u,v;
	double weight;
	struct directedEdge *nextEdge;
};

typedef struct directedEdge de;

int V; 		//total no. of vertex
int src;
de * *graph;	//DIRECTED GRAPH shown as adjacency list

int *distTo;	//distTo[v] is shortest path from s to v.
de *edgeTo;	//edgeTo[v] is last edge on shortest path from s to v.


/*
Initialize distTo[s] = 0 and other with INFINITY.
In our program INFINITY = INT_MAX.
*/

void initialize(int n, int s){
	V = n;
	src = s;

	//adjacency list
	graph = (de * *)malloc(V*sizeof(de *));
	distTo = (int *)malloc(V*sizeof(int));
	edgeTo = (de *)malloc(V*sizeof(de));

	for(int i=0; i<V; i++)
		distTo[i] = INT_MAX;
	distTo[s] = 0;
}


/*
Adds edge to digraph
*/
void addEdge(int u, int v, int weight){
	
	//create edge
	de  *edge =  (de *)malloc(sizeof(de));
	edge->u = u;
	edge->v = v;
	edge->weight = weight;

	de *temp = graph[u];
	graph[u] = edge;
	edge->nextEdge = temp;
}



/*
Returns adjacent edges to the given vertex.
*/
de * adj(int u){
	return graph[u];
}



/*
This function updates the distance of given vertex from 
src vertex, if the new distance is lesser than current one.
*/

void relax(de *e){
	int u = e->u, v = e->v;
	if(distTo[v] > distTo[u] + e->weight){
		distTo[v] = distTo[u] + e->weight;
		edgeTo[v].u = e->u;
		edgeTo[v].v = e->v;
		edgeTo[v].weight = e->weight;
		insert(v);
	}
}


void Dijkstra(int s){
	insert(s);
	while(!isEmpty()){
		int u = delMin();
		printf("min %i\n",u);
	
		//perform relax operation on each edge adjacent to vertex u
		de *e = adj(u);
		while(e != NULL){
			printf("relaxed %i->%i, %lf \n",e->u,e->v,e->weight);   
			relax(e);
			e = e->nextEdge;
		}
	}
}


/*
Prints shortest path from src to given vertex v.
*/
void pathTo(int v){
	int top=0;
	de path[V-1];	
	de tempEdge ;
	//trace path from destination vertex v to source vertex 0.
	while(v != src){
		tempEdge = edgeTo[v];
		path[top++] = tempEdge;
		v = tempEdge.u;		//previous vertex
	}

	//print path
	for(int i=--top; i>=0; i--)
		printf("%i -> %i  ",path[i].u, path[i].v );
	printf("\n");
}




void printGraph(){
	for(int i=0; i<V; i++){
		printf("%i  ",i);
		de *cursor = graph[i];
		while(cursor){
			printf("%i->%i,%lf  ", cursor->u, cursor->v, cursor->weight);
			cursor = cursor->nextEdge;
		}
		printf("\n");
	}
}
