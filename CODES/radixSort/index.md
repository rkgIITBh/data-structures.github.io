## C Program for Radix Sort

The program below consists of five functions and a main function as driver program. We first
create a structure which stores an array of numbers and the size of the array. We use a global
constant MAXSIZE for the capacity of the array. The function createArray() is used to create
the array of MAXSIZE for storing the input. 

The helper functions are as follows:

- print(): prints the contents of an array.
- getMax() to extract the maximum elements from the input.

The purpose of extracting the maximum is to get the number of buckets we will require to 
distribute the elements. We divide the maximum by the base of the number system. The number
digits in the maximum is equal to the number divisions till the residue becomes zero. 

The other three functions are:

- createArray(): creates storage for the array and also store its length.
- bucketDistribution(): distributes the elements into buckets using counting sort
- radixSort(): it calls bucketDistribution() repeatedly to perform the passes. The number of passes
is equal to the maximum number of digit positions.

We generate the input randomly using a random number generator taking time as seed. 

```
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAXSIZE 15 

typedef struct array {
    int * arr; // Store for list of elements
    int length;// Number of elements in the list
} ARRAY;

ARRAY * createArray(int n) {
    ARRAY * a;
    a = (ARRAY *)malloc(sizeof(ARRAY));
    a->length = n;
    a->arr = (int *)malloc(sizeof(int)*n);
    return a;
}

// A helper function to get maximum of input. 
int getMax(ARRAY *a) {
    int n = a->length;
    int mx = a->arr[0];
    for (int i = 1; i < n; i++)
	if (a->arr[i] > mx)
	    mx = a->arr[i];
    return mx;
}

// A function for counting sort 
void bucketDistribution(ARRAY *a, int exp) {
    int n = a->length;
    int output[n]; // output array
    int i, bucket[n];

    // Initialize the array
    for (i=0; i < n; i++)
        bucket[i] = 0;

    // Store number of occurrences in count array
    for (i = 0; i < n; i++)
	bucket[(a->arr[i] / exp) % 10]++;

    // Update bucket[i] to contain actual 
    // position of this digit in output array
    for (i = 1; i < n; i++)
	bucket[i] += bucket[i - 1];

     // Build the output array
     for (i = n - 1; i >= 0; i--) {
	output[bucket[(a->arr[i] / exp) % 10] - 1] = a->arr[i];
	bucket[(a->arr[i] / exp) % 10]--;
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

     // Use counting sort for every digit to distribute 
     // the numbers into appropriate buckets.
     for (int exp = 1; m / exp > 0; exp *= 10)
	 bucketDistribution(a, exp);
}

// A helper function to print an array
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

[Back to Radix Sort Algorithm](../../HTML/radixSortAlgorithm.md)
