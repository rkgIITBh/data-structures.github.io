## Sorting Algorithms

We have used sorting in various context in some of the previous blogs. Some operations on linked
lists become efficient if the lists are mainted in sorted order. Searching an element in a list
becomes efficient if the list is sorted. However, we have not considered the problem of sorting
itself. A list may be presented as collection of elements in any order, not necessarily in a
sorted order.So, the question is: how do we get a sorted list in the first place? There are many
sorting algorithms. We can classify them according to several characteristics. 

- Based on complexity.  
- Based on number of comparisons: 
- Based on number of exchanges
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

The 
So, we need to define a suitable 
- Sorting using comparisons
- Sorting by data exchanges
- Sorting by counting 
- Stable and non-stable sorting
- 
