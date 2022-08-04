## Binomial Trees

An interesting tree structure called a binomial tree is based on the concept of binomial coefficients. 
The definition of binomial trees relies on the recursive rules for the computing binomial coefficients.
We define binomial trees using a base case and a recursive rule for the generation of higher-order binomial trees
as follows:

- <strong>Base case</strong>: A binomial tree order 0 has a single node. 
- <strong>Recursive rule</strong>: A binomial tree of order <i>k</i> is constructed by merging two binomial trees of order <i>k-1</i>, where the root of one tree becomes the left child of the root of the other.
  
Figure 1 illustrates a few binomial trees of small orders. 
<p style="text-align:center">
  <img src="../images/binomTree.png"><br>
  Figure 1
</p>

Let us explore some properties of binomial trees before discussing implementation issues. A binomial tree of
order 0 has one node. Merging two binomial trees of order 0 creates one binomial tree of order 0. It has two
nodes. Similarly, a binomial tree of order 2 has four nodes. In general a binomial tree of order <i>k</i> has
2<sup><i>k</i></sup> nodes. We can verify the fact also from examples of binomial trees shown in Figure 1. More 
properties of binomial trees are as listed below:

- The root of a binomial tree of order <i>k</i> has <i>k</i> children
- The leftmost child of the root is the root of a binomial tree of order 0
- The second leftmost child is the root of a binomial tree of order 1
- In general <i>i</i> the leftmost child is the root of a binomial tree of order  <i>i</i>

A forest of binomial trees defines a binomial heap. If the binomial heap has <i>n</i> nodes then  it consists of
binomial trees equal to the number of 1 bits in binary representation of <i>n</i>. For example, if
<i>n=13</i>, the binomial heap representing it consists of three binomial trees 
B<sub>3</sub>, B<sub>2</sub>, and B<sub>0</sub> that correspond to 1 bits in binary representation of
13, i.e., 1101. Figure 2 illustrates the equivalence of heap and its binomial trees.
<p style="text-align:center">
  <img src="../images/binomialTreeAndBITs.png"><br>
  Figure 2
</p>

Merging two binomial forests is the fundamental operation in manipulating binomial heaps. We carry out 
joining from the lowest order to the highest order and stopping at the order where it ends up with a tree of non 
existent order. The process of merging is akin to the addition of two binary numbers. Figure 3 depicts binary 
addition in reverse order where carry bit corresponds to the generation of a new binomial tree in the merging 
process. 

<p style="text-align:center">
  <img src="../images/binaryAddBinomHeap.png"><br><br>
  Figure 3
</p>

For example, consider merging of two binomial heaps H<sub>1</sub> and H<sub>2</sub>. 

1. H<sub>1</sub> consists of three trees B<sub>0</sub>, B<sub>1</sub>, B<sub>3</sub>.
2. H<sub>2</sub> consists of three trees B<sub>0</sub>, B<sub>2</sub>, B<sub>3</sub>. 

As explained in Figure 3, we merge the binomial trees of the same orders 
belonging to two heaps starting with the lowest order trees. The merging process completes when no pair 
of binomial trees of the same order is left. A straightforward merging cannot maintain heap property. 
To maintain heap property, we choose the larger of the roots of the pair of trees a child of the
smaller. In the first merging operation we choose a B<sub>0</sub> from H<sub>1</sub> and another 
from H<sub>2</sub>. Merging these two trees, we get a new B<sub>1</sub>. The result of the merging 
is shown in the right half of the figure below.

<p style="text-align:center">
  <img src="../images/binomMerge1.png"><br><br>
  Figure 4a
</p>

Next, we take the B<sub>1</sub> from H<sub>1</sub> and merge it with the newly generated tree B<sub>1</sub>. 
It produces a new B<sub>2</sub>. The result is illustrated in Figure 4b.

<p style="text-align:center">
  <img src="../images/binomMerge2.png"><br><br>
Figure 4b
</p>

So, in the third merging the new B<sub>2</sub> tree is merged with B<sub>2</sub> available in H<sub>2</sub>. 
The merging creates a new binomial tree B<sub>3</sub>. However, a binomial tree B<sub>2</sub> is left unmerged in
heap H<sub>2</sub>. Therefore, when merging completes, we are left with a heap consisting of two binomial trees
B<sub>2</sub> and B<sub>3</sub> as shown in Figure 4c.

<p style="text-align:center">
  <img src="../images/binomMerge4.png"><br><br>
  Figure 4c
</p>

Merging a pair of trees takes O(1) time. Two heaps together may consists of up to O(log <i>n</i>) trees, 
so the merging takes O(log <i>n</i>) in the worst-case. If we maintain the trees in the forest in sorted 
order according to heights, then the merging stop with the smallest non-existent tree. However, 
merge is performed most frequently. Therefore, a binomial forest maintained according to 
ascending order of the constiuent binomial trees.
The key algorithm for merging is linking of two binomial trees. It is given below:

```
linkBinomialTrees(T, S) {
    r1 = getRoot(T);  // Root of the tree T
    r2 = getRoot(S);  // Root of the tree S
    if (r1->key < r2->key) { 
         // Since key in the root of S is smaller than key in the root of T
         // link the root of T as child of the root of S.         
         r2->parent = r1; 
         r1->child = r2; 
         r2->sibling = r1->child;
         r1->degree += 1;
     } else {  
         // Key in root of T is smaller, link S to T. 
         r1->parent = r2;
         r2->child = r1;
         r1->sibling = r2->child;
         r2->degree += 1;
     }
     return T;
}
```

Next blog will deal with operation on binomial heaps

[Back to Index](../index.md)
