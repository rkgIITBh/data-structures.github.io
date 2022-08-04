A binomial heap consists of a binomial forest with each tree preserving heap property. Figure 1 
depicts a binomial heap consisting of 11 elements. The trees are linked together by sibling and
child links, as indicated. 

<p style="text-align:center">
  <img src="../images/binomialHeapEx1.png"><br>
  Figure 1
</p>





Insertion is a special case of merging. We create a 0-order tree with the new element, then merge
it with the existing forest of binomial trees. The merging stops after <i>i</i>+1 steps if the smallest 
non-existent binomial tree in the binomial heap is B<sub><i>i</i></sub>. Creating a <i>n</i> node
heap starting from an empty binomial forest takes O(<i>n</i>) time. It is possible to create the 
binomial heap with <i>n</i>-1 comparisons. Let us try creating binomial queues formed by inserting
elements 1 to 8. 

<p style="text-align:center">
  <img src="../images/binomHeapInsert.png"><br>
  Figure 2
</p>

The deleteMin operation on a binomial heap is implemented by scanning all the roots of binomial trees that
constitute the heap. Consider the deleteMin operation on the binomial heap shown in Figure 3(a). 
The operation breaks a binomial tree into two, as shown in Figure 3(b).
<p style="text-align:center">
  <img src="../images/binomHeapDeleteMin1.png"><br>
  Figure 3(a): Binomial heap before deleteMin operation.<br>
   <img src="../images/binomHeapDeleteMin2.png"><br>
  Figure 3(b): After deleteMin operation.
</p>

After the root of a binomial tree is deleted, the corresponding tree breaks into constituent
smaller binomial trees. For convenience in discussion, we use the following notations:

- H<sub>1</sub> be the original heap. 
- H be the remaining part of the original heap after deleteMin
- H' be the heap created by constituent smaller binomial trees after deleting the minimum element

We merge H and H' to get the heap H<sub>2</sub> after the deleteMin operation. 
We explained the merging process in the previous blog. So, the result after merging heaps 
H and H' of Figure 3(b) after deleteMin operation on Figure 3(a) are as follows:

<p style="text-align:center">
  <img src="../images/binomHeapDeleteMin3.png"><br>
  Figure 4
</p>

We can maintain the minimum of all roots in a separate variable and update it whenever
it changes during a heap operation. Since binary representation has log <i>n</i> bits, deleteMin requires
O(log <i>n</i>). If the heap trees are sorted in ascending order, deleteMin, then the first root in the
list is the minimum element. Then we have to perform merging if required. Therefore, the deleteMin
operation takes time of O(log <i>n</i>) in the worst-case.

[Back to Index](../index.md)

