#include "pyramid.c"
#include "reversePyramid.c"

void diamond(int height){
	pyramid(height);
	printf(" ");
	reversePyramid(height-1);
}
