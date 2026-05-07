#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
        
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n = 10000; // Size of array
    int *arr = (int*)malloc(n * sizeof(int));
    
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
    
    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();
    
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Merge Sort Completed.\n");
    printf("First 10 sorted elements: ");
    for(int i = 0; i < 10; i++) printf("%d ", arr[i]);
    printf("...\n");
    
    printf("Execution time for %d elements: %f seconds\n", n, time_taken);
    printf("Design Strategy: Divide and Conquer\n");
    printf("Time Complexity: O(n log n)\n");
    
    free(arr);
    return 0;
}
