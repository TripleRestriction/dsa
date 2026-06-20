#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void display(int arr[], size_t n){
	for (size_t i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void indDeletion(int arr[], size_t size, size_t index){
	if (index > size-1) {
		printf("ERROR: size > index\n");
		exit(1);
	}
	for(size_t i = index; i < size-1; i++){
		arr[i] = arr[i+1];
	}
}

int main(int argc, char *argv[])
{
	int arr[100] = {7, 8, 12, 27, 88};
	size_t size = 5, capacity = 100;
	int element = 45, index = 2;
	display(arr, size);
	indDeletion(arr, size, index);
	size--;
	display(arr, size);
	return 0;
}
