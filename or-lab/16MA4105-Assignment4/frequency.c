/*
This program counts the frequency of each item in a given matrix.
*/
#include<stdlib.h>

struct fr{
	double data;	//matrix item
	int freq;	//its frequency
	struct fr *next;
};

int hash(double x, int n){
	int h = ((int)abs(x))%n;
	return h;
}

void insert(struct fr * ht[], int n, double x){
	int h = hash(x, n);	//insert x at index h
	struct fr *curNode = ht[h];	//curNode points to first node at index h
	
	while(curNode != NULL){

		if(curNode->data == x){
			curNode->freq++;	//update frequency
			return;
		}
		curNode = curNode->next;
	}	
		
		//create new node
		struct fr *new = (struct fr *)malloc(sizeof(struct fr));
		new->data = x;
		new->freq = 1;

		//put it as a first node
		new->next = ht[h];
		ht[h] = new;
}

void frequency(double **m, int r, int c){
	struct fr * hashtable[r*c];	//stores matrix item with their frequencies
	for(int i=0; i<r*c; i++)
		hashtable[i] = NULL;


	//insert each item in hashtable
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			insert(hashtable, r*c, m[i][j]);
		}
	}

	//print frequency
	struct fr *node;
	for(int i=0; i<r*c; i++){
		node = hashtable[i];
		while(node != NULL){
			printf("freq of %lf = %i \n",node->data, node->freq);
			node = node->next;	
		}
	}
}
