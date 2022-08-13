## Sorting Algorithms

We have used sorting in various context in some of the previous blogs. Some operations on linked
lists become efficient if the lists are mainted in sorted order. Searching an element in a list
becomes efficient if the list is sorted. However, we have not considered the problem of sorting
itself. A list may be presented as collection of elements in any order, not necessarily in a
sorted order.So, the question is: how do we get a sorted list in the first place? There are many
sorting algorithms. We can classify them according to several characteristics. 

- Based on complexity.  
- Based on number of comparisons: 
- Based on number of movements
- Based on memory usage
- Based on stability
- Based on adaptability

The three measures of computational complexity are best case, average case, and worst case. Since 
the lower bound of sorting is O(<i>n log n</i>) for input size of <i>n</i>, the best case of
computational complexity is O(<i>n log n</i>). The worst case of sorting <i>n</i> is 
O(<i>n<sub>2</sub></i>). The average case is equal to the computational efforts by the sorting 
algorithm averaged over all possible input distributions. Typically, we take all possible 
inputs to be equally likely and define a probability measures. Using the probability measure
we find out the computational complexity for placing the elements in sorted order. 

Sorting is defined only on a collection of elements on which a total order is possible. Comparison
is the fundamental operation for finding the relative position of an element with respect to others
in a given collection. Therefore, the number of comparisons determines the running time of a 
sorting algorithm. In fact, a sorting network consists of a wired set of comparators. Counting
the number of comparisons that turns an input to a sorted list gives the computation complexity.
However, as we will see later there are algorithms such as radix sort or counting sort, which do 
not use comparisons. So, the running time of these algorithms are not defined on the basis of
number of comparisons.

Most comparison based algorithms use swaps or data exchanges. However, there are no movement of
data as it happens in the case of bubble sort. In bubble sort, we move the data to right of 
the list to create a vacant slot for the current data element. As we will find buble sort 
progressively builds the sorted list from single element to include all the elements in the 
input list.

Memory usage tells whether the algorithm requires extra (auxiliary) space for carrying out 
sorting operations, or the operations are possible without any extra space. If a sorting 
algorithm does not require extra space then we call it as "in place" sorting algorithm.

