#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// swap exchanges two values in the array.
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// This partition step chooses a random pivot so we avoid bad cases.
// Then it moves smaller values to the left and larger values to the right.
int partition(int arr[], int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    swap(&arr[pivotIndex], &arr[high]); // put pivot at end
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] <= pivot)
            swap(&arr[++i], &arr[j]); // extend left partition
    swap(&arr[i + 1], &arr[high]); // place pivot in correct position
    return i + 1;
}

// quickSort sorts by dividing the array around pivot and recursing.
// First it partitions the array, then it sorts each half separately.
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);   // sort left part
        quickSort(arr, pi + 1, high);  // sort right part
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    srand((unsigned) time(NULL));
    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
