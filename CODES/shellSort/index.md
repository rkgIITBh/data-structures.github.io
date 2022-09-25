## C Program for Shell Sort

```
// Shell Sort in C programming

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


// Shell sort
void shellSort(ARRAY * a) {
     // Rearrange elements at each n/2, n/4, n/8, ... intervals
     int  n = a->length; 
     for (int interval = n / 2; interval > 0; interval /= 2) {
         for (int i = interval; i < n; i += 1) {
             int temp = a->arr[i];
             int j;
             for (j = i; j >= interval && a->arr[j - interval] > temp; j -= interval) {
                 a->arr[j] =  a->arr[j - interval];
             }
             a->arr[j] = temp;
         }
     }
}

// Driver code
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

    shellSort(A);
    printf("Sorted array: \n");
    printArray(A);
}

```

[Back to Shell Sort Algorithm](../../HTML/shellSortAlgorithm.md)
