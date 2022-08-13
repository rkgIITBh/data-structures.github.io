## Sorting Algorithms

We have used sorting in various contexts in some of the previous blogs. Some operations on linked
lists become efficient if the lists are maintained in sorted order. Searching for an element in a list
becomes efficient if the list is sorted. However, we have not considered the problem of sorting
itself. A list may be presented as a collection of elements in any order, not necessarily in 
sorted order. So, the question is: how do we get a sorted list in the first place? There are many
sorting algorithms. We can classify them according to several characteristics. 

- Based on the complexity  
- Based on the number of comparisons 
- Based on the number of movements
- Based on memory usage
- Based on stability
- Based on adaptability

The three measures of computational complexity are best case, the average case, and worst case. Since 
the lower bound of sorting is O(<i>n log n</i>) for input size of <i>n</i>, the best case of
computational complexity is O(<i>n log n</i>). The worst case of sorting <i>n</i> is 
O(<i>n<sup>2</sup></i>). The average case is equal to the computational efforts by the sorting 
algorithm averaged over all possible input distributions. Typically, we consider all possible inputs equally likely and define probability measures. We determine the computational complexity for placing the elements in sorted order using the probability measure. 

Sorting is defined only as a collection of elements on which a total order is possible. A comparison
between a pair of elements is the fundamental operation for finding the relative position of an 
element with respect to others in an input list. Therefore, the number of comparisons determines
the running time of a sorting algorithm. A sorting network consists of a wired set 
of comparators. Counting the number of comparisons that turns an input into a sorted list gives 
the computation complexity. However, as we will see later, algorithms such as radix 
sort or counting sort do not use comparisons. So, the running time of these algorithms is not 
defined based on the number of comparisons.

Most comparison-based algorithms use swaps or data exchanges. However, there is no movement of
data as it happens in the case of bubble sort or radix sort. In bubble sort, we move the elements
to the right of the sorted section to create a vacant slot for the next element
from the unsorted selection of the list. As we find, bubble sort progressively builds the
sorted list from a single element to including all the elements in the input list.

Memory usage tells whether the algorithm requires extra (auxiliary) space for  
sorting operations or whether the operations are possible without any extra space. If a sorting 
algorithm does not require additional space, we call it an "in place" sorting algorithm.

A stable sort does not disturb the relative position of the equal elements. So equal keys maintain
their relative order in the sorted list. If elements are distinct, then stability distinction
is meaningless. However, some algorithms fail to maintain stability in the presence of equal elements in the input.

Adaptability influences the sorting time for some sorting algorithms. Some sorting algorithms take presortedness of the elements to reduce running time. Such algorithms are classified
as adaptable. 

Now let us deal with actual algorithms. We start with a set of easy algorithms. It consists of

- Bubble sort
- Insertion sort
- Selection sort

<strong>Bubble Sort</strong>

Bubble sort works on the principle of floating the lightest element to the top. We view the input 
as consisting of two sets of elements: lighter and heavier. Heavier elements sink to the bottom, and 
lighter elements float to the top as it happens in water or any liquid with buoyancy. Figure
below illustrates bubble sort algorithm.
<p style="text-align:center">
  <img src="../images/bubbleSort.png">
</p>
It is basically a swap-based algorithm. Starting with leftmost end of the input list, it compares
adjacent pair of the elements. The heavier element is placed to right. After the first pass of 
<i>n</i> compare-swap operations, the heaviest element occupies the <i>n</i> th position of the
list. Now the list consist of unsorted part of <i>n-1</i> elements and sorted part of 1 element.
The sorted part is excluded from the next pass of comparison which considers a list of <i>n-1</i>
elements to the left. With every pass of compare-swap the size of the sorted part increase by one.
Therefore, with <i>n</i> passes the size of the sorted part becomes <i>n</i>. The algorithm
is given below.

```
 procedure bubbleSort(A) {
  n = A.length();
  do while
    swapped = FALSE; // Flag used to indicate swaps
    for(i = 0; i < n; i++) {
      if (A[i] > A[i + 1]) { 
        swap(A[i], A[i + 1]); // Exchanges A[i] and A[i+1]
        swapped = TRUE;
      }
    }
    n--; // Size of unsorted part decreases
  until (!swapped)
}
```





