## C Program for Radix Sort

The program below consists of four functions and a main function as driver program. We first
create a structure which stores an array of numbers and the size of the array. We use a global
constant MAXSIZE for the capacity of the array. The function createArray() is used to create
the array of MAXSIZE for storing the input. We generate the input randomly using random number
generator. 


```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAXSIZE 15 

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

// A helper function to get maximum value in a->arr[]
int getMax(ARRAY *a) {
    int n = a->length;
	int mx = a->arr[0];
	for (int i = 1; i < n; i++)
		if (a->arr[i] > mx)
			mx = a->arr[i];
	return mx;
}


// A function for counting sort 
void countSort(ARRAY *a, int exp) {
    int n = a->length;
	int output[n]; // output array
	int i, count[n];

    // Initialize the array
    for (i=0; i < n; i++)
        count[i] = 0;

	// Store number of occurrences in count array
	for (i = 0; i < n; i++)
		count[(a->arr[i] / exp) % 10]++;

	// Update count[i] to contain actual 
    // position of this digit in output array
	for (i = 1; i < n; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(a->arr[i] / exp) % 10] - 1] = a->arr[i];
		count[(a->arr[i] / exp) % 10]--;
	}

	// Copy the output array to a->arr[], so that it 
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		a->arr[i] = output[i];
}

// The main function to that sorts a->arr[] using Radix Sort
void radixsort(ARRAY *a) {
	// Find the maximum number to know number of digits
    
	int m = getMax(a);

	// Do counting sort for every digit.
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(a, exp);
}

// A utility function to print an array
void print(ARRAY *a) {
    int n = a->length;
	for (int i = 0; i < n; i++)
		printf("%d  ", a->arr[i]);
    printf("\n");
}

// Driver Code
int main() {
	ARRAY *a; 

    a = createArray(MAXSIZE);
    int n = a->length;

    srand(time(0));
    for(int i = 0; i < n; i++) {
        int x = rand()%100;
        a->arr[i] = x; // Get  random values in heap
    }
    // Print the unsorted input list
    printf("List to be sorted using heap sort\n");
	print(a);
	
	// Function  radix sort to sort the input list  
	radixsort(a);
    printf("Sorted list using radix sort\n");
	print(a);
	return 0;
}

```
