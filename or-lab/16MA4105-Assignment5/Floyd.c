/*
This program computes the length of shortest path between all
pairs of vertices.
*/

void floyd(double** graph, int v){
	double sd[v][v];		//contains shortest distance b/w every pair of vertex
	int dist;

	for(int i=0; i<v; i++)		//simply copy graph[][] to sd[][]
		for(int j=0; j<v; j++)
			sd[i][j] = graph[i][j];  

	for(int k=0; k<v; k++)		//here k can be intermediate node of any two nodes say i and j
		for(int i=0; i<v; i++)
			for(int j=0; j<v; j++ ){
				dist = sd[i][k] + sd[k][j];		//dist bet. i,j with k as intermediate vertex
				if(dist < sd[i][j])
					sd[i][j] = dist;
			}

	for(int i=0; i<v; i++){		//print solution
		for(int j=0; j<v; j++){
			printf("%.2lf ",sd[i][j]);
		} 
		printf("\n");
	} 		
}
