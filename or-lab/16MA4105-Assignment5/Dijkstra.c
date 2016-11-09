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

	edge->nextEdge = graph[u];
	graph[u] = edge;
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
	if( distTo[u] + e->weight < distTo[v] ){
		distTo[v] = distTo[u] + e->weight;
		edgeTo[v] = *e;
		insert(v);
	}
}

void Dijkstra(int s){
	insert(s);
	while(!isEmpty()){
		int u = delMin();
	
		//perform relax operation on each edge adjacent to vertex u
		de *e = adj(u);
		while(e != NULL){
			relax(e);
			e = e->nextEdge;
		}
	}
}

/*
Prints shortest path from src to given vertex v.
*/
void pathTo(int dtn){
	int v = dtn;
	int top=0;
	de path[V];	
	de tempEdge ;
	//trace path from destination vertex v to source vertex src.
	while(v != src){
		tempEdge = edgeTo[v];
		if(tempEdge.u ==0 && tempEdge.v == 0){
			printf("Vertex %i, is not reachable from src %i.\n", v, src);
			return;
		}
		path[top++] = tempEdge;
		v = tempEdge.u;		//previous vertex
	}
	//print path
	printf("Shortest path from %i to %i is:\n", src, dtn);
	for(int i=--top; i>=0; i--)
		printf("%i -> %i  ",path[i].u, path[i].v );
	printf("\n");
}

/*
Prints graph as adjacency list.
*/
void printGraph(){
	printf("Graph: \n");
	for(int i=0; i<V; i++){
		printf("%i  ",i);
		de *cursor = graph[i];
		printf("\n");
		while(cursor){
			printf("%i->%i,%lf  ", cursor->u, cursor->v, cursor->weight);
			cursor = cursor->nextEdge;
		}
	}
}

/*
	START
This function setup Graph and Minimum Priority Queue.
*/
void init(char *graph){
	FILE *file = fopen(graph,"r");
	int V,src,dtn;
        fscanf(file,"%i %i %i", &V, &src, &dtn); 
            
        initialize(V,src);	//init graph
        initializeMinPQ(V+1);   //init min pq
            
        //build graph
        int u,v,weight;
        while(fscanf(file, "%i %i %i", &u, &v, &weight) != EOF){
                addEdge(u, v, weight);
        }              
        printGraph();
        Dijkstra(src);
        pathTo(dtn);
}
