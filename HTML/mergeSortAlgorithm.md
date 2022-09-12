## Merge Sort

Merge sort is suitable for external sorting algorithm. It can handle massive amount of data that cannot
fit into main memory. The data resides in slow access memory such as disk. Chunks of data that can be
brought into main memory are sorted and written into disk. Then smaller files are combined by merging
the data. However, we only discuss the internal sorting algorithms. So, we assume that the data is
small enough to fit into main memory.

The main operation of merge sort is merging. A single element is vacously sorted. Merging of
two single elements  creates a sorted array of two elements. In general, a merging merging two sorted 
arrays of length <i>k</i> each and produces a single sorted array of length <i>2k</i>.  Therefore, by 
repeated merging, we finally get a sorted arrays of input sequence. The figures below
illustrates the operation of merging two sorted sequences of equal length.
<p style="text-align:center">
  <img src="../images/mergeTwoArrays.png"><br>
  Figure 1
</p>
As the figure shows we maintain three cursers, one each for the two given input arrays and one for 
the output array. 

- At each step we take one element from each array under the respective cursers.
- Compare the elements, the smaller is placed in the output array.
- Advance the curser for the input array from which element was sent to output.
- Advence the curser for the output array
- Repeat the step until all elements of one of the input arrays has been considered

After completing the above steps, one of the arrays will be left with the elements are not processed
in merging. These elements will be greater than the output elements. So we can transfer these
elements in same relative order in subsequent positions of output array. In the example showm in
the figure, after transfering 40 and 55 the first input array is exhausted. However, the input
array to the right will be still left with elements 72 and 89. Since the left input array will be
empty, the remaining elements 72 and 89 will get appended to the output in subsequent positions.
Therefore, the final merged sequence will be: 19, 25, 29, 38, 40, 55, 72, 89. The time complexity
of merging procedure is O(<i>m + n</i>), where <i>m</i> and <i>n</i> are respective sizes of the
two arrays. 

The merging algorithm appears below.

```
// Merge two sorted arrays A and B into C 
proedure merge(A[], B[], C[]) {
  
   m = A.length;
   n = B.length;
   C.length = m + n;

  // Maintain current index of input arrays and output array
  i = 0;
  j = 0;
  k = 0;

  // Until we reach either end of either A or B, pick larger among
  // elements A and B and place them in the correct position of array C
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
  // pick up the remaining elements and put in C[k..m+n]
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

```

The recursive version of merge sort is simple. It first divides the input 
array into two subarrays topdown and recursively calls merge sort on two
subarrays. The division continues recursively till subarray sizes are one 
each. Then merge combines the sorted subarrays bottom up. The algorithm
for merge sort is given below

```
void mergeSort(C[],  left, right) {
  if (left < right) {
    
    // Recursive topdown division of input array into subarrays
    // m is the point where the array is divided into two subarrays
    mid = left + (right - left) / 2;

    mergeSort(C, left, mid);
    mergeSort(C, mid + 1, right);

    // Merge the sorted subarrays bottom up
    merge(C, left, mid, right);
  }
}

```
Figure 3 illustrates the merge sort procedure. 
<p style="text-align:center">
  <img src="../images/mergeTopdownDivision.png" width=300 height=250 style="border:15px;margin:15px">         &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <img src="../images/mergeCombineBottomUp.png" width=300 height=250 style="border:15px;margin:15px">
  <br>
  Figure 2
</p>
The left half of the image shows recursive topdown division of the array into smaller subarrays while
the right half of the image depicts recursive merging of the subarrays bottom up. 

<strong>In place merging techniques</strong>

There are many variation of merging. The interesting part of these variations is to merge in place.
That is merging sorted arrays without using a third array for output. We discuss these variations
below.

Since there no additional array, we must rearranging the positions of elements in the input arrays.
Merging step works by swapping positions of the element pairs when first array has larger element
compared to that in the second array. The element which goes into the second array is rearranged to
keep the second array always in sorted order. When comparing elements we always begin with the 
first element of the second array. However, the curser for the first array advances after each merge
step. The figure below depicts the merging procedure.  
<p style="text-align:center">
  <img src="../images/mergingWOthirdArray.png"><br>
  Figure 3
</p>  
The rearranging elements in the second array is similar to insertion sort procedure. In Figure 2
third column depicts the subarray A2 after rearrangement. The second column shows A2 after 
swapping of elements between A1 and A2. The first column is for subarray A1.

The time complexity of the method is O(<i>m * n</i>). The worst-case time for comparing
every element of the first array with elements of the second array is O(<i>n</i>). 
Since there are <i>m</i> elements in the first array, total time for comparison is
O(<i>m * n</i>). The rearrangement of second array is done swapping. It may take a
worst case time of <i>n</i>. So, overall worst-case time including rearrangment
is O(<i>m * n</i>). Since we are not using extra space, the running time increase.
In other words, there is tradeoff between time and space.

The next merging technique uses insertion sort technique to place elements from 
one subarray into correct position in the other. The procedure is depicted in 
Figure 4.
<p style="text-align:center">
  <img src="../images/mergingFromEnd.png"><br>
  Figure 4
</p>

[C Program for Merge Sort](../CODES/mergeSort/index.md)

[Back to Index](../index.md)
