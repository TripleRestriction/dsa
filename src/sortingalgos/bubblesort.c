// bubble sort works on the concept of comparing adjacent values in an array
// so if the array is [2, 9, 3, 5, 1] it will compare {2, 9}
// since 2 < 9 hence their position remains intact
// however when the comparsion of {9, 3} happens, positions of these two
// elements will be swapped this will be done until we reach the end of array
// and will be repeated again this entire process will be done several times (n
// = number of passes), where n = size of array - 1 number of comparisons: n-1 +
// n-2 + n-3 + ... + 1 = n(n-1)/2 therefore time complexity is O(n^2) the
// algorithm is stable non adaptive algorithm, by default atleast; called bubble
// sort because smaller elements come to one side like bubbles come to the top
#include <stddef.h>
#include <stdio.h>

void printArray(int *array, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, size_t size)
{
    int temp;
    for (size_t i = 0; i < (size - 1); i++) { // passes -> happens size - 1 times
        for (size_t j = 0; j < (size - 1 - i); j++) { // comparison in each pass, runs size - 1 - i times
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
		arr[j+1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int *arr, size_t size)
{
    int temp;
    int isSorted = 0;
    for (size_t i = 0; i < (size - 1); i++) {
	isSorted = 1;
        for (size_t j = 0; j < (size - 1 - i); j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
		isSorted = 0; // the fact that the program reaches this condition means the array isn't sorted
            }
        }
        if (isSorted) {
	    return; // just end in the first run itself
        }
    }
}

int main()
{
    int a[] = {12, 54, 65, 7, 23, 9};
    int b[] = {1, 2, 3, 4, 5, 6};
    int c[] = {1, 2, 9, 4};
    size_t size = 6;
    printf("Printing the array before sorting: ");
    printArray(a, size);
    bubbleSort(a, 6);
    printf("Printing the array after sorting: ");
    printArray(a, size);

    printf("Printing the array before sorting: ");
    printArray(b, size);
    bubbleSortAdaptive(b, 6);
    printf("Printing the array after sorting: ");
    printArray(b, size);

    printf("Printing the array before sorting: ");
    printArray(c, 4);
    bubbleSortAdaptive(c, 4);
    printf("Printing the array after sorting: ");
    printArray(c, 4);
    return 0;
}
