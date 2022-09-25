## C Program for Insertion Sort

The program requires one helper function for printing the elements of the array. The printArray()
function was discussed earlier in the program for bubble sort. 

As in the case of bubble sort, the input array is generated using a random number generator. It uses
rand() and srand() functions. We have used time.h to seed the random number generator. The code otherwise is easy to 
follow.

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15

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

// Function to print elements in the array 
void printArray(ARRAY *a) {
    int n = a->length;
	for (int i = 0; i < n; i++)
		printf("%d  ", a->arr[i]);
    printf("\n");
}

void insertionSort(ARRAY *a) {
  int  i, j, n = a->length, gap;

  for(i = 1; i < n; i++) {
        gap = a->arr[i];
        j = i-1;
        while(j >= 0 && a->arr[j] > gap) {
            a->arr[j+1] = a->arr[j];
            j--;
        }
        a->arr[j+1] = gap;
  } 
 
  return;
}

// Driver function for insertion sort
int main() {
    ARRAY * A;
    A = createArray(MAX);
    int n = A->length;
    
    // Generate and store random values
    srand(time(0));
    for(int i = 0; i < n; i++) {
        int x = rand()%100;
        A->arr[i] = x; 
    }

    printf("\nUnsorted array\n");
    printArray(A);

    insertionSort(A);
    printf("\nSorted array\n");
    printArray(A);

    return 0;
}
```

[Back to Insertion Sort](../../HTML/insertionSort.md)
