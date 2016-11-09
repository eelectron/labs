/*
This program counts the frequency of each item in a given matrix.

*/
#include<stdlib.h>
struct freq{
	double data;	//matrix item
	int frq;	//its frequency
	struct freq *next;
};

/*
Its a simple hash function.
Input: x, a Matrix item
Output: integer value corresponding to x.
*/
int hash(double x, int n){
	int h = ((int)abs(x))%n;
	return h;
}

/*
Inserts a given matrix item into hashtable. 
*/
void insert(struct freq * ht[], int n, double x){
	int h = hash(x, n);	//insert x at index h
	struct fr *curNode = ht[h];	//curNode points to first node at index h
	
	while(curNode != NULL){		//if item already present in HT, then simply update its freq and return

		if(curNode->data == x){
			curNode->freq++;	//update frequency
			return;
		}
		curNode = curNode->next;
	}	
		//create new node
		struct freq *new = (struct freq *)malloc(sizeof(struct freq));
		new->data = x;
		new->freq = 1;

		//put it as a first node
		new->next = ht[h];
		ht[h] = new;
}

/*
Input: Matrix M of rxc dimension
Output: prints how many times each item occurs in M.
*/
void frequency(double **m, int r, int c){
	struct freq * hashtable[r*c];	//stores matrix item with their frequencies
	for(int i=0; i<r*c; i++)
		hashtable[i] = NULL;

	//insert each item in hashtable
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			insert(hashtable, r*c, m[i][j]);
		}
	}

	//print frequency
	struct freq *node;
	for(int i=0; i<r*c; i++){
		node = hashtable[i];
		while(node != NULL){
			printf("freq of %lf = %i \n",node->data, node->freq);
			node = node->next;	
		}
	}
}
