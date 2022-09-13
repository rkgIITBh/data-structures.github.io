## Quick Sort Algorithm

Tony Hoare discovered the Quick sort algorithm in 1959. Like mergesort, it recursively divides the 
input array into smaller subarrays top-down. Each division operation divides an array into two
smaller subarrays, with one subarray consisting of smaller elements than all the other subarray 
elements. The exchange of elements occurs during division that transfers all smaller elements to one 
side and all larger ones to the other. So, the algorithm belongs to the class
of sorting known as the partition-exchange algorithm. The average cost of quick sort is 
O(<i>n log n</i>) for sorting of an <i>n</i> element array. However, the worst-case time complexity 
is O(<i>n<sup>2</sup></i>). We will discuss the average case later in the blog.

Quick sort requires an element for the pivot that works as a fulcrum of balancing scale. 
The choice of pivot is critical to the performance of quicksort. If the pivot is entirely one-sided 
then the size of partitions becomes uneven. For example, if we choose either the first or the 
last element as pivot, then one subarray will consist of <i>n-1</i> elements while the other 
will have only one element. So, the pivot should not be close to the smallest or largest element. The 
best choice for the pivot is the median. However, if the cost of median finding
is high, then performance will degrade because a pivot is also needed for each subsequent partition.
In our description, we assume that the input is sufficiently random. So, we neither
have a sorted nor a reverse sorted sequence as input. In such a situation, we can assume the 
first element to be good enough for a pivot. Sometimes, we can pick the input's first, last, and
middle elements and find the median of three. Then use the median of three as a pivot. 
The median of three captures more randomness than using the first element as a pivot. Since the 
median of three takes constant time, the performance of quick sort is not affected.

Since partitioning is the critical step, let us understand the partitioning method.  We begin
with a sketch assuming the first element as a pivot. As partitioning progresses, we should have
the elements in sorted order. 
<p style="text-align:center">
  <img src="../images/quickSortPartitioning.png"><br>
  Figure 1: Partitioning example
</p>
The figure only serves to give an insight of top-down recursive partitioning. However, it does
not indicate how the partitioning method will actually work. 

If we swap the pivot with last element of the input array then it shifts the pivot to position
away from consideration of the partitioning the rest of elements. We need to divide those 
element into two parts: 

- One set of elements <i>S</i> which are smaller than or equal to the pivot,
- Another set of elements <i>G</i> which are greater than the pivot, and
- The elements of <i>S</i> should occur before those of <i>G</i> in the array positions.

To accomplish it, we should scan over all the elements except the pivot, and rearrange them in
place. We create two cursors:

- The first cursor <i>i</i> set to one position behind the leftmost index. 
- The second cursor <i>j</i> set to the leftmost index of the array. 

Now the question is:

- How are the elements moved to create the partition?

We advance both the cursors <i>i</i> and <i>j</i> as long as elements under them are smaller 
than pivot. By doing so, we ensure that none of the smaller elements are shifted unnecessarily.
If the element under <i>i + 1</i> becomes greater than the pivot then we stop incrementing 
<i>i</i>. At this point we have a hit the boundary for first partition, now we must try to
expand the boundary. So, we advance <i>j</i> until finding an element smaller than or equal
to the pivot. The two situations are depicted in Figure 2. 
<p style="text-align:center">
  <img src="../images/quickSortIndexLoc1.png">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<img src="../images/quickSortIndexLoc2.png"><br>
  Figure 2: Partitioning process and its termination
</p>
The left part of the figure refers to the case when <i>i</i> is set at the boundary of the
array with elements smaller or equal to the pivot. The cursor <i>j</i> continues to advance
expanding the segment of the array between <i>i + 1</i> and <i>j</i> for the elements greater
than the pivot. Once we get an element smaller or equal to pivot under <i>j</i>, we can 
swap it with the element at <i>i + 1</i>. The swapping expands the array segments of both
types of element as indicated by the right part of Figure 2. After the swapping we have to
advance both <i>i</i> and <i>j</i>. The partitioning process should terminate when <i>j</i> 
has run through the array and points to the pivot's position. 

Since <i>i</i> points to the rightmost element smaller or equal to the pivot, all elements at 
index position <i>i + 1</i> and beyond should be greater than the pivot. So, by swapping
the pivot with the element at the index <i>i + 1</i>, we place the pivot at its correct position. 
Hence the partitioning should terminate. 

Figure 3 gives an example of the partitioning. As we can find 

- All elements less than or equal to pivot occur before the elements greater than pivot 

<p style="text-align:center">
  <img src="../images/quickSortPartitionExample.png"><br>
  Figure 3: Partitioning example
</p>
The algorithm for partitioning appears below.

```
partition(A, low, high) {
   pivot = A[high];  // Pivot 
   i = low - 1 // index for smaller element 
   for (j=low; j<high; j++) {
       if (A[j] < pivot) { 
          i++; 
          swap(A[i], A[j]);
       }
   }
   // Elements A[i+1:high] > pivot
   // Elements A[low:i] <= pivot
   swap(A[i+1], A[r]);
   return ++i;
}
```
The partitioning process places the pivot in correct position. So quick sort is a straightforward
recursive call to partitioning algorithm on partitions after the pivot is in correct postion. The
algorithm is give below.

```
quickSort(A, p, r) {
    if (p < r) {
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}
```

<strong>Average case analysis</strong>

Quick sort average case analysis is based on the following assumptions:

- All permutation of input sequence is equally likely, so we can choose first element as pivot
- The pivots used at all recursive levels are random 

Therefore, the recurrence formula for time complexity is:
<p style="text-align:center">
  <img src="../images/quickSortRecurrenceFormula.png" width="380" height="50">
</p>
Since we move the pivot out of the way during partitioning, one comparisons takes place for
each of <i>n-1</i> elements. The remaining part of the recurrence relation is explained as 
follows. If <i>i</i> elements are in one partition then <i>n-i-1</i> elements are in the other
partition. Now by symmetry of expression within summation sign, we simplify the recurrence
relation as:
<p style="text-align:center">
  <img src="../images/quickSortFormula1.png" width="260" height="40">
</p>                                                                
We multiply both sides of the above equation by <i>n</i> and substract <i>T(n-1)</i>
from <i>T(n)</i> and get:                                                              
<p style="text-align:center">
  <img src="../images/quickSortFormula2.png" width="400" height="35">
</p>
Rearranging terms and simplifying, we have:
<p style="text-align:center">
  <img src="../images/quickSortFormula3.png" width="250" height="30">
</p>
Now the recurrence is in a form which we can solve by unfolding the recurrence.
<p style="text-align:center">
  <img src="../images/quickSortFormula4.png" width="400" height="250">
</p>
Approximating summation by integral 
<p style="text-align:center">
  <img src="../images/quickSortFormula5.png" height="30" width="60">
</p>
we get:
<p style="text-align:center">
  <img src="../images/quickSortFormula6.png" width="350" height="60">
</p>
