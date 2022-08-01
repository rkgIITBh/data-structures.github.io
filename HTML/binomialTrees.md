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
  <img src="../images/binomialTreeExamples">
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
<i>n=17</i>, the binomial heap representing it consist of two binomial trees 
B<sub>4</sub> and B<sub>1</sub> that correspond to 1 bits in binary representation of 17, i.e., 1001.

The deleteMin operation on a binomial heap is implemented by scanning all the roots of binomial trees that
constitue the heap. We can maintain the minimum of all roots in a separate variable, and update it whenever
it changes during a heap operation. Since binary representation has log <i>n</i> bits, deleteMin requires
O(log <i>n</i>). Merging two binomial heaps H<sub>1</sub> and H<sub>2</sub> is quite easy. 
The merging of binomial trees of same orders in H<sub>1</sub> and H<sub>2</sub> is carried out
until no pair of binomial trees of same order is left. Let us take an example to illustrate the merging
process. Suppose 

1. H<sub>1</sub> consists of three trees B<sub>0</sub>, B<sub>1</sub>, B<sub>2</sub>.
2. H<sub>2</sub> consists of two trees B<sub>1</sub>, B<sub>3</sub>.

A straightforward merging cannot maintain heap property. To maintain heap property, we choose 
the larger of the roots of the pair of trees a child of the smaller. In the first merging operation 
we choose a B<sub>1</sub> from H<sub>1</sub> and another from H<sub>2</sub>. Merging these two trees
B<sub>2</sub>. Next, we take the B<sub>2</sub> from H<sub>1</sub> and merge it with the newly
generated tree B<sub>2</sub>. It produces a B<sub>3</sub>. So, in the third merging the new 
B<sub>3</sub> tree is merged with B<sub>3</sub> available in H<sub>2</sub>. Since only one B<sub>0</sub> 
is available, it cannot be merged. Therefore, merging process completes with two trees B<sub>0</sub>
and B<sub>4</sub>. The merging is illustrated below in Figure 2. 


