## C Program for Insertion Sort

The program requires two helper functions.

- One for generating a random set of input elements
- The second one is for printing the elements

As in the case of bubble sort, the input array is generated using a random number generator. It uses
rand() and srand() functions. We have used time.h to seed the random number generator. The printArray()
function was discussed earlier in the program for bubble sort. The code otherwise is easy to 
follow.

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
    //printf("\n%d Random Numbers between %d and %d:\n", n, start, end);
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
    return;
}


void insertionSort(int *a) {
  int  i, j, n = MAX, gap, moved;

  for(i = 1; i < n; i++) {
        gap = a[i];
        j = i-1;
        while(j >= 0 && a[j] > gap) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = gap;
  } 
 
  return;
}

int main() {
    int A[MAX];
    randomGen(A);
    printf("\nUnsorted array\n");
    printArray(A);
    insertionSort(A);
    printf("\nSorted array\n");
    printArray(A);
    return 0;
}
```

[Back to Insertion Sort](../../HTML/insertionSort.md)
