## C Program for Selection Sort

The program requires two helper functions:

- swap() function for swapping the postions of a pair of elements
- printArray() function for printing an array

As explained in the description of insertion sorting algorithm, we locate the index of minimum element
and swap it with the rightmost unsorted element in the array. The function selectionSort() implements
the same.

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Required for seeding random number generator
#define MAX 15

typedef struct array {
    int * arr;  // Storage for elements
    int length; // length of the array
} ARRAY;

// Create an array of a given length
ARRAY * createArray(int n) {
    ARRAY * a;
    a = (ARRAY *)malloc(sizeof(ARRAY));
    a->length = n;
    a->arr = (int *)malloc(sizeof(int)*n);
    return a;
}

// Function to print elements in the array 
void printArray(ARRAY *a) {
    int n = a->length;
	for (int i = 0; i < n; i++)
		printf("%d  ", a->arr[i]);
    printf("\n");
}

// Function to swap a pair of elements
void swap(ARRAY* a, int i, int j) {
	int t = a->arr[i];
	a->arr[i] = a->arr[j]; 
	a->arr[j] = t;
}

void selectionSort(ARRAY *a) {
    int  i, j, n = a->length, minIndex;

    for(i = 0; i < n; i++) {
        minIndex = i; // Start with the first element of 
                      // the unsorted part of the array 
        for(j = i+1; j < n; j++) {
            if (a->arr[j] < a->arr[minIndex]) {
                minIndex = j; // Update the current minIndex 
            }
        }
        // Found the index of the overall minimum 
        // Exchange a[i] and a[minIndex]
        swap(a, i, minIndex); 
    }

    return;
}

int main() {
    ARRAY * A;

    A = createArray(MAX);
    int n = A->length;
    
    // Generate and store random values
    srand(time(0));
    for(int i = 0; i < n; i++) {
        int x = rand()%100;
        A->arr[i] = x; // Populate array A with random numbers
    }
    printf("\nUnsorted array\n");
    printArray(A); // Print unsorted array

    selectionSort(A);
    printf("\nSorted array\n");
    printArray(A);

    return 0;
}

```
[Back to Selection Sort Algorithm](../../HTML/selectionSort.md)
