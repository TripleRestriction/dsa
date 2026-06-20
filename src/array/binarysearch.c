#include <stdio.h>

int binarySearch(int arr[], int size, int value){
	int high = size - 1, low = 0, mid;
	while(low <= high){
		mid = (high + low)/2;
		if(arr[mid] == value){
			printf("We found the value:%d at index:%d\n", value, mid);
			return mid;
		}
		else if(arr[mid] < value){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	printf("value not found\n");
	return -1;
}

int main(int argc, char *argv[])
{
	int arr[] = {1, 3, 4, 6, 9, 48, 56, 67, 95};
	int size = 9, value = 6;
	binarySearch(arr, size, value);
	return 0;
}
