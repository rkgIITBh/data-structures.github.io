## C Program for Bubble Sort

The program uses a random number generator function to generate MAX number of integers within a 
range specified by <i>start</i> and <i>end</i>. The random number generator uses <i>time.h</i> for
random seed. The rest of the code is easy to follow. We have provided a print function and the 
main function. Therefore, the program can be copied as is and executed.

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
}

void swap(int *i, int *j) {
    int tmp = *i;
    *i = *j;
    *j = tmp;
    return;
}

void bubbleSort(int *a) {
  int  i, n = MAX;
  int swapped;
  do { 
    swapped = 0; // Value 0 indicates no swap
    for(i = 0; i < n-1; i++) {
      if (a[i] > a[i + 1]) { 
        swap(&a[i], &a[i + 1]); // Exchange a[i] and a[i+1]
        swapped = 1; // Value 1 indicate at least one swap
      }
    }
    n--; // The size of unsorted part decreases
  } while(swapped); // Continue till no swap

  return;
}

int main() {
    int A[MAX];
    randomGen(A);
    printf("\nUnsorted array\n");
    printArray(A);
    bubbleSort(A);
    printf("\nSorted array\n");
    printArray(A);
    return 0;
}

```

[Back to Bubble Sort Algorithm Page](../../HTML/bubbleSortingAlgorithm.md)
