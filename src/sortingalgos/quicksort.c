// divide and conquer or something
#include <stddef.h>
#include <stdio.h>

void printArray(int *array, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

size_t partition(int *arr, size_t low, size_t high)
{
    int pivot = arr[low];
    size_t i = low + 1;
    size_t j = high;
    int temp = 0;
    do {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (j > low && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int *arr, size_t low, size_t high)
{
    if (low < high) {
        size_t partitionIndex = partition(arr, low, high);
        if (partitionIndex > low) {
            quickSort(arr, low, partitionIndex - 1);
        }
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    int a[] = {12, 54, 65, 7, 23, 9};
    printArray(a, 6);
    quickSort(a, 0, 5);
    printArray(a, 6);
}
