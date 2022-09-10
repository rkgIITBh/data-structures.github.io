## C Program for Insertion Sort

The program requires three helper functions:

- swap() function for swapping the postions of a pair of elements
- printArray() function for printing an array
- randomGen() function for generation of random numbers within a given range

As explained in the description of insertion sorting algorithm, we locate the index of minimum element
and swap it with the rightmost unsorted element in the array. The function selectionSort() implements
the same.

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#define MAX 15

void randomGen(int *a) {
    int i, rnum, start, end;
    int n = MAX;
    printf("Enter Interval: ");
    scanf("%d%d", &start, &end);
    srand(time(0));
    for(i=0; i<n; i++) {
        rnum = rand()%(end+1-start)+start;
        a[i] = rnum;
        //printf("%d\n", rnum);
    }
    getch();
    return;
}

void printArray(int *a) {
    int i, j = 0;
    while (j < MAX) {
        for (i = 0; i < 5; i++) {
            if (i+j < MAX-1) 
                printf("%3d  ", a[i+j]);
            else 
                printf("%3d  ", a[i+j]);
        }
        printf("\n"); // Print 5 elements in a row
        j = j+5;
    }
}

void swap(int *i, int *j) {
    int tmp = *i;
    *i = *j;
    *j = tmp;
    return;
}

void selectionSort(int *a) {
  int  i, j, n = MAX, minIndex;

    for(i = 0; i < n; i++) {
        minIndex = i; // Start with the first element of 
                      // the unsorted part of the array 
        for(j = i+1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j; // Update the current minIndex 
            }
        }
        // Found the index of the overall minimum 
        // Exchange a[i] and a[minIndex]
        swap(&a[i], &a[minIndex]); 
    }

    return;
}

int main() {
    int A[MAX];
    randomGen(A);
    printf("\nUnsorted array\n");
    printArray(A);
    selectionSort(A);
    printf("\nSorted array\n");
    printArray(A);
    return 0;
}

```

[Back to Insertion Sort Algorithm](../../HTML/insertionSort.md)
