// O(n^2) total passes = n-1, total comparisons = 1+2+3+...+n-1 = n(n-1)/2
//<Sor|--UnSor->
// [7,| 1, 2, 11, 8]
// compare 1 with 7, interchange if 1 is less
// [1, 7,| 2, 11, 8] -> [1, 2, 7,| 11, 8]...etc
// stable algorithm; adaptive algorithm
#include <stddef.h>
#include <stdio.h>

void printArray(int *array, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void insertionSort(int *arr, size_t size)
{
    int key;
    size_t j;
    for (size_t i = 0; i < size - 1; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int a[] = {12, 54, 65, 7, 23, 9};
    printArray(a, 6);
    insertionSort(a, 6);
    printArray(a, 6);
}
