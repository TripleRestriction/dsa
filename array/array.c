#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int totalSize;
	int usedSize;
	int *ptr;
} myArray;

void createArray(myArray *a, size_t tSize, size_t uSize){
	a->totalSize = tSize;
	a->usedSize= uSize;
	a->ptr = (int *)malloc(tSize*sizeof(int));
}

int main(int argc, char *argv[]){
	myArray array;
	createArray(&array, 100, 20);
	return 0;
}
