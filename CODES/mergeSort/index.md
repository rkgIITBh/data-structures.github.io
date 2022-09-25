## C Program for Mergesort

The program uses random number generator function as described earlier. It
also requires a function to print the array. The most important function is
merge as discussed. 

```
// Merge sort in C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Required for random seed
#define MAX 25

typedef struct array {
    int * arr;
    int length;
} ARRAY;

ARRAY * createArray(int n) {
    ARRAY * a;
    a = (ARRAY *)malloc(sizeof(ARRAY));
    a->length = n;
    a->arr = (int *)malloc(sizeof(int)*n);
    return a;
}

// A helper function to print an array
void printArray(ARRAY *a) {
    int n = a->length;
	for (int i = 0; i < n; i++)
		printf("%d  ", a->arr[i]);
    printf("\n");
}

// In place merging of elements in an array
void merge(ARRAY * a, int start, int mid, int end) {
    int start2 = mid + 1;
  
    // If the direct merge is already sorted
    if (a->arr[mid] <= a->arr[start2]) {
        return;
    }
  
    // Two pointers to maintain start
    // of both arrays to merge
    while (start <= mid && start2 <= end) {
  
        // If element 1 is in right place
        if (a->arr[start] <= a->arr[start2]) {
            start++;
        }
        else {
            int value = a->arr[start2];
            int index = start2;
  
            // Shift all the elements between element 1
            // element 2, right by 1.
            while (index != start) {
                a->arr[index] = a->arr[index - 1];
                index--;
            }
            a->arr[start] = value;
  
            // Update all the pointers
            start++;
            mid++;
            start2++;
        }
    }
}

// Divide the array into two subarrays,
// sort and merge them.
void mergeSort(ARRAY * a, int l, int r) {
    if (l < r) {
        // Same as (l + r) / 2, but avoids overflow
        // for large l and r
        int m = l + (r - l) / 2;
  
        // Sort first and second halves
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
  
        merge(a, l, m, r);
    }
}

// Driver program 
int main() {
    ARRAY * A; 

    A = createArray(MAX);
    int n = A->length;

    srand(time(0));
    for(int i = 0; i < n; i++) {
        int x = rand()%100;
        A->arr[i] = x; // Get  random values in heap
    }

    printf("\nUnsorted Array\n");
    printArray(A);

    mergeSort(A, 0, MAX-1);

    printf("Sorted array: \n");
    printArray(A);
    
    return 0;
}

```

[Back to Merge Sort Algorithm](../../HTML/mergeSortAlgorithm.md)
