#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int partition_r(int arr[], int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(&arr[random], &arr[high]);
    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_r(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n = 10000;
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i=0; i<n; i++) arr[i] = rand() % 10000;

    printf("Algorithm: Randomized Quick Sort\n");
    
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Sorted first 10 elements: ");
    for(int i=0; i<10; i++) printf("%d ", arr[i]);
    printf("\nExecution time: %f seconds\n", time_taken);
    printf("Design Strategy: Divide and Conquer (Randomized)\n");
    printf("Time Complexity: O(n log n) average, O(n^2) worst-case\n");

    free(arr);
    return 0;
}
