#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    return i + 1;
}

void shellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void heapify(int arr[], int size, int root) {
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != root) {
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
    for (int i = size - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int getMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int size) {
    int max = getMax(arr, size);
    int count[max + 1];

    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    int output[size];
    int outputIndex = 0;

    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            output[outputIndex] = i;
            outputIndex++;
            count[i]--;
        }
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

int getMaxDigits(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int digits = 0;
    while (max > 0) {
        max /= 10;
        digits++;
    }
    return digits;
}

void radixSort(int arr[], int size) {
    int maxDigits = getMaxDigits(arr, size);
    int exp = 1;
    for (int i = 0; i < maxDigits; i++) {
        countingSort(arr, size, exp);
        exp *= 10;
    }
}

void countingSort(int arr[], int size, int exp) {
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void bucketSort(int arr[], int size, int numOfBuckets) {
    if (numOfBuckets <= 0) {
        printf("Invalid number of buckets.\n");
        return;
    }

    int max = getMax(arr, size);
    int min = getMin(arr, size);

    int range = (max - min) / numOfBuckets + 1;

    int buckets[numOfBuckets][size];
    int bucketSize[numOfBuckets];

    for (int i = 0; i < numOfBuckets; i++) {
        bucketSize[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = (arr[i] - min) / range;
        if (bucketIndex >= numOfBuckets) {
            bucketIndex = numOfBuckets - 1;
        }
        buckets[bucketIndex][bucketSize[bucketIndex]] = arr[i];
        bucketSize[bucketIndex]++;
    }

    int index = 0;
    for (int i = 0; i < numOfBuckets; i++) {
        insertionSort(buckets[i], bucketSize[i]);
        for (int j = 0; j < bucketSize[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int getMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
