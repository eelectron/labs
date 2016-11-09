#include<stdbool.h>
/*
This program creates a min heap of given numbers.
*/

int *pq;	//points to array of vertices
int N ;
int i = 1;	//new item will be inserted at i
		//first item will be inserted at index 1 not at 0
		//for simplifying calc of parent and child position.

void initializeMinPQ(int n){
	N = n;
	pq = (int *)malloc( N*sizeof(int) );
}

/*
Returns true if priority queue is empty.
*/
bool isEmpty(){
	return i == 1;
}

void swim(int c){
	int p = c/2;
	int t;
	while(p >= 1 && pq[c] < pq[p]){
		t = pq[c];
		pq[c] = pq[p];
		pq[p] = t;

		c = p;	//parent becomes child
		p = c/2;	
	}
}

void sink(int p){
	int c = 2*p;
	int t;
	while(c < i){
		//select smaller child 
		if(c+1 < i && pq[c+1] < pq[c])
			c = c+1;

		//swap if min heap property violates
		if(pq[c] < pq[p]){
			t = pq[c];
			pq[c] = pq[p];
			pq[p] = t;
		}
		p = c;
		c = 2*p;		
	}
}

int delMin(){
	if(isEmpty() == true){
		printf("PQ is empty.");
		return -1;
	}

	int min = pq[1];	//min will always at index 1
	i--;			//location of last item

	//swap min item with last item
	int t = pq[1];
	pq[1] = pq[i];
	pq[i] = t;
	sink(1);
	return min;	
}

void insert(int n){
	if(i == N){
		printf("PQ is full.");
		return;
	}
	pq[i] = n;
	swim(i);	//swim to its correct position in heap
	i++;
}
