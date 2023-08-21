#include <stdio.h>
#include <stdlib.h>
#include "sort_algorithms.h"

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {9, 52, 59, 80, 64, 89, 82, 78, 21, 32};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    int bubbleArr[size];
    for (int i = 0; i < size; i++) {
        bubbleArr[i] = arr[i];
    }
    bubbleSort(bubbleArr, size);
    printf("Bubble sorted array: ");
    printArray(bubbleArr, size);

    int selectionArr[size];
    for (int i = 0; i < size; i++) {
        selectionArr[i] = arr[i];
    }
    selectionSort(selectionArr, size);
    printf("Selection sorted array: ");
    printArray(selectionArr, size);

    int quickArr[size];
    for (int i = 0; i < size; i++) {
        quickArr[i] = arr[i];
    }
    quickSort(quickArr, 0, size - 1);
    printf("Quick sorted array: ");
    printArray(quickArr, size);

    int shellArr[size];
    for (int i = 0; i < size; i++) {
        shellArr[i] = arr[i];
    }
    shellSort(shellArr, size);
    printf("Shell sorted array: ");
    printArray(shellArr, size);

    int heapArr[size];
    for (int i = 0; i < size; i++) {
        heapArr[i] = arr[i];
    }
    heapSort(heapArr, size);
    printf("Heap sorted array: ");
    printArray(heapArr, size);

    int radixArr[size];
    for (int i = 0; i < size; i++) {
        radixArr[i] = arr[i];
    }
    radixSort(radixArr, size);
    printf("Radix sorted array: ");
    printArray(radixArr, size);

    int countingArr[size];
    for (int i = 0; i < size; i++) {
        countingArr[i] = arr[i];
    }
    countingSort(countingArr, size);
    printf("Counting sorted array: ");
    printArray(countingArr, size);

    int bucketArr[size];
    for (int i = 0; i < size; i++) {
        bucketArr[i] = arr[i];
    }
    bucketSort(bucketArr, size, 5);
    printf("Bucket sorted array: ");
    printArray(bucketArr, size);

    return 0;
}
