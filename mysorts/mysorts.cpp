//
// Created by dmitr on 14.10.2023.
//

#include "mysorts.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

long long insertionSort(int arr[], int size) {
    long long comparisons = 0;
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            comparisons++;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

long long selectionSort(int arr[], int size) {
    long long comparisons = 0;
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            comparisons++;
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(&arr[i], &arr[min_index]);
        }
    }
    return comparisons;
}

long long bubbleSort(int *array, int n) {
    long long countComparison = 0;
    for (int i = 0; i < n - 1 && ++countComparison; ++i)
        for (int j = n - 1; j > 0 && ++countComparison; --j)
            if (array[j - 1] > array[j]

                && ++countComparison)
                swap(&array[j - 1], &array[j]);

    return countComparison;
}

long long bubbleSort1(int arr[], int size) {
    long long comparisons = 0;
    int swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
    return comparisons;
}

long long bubbleSort2(int *array, int n) {
    long long countComparison = 0;
    for (int i = 0; i < n - 1 && ++countComparison; ++i)
        for (int j = n - 1; j > i && ++countComparison; --j)
            if (array[j - 1] > array[j]

                && ++countComparison)
                swap(&array[j - 1], &array[j]);

    return countComparison;
}

long long shellSort(int arr[], int size) {
    long long comparisons = 0;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                comparisons++;
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return comparisons;
}

long long quickSort(int arr[], int n) {
    return quickSort(arr, 0, n);
}

long long quickSort(int arr[], int left, int right) {
    long long comparisons = 0;
    if (left < right) {
        int pivot = arr[left];
        int i = left;
        int j = right;
        while (i < j) {
            while (arr[i] <= pivot && i < right) {
                comparisons++;
                i++;
            }
            while (arr[j] > pivot) {
                comparisons++;
                j--;
            }
            if (i < j) {
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[left], &arr[j]);
        quickSort(arr, left, j - 1);
        quickSort(arr, j + 1, right);
    }
    return comparisons;
}

void heapify(int arr[], int size, int i, long long *comparisons) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
        (*comparisons)++;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
        (*comparisons)++;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest, comparisons);
    }
}

long long heapSort(int arr[], int size) {
    long long comparisons = 0;
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i, &comparisons);
    }
    for (int i = size - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0, &comparisons);
    }
    return comparisons;
}