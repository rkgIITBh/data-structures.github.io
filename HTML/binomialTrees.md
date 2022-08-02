## Binomial Trees

An interesting tree structure is based on the concept of binomial coefficients. Binomial tree has heap properties.
The definition of binomial trees relies on the recursive rules for computation of binomial coefficients.
We define binomial trees using a base case and a recursive rule for generation of higher order binomial trees
as follows:

- A binomial tree order 0 has a single node. 
- A binomial tree of order <i>k</i> is created from two binomial trees of order <i>k-1</i> and making root of
  one tree as the left child of the root of the other tree.
  
Figure 1 illustrates few binomial trees of small orders. 
<p style="text-align:center">
  <img src="../images/binomTree.png"><br>
  Figure 1
</p>

Let us explore some properties of binomial trees before discussing implementation issues. A binomial tree of
order 0 has one node. Since a binomial tree of order 1 is made of two binomial trees of order 0. It has two
nodes. Similarly, a binomial tree of order 2 has 4 nodes. In general a binomial tree of order <i>k</i> has
2<sub><i>k</i></sub> nodes. The above fact is also indicated in examples shown in Figure 1. More properties 
of binomial trees are as listed below:

- The root of a binomial tree of order <i>k</i> has <i>k</i> children
- The leftmost child of the root is the root of a binomial tree of order 0
- The second leftmost child is the root of a binomial tree of order 1
- In general <i>i</i> th leftmost child is the root of a binomial tree of order  <i>i</i>

A binomial heap is based on binomial tree structure. If the binomial heap has <i>n</i> nodes then 
it has binomial trees equal to the number of 1 bits in binary representation of <i>n</i>. For example if
<i>n=13</i>, the binomial heap representing it consist of two binomial trees 
B<sub>4</sub>, B<sub>3</sub>, and B<sub>1</sub> that correspond to 1 bits in binary representation of
13, i.e., 1101. Figure 2 illustrates the equivalence.
<p style="text-align:center">
  <img src="../images/binomialTreeAndBITs.png"><br>
  Figure 2
</p>

Merging two binomial forests is the fundamental operation in manipulating binomial heaps. Merging is quite easy.  
Consider two binomial heaps H<sub>1</sub> and H<sub>2</sub>. The merging of binomial forests of two heaps is 
carried out by merging the binomial trees of same orders belonging to two heaps. Merging process completes 
when no pair of binomial trees of same order is left. Let us take an example to illustrate the merging
process. Suppose 

1. H<sub>1</sub> consists of three trees B<sub>0</sub>, B<sub>1</sub>, B<sub>3</sub>.
2. H<sub>2</sub> consists of three trees B<sub>0</sub>, B<sub>2</sub>, B<sub>3</sub>.

A straightforward merging cannot maintain heap property. To maintain heap property, we choose 
the larger of the roots of the pair of trees a child of the smaller. In the first merging operation 
we choose a B<sub>0</sub> from H<sub>1</sub> and another from H<sub>2</sub>. Merging these two trees
we get a new B<sub>1</sub>. The result of merging is shown in right half of the figure.

<p style="text-align:center">
  <img src="../images/binomMerge1.png"><br><br>
  Figure 3a
</p>

Next, we take the B<sub>1</sub> from H<sub>1</sub> and merge it with the newly generated tree B<sub>1</sub>. 
It produces a new B<sub>2</sub>. The result is illustrated in Figure 3b.

<p style="text-align:center">
  <img src="../images/binomMerge2.png"><br><br>
Figure 3b
</p>

So, in the third merging the new B<sub>2</sub> tree is merged with B<sub>2</sub> available in H<sub>2</sub>. 
The merging creates a new binomial tree B<sub>3</sub>. However, a bionmial tree B<sub>2</sub> is left unmerged in
heap H<sub>2</sub>. Therefore, when merging completes we are left with a heap consisting of two binomial trees
B<sub>2</sub> and B<sub>3</sub> as shown in Figure 3c.

<p style="text-align:center">
  <img src="../images/binomMerge4.png"><br><br>
  Figure 3c
</p>

Merging of a pair of trees takes O(1) time. Two heaps together may consists of up to O(log <i>n</i>) trees, 
so the merging takes O(log <i>n</i>) in the worst-case. If we maintain the trees in the forest in sorted 
order according to heights then the merging stop with the smallest non-existent tree.

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

