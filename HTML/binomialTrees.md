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
- In general <i>i</i>th leftmost child is the root of a binomial tree of order  <i>i</i>

A binomial heap is based on binomial tree structure. If the binomial heap has <i>n</i> nodes then 
it has binomial trees equal to the number of 1 bits in binary representation of <i>n</i>. For example if
<i>n=</i>, then binary representation of 17 = 
