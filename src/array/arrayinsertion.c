#include <stddef.h>
#include <stdio.h>

void display(int arr[], size_t n){
	for (size_t i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int indInsertion(int arr[], size_t size, int value, size_t capacity, size_t index){
	if(size >= capacity){
		return -1;
	}
	for (size_t i = size-1; i >= index; i--) {
		arr[i+1] = arr[i];
	}
	arr[index] = value;
	return 1;
}

int main(int argc, char *argv[])
{
	int arr[100] = {7, 8, 12, 27, 88};
	size_t size = 5, capacity = 100;
	int element = 45, index = 3;
	display(arr, size);
	indInsertion(arr, size, element, capacity, index);
	size += 1;
	display(arr, size);
	return 0;
}
