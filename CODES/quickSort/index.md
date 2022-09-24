## C Program for Quick Sort

The main function in program for quck sort is partition(). We have assumed the last element as
the pivot element. It returns the index position where we should place the pivot. The partitioning
also places 

- All elements less than pivot are to its left, and
- All elements  greater than the pivot to its right.

The program requires two helper functions, namely

- creatArray(): it creates an array of the given size, and
- printArray(): it prints the content of the array.

In the driver program, we use random number generator using srand() and rand() and populate the 
array. 

```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAXSIZE 15 

typedef struct array {
    int * arr;
    int length;
} ARRAY;

// Create array of a given length
ARRAY * createArray(int n) {
    ARRAY * a;
    a = (ARRAY *)malloc(sizeof(ARRAY));
    a->length = n;
    a->arr = (int *)malloc(sizeof(int)*n);
    return a;
}

// Function to swap a pair of elements
void swap(ARRAY* a, int i, int j) {
     int t = a->arr[i];
     a->arr[i] = a->arr[j]; 
     a->arr[j] = t;
}

// The function takes the last element as pivot,
// places it at the correct position in sorted order.
// Places all element smaller than pivot to the left
// all elements greater than pivot to the right of pivot.

int partition(ARRAY *a, int low, int high) {
   int pivot = a->arr[high]; // pivot
   int i = (low - 1); // Index of smaller element and indicates
	              // the right position of pivot found so far

   for (int j = low; j <= high - 1; j++) {
	// If current element is smaller than the pivot
	if (a->arr[j] < pivot) {
	     i++; // increment index of smaller element
	     swap(a, i, j);
	}
   }
   swap(a, i + 1, high);
   return (i + 1);
} 

void quickSort(ARRAY *a, int low, int high) {
    if (low < high) {
	// pi is partitioning index, arr[p] is now
	// at right place 
	int pi = partition(a, low, high);

	// Separately sort elements before
	// partition and after partition
	quickSort(a, low, pi - 1);
	quickSort(a, pi + 1, high);
    }
} 

// Function to print elements in the array 
void printArray(ARRAY *a) {
    int n = a->length;
    for (int i = 0; i < n; i++)
	printf("%d  ", a->arr[i]);
    printf("\n");
}

// Driver Code
int main() {
   ARRAY * A;
   A = createArray(MAXSIZE);
   int n = A->length;
    
   // Generate and store random values
   srand(time(0));
   for(int i = 0; i < n; i++) {
       int x = rand()%100;
       A->arr[i] = x; 
   }
 
   printf("Unsorted array: \n");
   printArray(A);

   quickSort(A, 0, n - 1);
   printf("\nSorted array: \n");
   printArray(A);
   return 0;
}
```
[Back to Quick Sort Algorithm](../../HTML/quickSortAlgorithm.md)
