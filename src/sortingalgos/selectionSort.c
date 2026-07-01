// finds lowest element in the array and brings it top the top
// O(n^2); not stable; not adaptive
// [3, 8, 1, 5, 0]: first the algorithm takes 3 and compares it with all the
// element,when it finds the lowest value it swaps


#include <stddef.h>
#include <stdio.h>

void printArray(int *array, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, size_t size)
{
    size_t indexOfMin;
    int temp = 0;
    for (size_t i = 0; i < size - 1; i++) { // size - 1 because last element is already sorted
        indexOfMin = i;
        for (size_t j = i + 1; j < size; j++) {
            if (arr[j] < arr[indexOfMin]) {
		indexOfMin = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[indexOfMin];
	arr[indexOfMin] = temp;
    }
}

int main()
{
    int a[] = {12, 54, 65, 7, 23, 9};
    printArray(a, 6);
    selectionSort(a, 6);
    printArray(a, 6);
}
