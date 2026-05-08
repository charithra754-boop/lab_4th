#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Returns the number of inversions found while merging
int mergeandcount(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int inv_count = 0;

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
            inv_count += (n1 - i); 
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    return inv_count;
}

int mergeSort(int arr[], int l, int r) {
    int inv_count = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        // Sum up inversions from left, right, and the merge step
        inv_count += mergeSort(arr, l, m);
        inv_count += mergeSort(arr, m + 1, r);
        inv_count += mergeandcount(arr, l, m, r);
    }
    return inv_count;
}

int main() {
    int n = 10; // Keeping it small for easy verification
    int arr[] = {3, 1, 8, 2, 7, 5, 6, 4, 10, 9};
    
    printf("Original array: \n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    clock_t start = clock();
    int total_inversions = mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    
    printf("\n\nTotal Inversions: %d", total_inversions);
    printf("\nTime taken: %f seconds\n", time_taken);

    return 0;
}