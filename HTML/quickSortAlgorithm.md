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

Since partitioning is the critical step, we begin with a description of the partitioning method.
The idea of partition is shown below, assuming the first element as a pivot.
<p style="text-align:center">
  <img src="../images/quicksortPartitionEx.png">
</p>


