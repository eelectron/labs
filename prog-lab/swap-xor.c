
/*
Input: address of two var.
Output: swaps their content using XOR.
*/
void swap(int *a, int *b){
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
