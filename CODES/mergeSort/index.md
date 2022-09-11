## C Program for Mergesort

The program uses random number generator function as described earlier. It
also requires a function to print the array. The most important function is
merge as discussed. 

```
// Merge sort in C
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
        printf("\n"); // Print 5 elements in each line 
        j = j+5;
    }
}

// Merge two subarrays A and B into C 
void merge(int *C, int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int m = q - p + 1;
  int n = r - q;

  int A[m], B[n];

  for (int i = 0; i < m; i++)
    A[i] = C[p + i];
  for (int j = 0; j < n; j++)
    B[j] = C[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements A and B and place them in the correct position at C[p..r]
  while (i < m && j < n) {
    if (A[i] <= B[j]) {
      C[k] = A[i];
      i++;
    } else {
      C[k] = B[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either A or B,
  // pick up the remaining elements and put in C[p..r]
  while (i < m) {
    C[k] = B[i];
    i++;
    k++;
  }

  while (j < n) {
    C[k] = B[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int *C, int left, int right) {
  if (left < right) {

    // Recursive topdown division of input array into subarrays
    // m is the point where the array is divided into two subarrays
    int mid = left + (right - left) / 2;

    mergeSort(C, left, mid);
    mergeSort(C, mid + 1, right);

    // Merge the sorted subarrays bottom pass
    merge(C, left, mid, right);
  }
}


int main() {
  int arr[MAX];

  randomGen(arr);

  printf("\nUnsorted Array\n");
  printArray(arr);

  mergeSort(arr, 0, MAX - 1);

  printf("Sorted array: \n");
  printArray(arr);
}
```

[Back to Merge Sort Algorithm](../../HTML/mergeSortAlgorithm.md)
