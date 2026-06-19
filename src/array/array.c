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

void showArray(myArray * a){
	for (size_t i = 0; i < a->usedSize; i++){
		printf("%d\n", a->ptr[i]);
	}
}

void freeArray(myArray * a){
	free(a->ptr);
}

int main(int argc, char *argv[]){
	myArray array;
	createArray(&array, 10, 2);
	array.ptr[0] = 69;
	array.ptr[1] = 67;
	showArray(&array);
	freeArray(&array);
	return 0;
}
