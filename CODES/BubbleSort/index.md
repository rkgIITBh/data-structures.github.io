## C Program for Bubble Sort

The program uses a random number generator function to generate MAX number of integers within a 
range specified by <i>start</i> and <i>end</i>. The random number generator uses <i>time.h</i> for
random seed. The rest of the code is easy to follow. We have provided a print function and the 
main function. Therefore, the program can be copied as is and executed.

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15

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


// A utility function to print an array
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

void bubbleSort(ARRAY *a) {
  int  i, n = a->length;
  int swapped;
  do { 
    swapped = 0; // Value 0 indicates no swap
    for(i = 0; i < n-1; i++) {
      if (a->arr[i] > a->arr[i + 1]) { 
        swap(a, i, i + 1); // Exchange a->arr[i] and a->arr[i+1]
        swapped = 1; // Value 1 indicate at least one swap
      }
    }
    n--; // The size of unsorted part decreases
  } while(swapped); // Continue till no swap

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
        A->arr[i] = x; 
    }
 
    printf("\nUnsorted array\n");
    printArray(A);

    bubbleSort(A);
    printf("\nSorted array\n");
    printArray(A);

    return 0;
}
```

[Back to Bubble Sort Algorithm Page](../../HTML/bubbleSortingAlgorithm.md)
