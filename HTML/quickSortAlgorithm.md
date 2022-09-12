## Quick Sort Algorithm

Tony Hoare discovered Quick sort algorithm in 1959. Like mergesort, it recursively divides the 
input array into smaller subarrays top-down. Each division operation divides an array in two
smaller subarrays with one subarray consisting of elements which are smaller than all the elements
of the other subarray. Exchange of elements occurs during division that transfer all smaller
element to one side and all larger once to the other side. So, the algorithm belong to the class
of sorting known as partition-exchange algorithm. The averge cost of quick sort is O(<i>n log n</i>)
for sorting of an <i>n</i> element array. However, the worst-case time complexity is O(<i>n<sup>2</sup></i>).
We will discuss about average case later in the blog.

Quick sort requires an element for pivot or as fulcrum in a balancing scale. The choice of pivot is
critical to performance of quick sort. If the pivot is completely one-sided then the size of partitions
are uneven. For example, if we choose either the first or the last element as pivot then one of 
the subarray will consist of <i>n-1</i> elements while the other will have only one element. So, the
pivot should not be close either to the smallest or to the largest element. The best choice for
pivot is median. However, if the cost of median finding is high then performance will degrade, because
a pivot is needed for each subsequent partitions as well. In our description, we assume that the
input is sufficiently random. So, we neither have a sorted or a reverse sorted sequence as input.
In such a situation we can assume the first element to be good enough for a pivot. Sometimes, we
can pick the first, the last and the middle element of the input and find the median of three. Then
use the median of three as pivot. The median of three captures more randomness than using the first
element as pivot. Since the median of three takes constant time, the performance of quick sort is
not affected.



