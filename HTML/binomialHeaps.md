Insertion is a special case of merging. We create a 0-order tree with the new element, then merge
it with existing forest of binonmial trees. The merging stops after <i>i</i>+1 steps if the smallest 
non-existent binomial tree in the binomial heap is B<sub><i>i</i></sub>. Creating a <i>n</i> node
heap starting from an empty binomial forest takes O(<i>n</i>) time. It is possible to create the 
binomial heap with <i>n</i>-1 comparisons. Let us try creating binomial queues formed by inserting
elements 1 to 8. 

<p style="text-align:center">
  <img src="../images/binomHeapInsertion.png"><br>
  Figure 3
</p>

The deleteMin operation on a binomial heap is implemented by scanning all the roots of binomial trees that
constitue the heap. We can maintain the minimum of all roots in a separate variable, and update it whenever
it changes during a heap operation. Since binary representation has log <i>n</i> bits, deleteMin requires
O(log <i>n</i>).
The deleteMin operation is also easy. It breaks a binomial tree into two. Then we have to perform
merging if required. So it takes time of O(log <i>n</i>) in the worst-case.
