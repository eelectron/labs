

int isUpperTriang(double **m, int dim){
	for(int i=0; i<dim; i++)
		for(int j=0; j<dim; j++)
			if(i>j && m[i][j] != 0)
				return 0;

	return 1;				
}
