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

void showArray(myArray *a){
	printf("{");
	for (size_t i = 0; i < a->totalSize; i++){
		printf("%d", a->ptr[i]);
		printf(",");
	}
	printf("}\n");
}

void freeArray(myArray * a){
	free(a->ptr);
}

void insertionMaintainOrder(myArray *a, int value, size_t index){
	if (a->usedSize < a->totalSize && index <= (a->totalSize - 1)) {
		if (index > a->usedSize) {
			a->ptr[index] = value;
			a->usedSize++;
		}
		else {
			for (size_t i = 0; i <= a->usedSize; i++) {
				if (a->usedSize - i > index){
					a->ptr[a->usedSize - i] = a->ptr[a->usedSize - i - 1];
				}
				else {
					a->usedSize++;
					a->ptr[index] = value;
					break;
				}
			}
		}
	}
	else if (index > (a->totalSize - 1)){
		printf("ERROR: Can't add to index: %lu because requested index is out of bounds!\n", index);
		exit(1);
	}
	else{
		printf("ERROR: Can't insert more elements, allocation is full.\n");
		exit(1);
	}
}

void insertChangeOrder(myArray *a, size_t index, int value){
	a->ptr[(a->usedSize)] = a->ptr[index]; // put at the end AFTER the last element
	a->ptr[index] = value;
	a->usedSize++;
}

int main(int argc, char *argv[]){
	myArray array;
	createArray(&array, 10, 3);
	array.ptr[0] = 69;
	array.ptr[1] = 67;
	array.ptr[2] = 420;
	showArray(&array);
	insertionMaintainOrder(&array, 1337, 9);
	showArray(&array);

	return 0;
}
