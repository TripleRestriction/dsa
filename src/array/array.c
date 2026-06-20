#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t totalSize;
	size_t usedSize;
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
	if (index > a->totalSize-1) {
		printf("Can't insert more than allocation.\n");
		exit(1);
	}
	if (a->usedSize < a->totalSize && index <= a->usedSize) {
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
		printf("ERROR: Can't insert\n");
		printf("used size: %lu ", a->usedSize);
		printf("total size: %lu ", a->totalSize);
		printf("index: %lu ", index);
		exit(1);
	}
}

void insertChangeOrder(myArray *a, int value, size_t index){
	if (index > a->usedSize) {
		printf("Can't insert \n");
		exit(1);
	}
	a->ptr[(a->usedSize)] = a->ptr[index]; // put at the end AFTER the last element
	a->ptr[index] = value;
	a->usedSize++;
}

int main(int argc, char *argv[]){
	myArray array;
	createArray(&array, 4, 0);

	insertionMaintainOrder(&array, 1, 0);
	showArray(&array);

	insertionMaintainOrder(&array, 2, 1);
	showArray(&array);
	insertionMaintainOrder(&array, 3, 2);
	showArray(&array);
	insertionMaintainOrder(&array, 4, 3);
	showArray(&array);
	insertionMaintainOrder(&array, 5, 0);
	showArray(&array);
	return 0;
}
