## Height of AVL Tree

<strong>Height of AVL Tree</strong>: Prove that the height of an AVL tree with <i>n</i> nodes is <i>log n</i>.

Let <i>n(h)</i> be the minimum number of internal nodes in an AVL tree of height <i>h</i>. An AVL tree of height <i>h = 1</i> with of minimum 
number of internal nodes should have at least one internal node (which is the root). An AVL tree of height <i>h = 2</i> must have at least two
internal nodes as shown below. 
<p align="center">
<img src=../images/baseAVLTrees.jpg">
</p>
The AVL balance properties are satisfied by both the trees.

We now recursively define an AVL tree of height <i>h</i> with minimum number of internal nodes as follows:
- A root, which is an internal node,
- One left subtree <i>T<sub>L</sub></i> with minimum number of internal nodes, and
- One right subtree <i>T<sub>R</sub></i> with minimum number of internal nodes.

Without loss of generality, we assume that height of the left subtree <i>T<sub>L</sub></i> is <i>h-1</i>, and the height of right subtree 
<i>T<sub>R</sub></i> is <i>h-2</i>. So the minimum number of internal nodes in an AVL tree of height <i>h</i> is:
<p align="center">
<img src="https://latex.codecogs.com/svg.image?\begin{array}{rcl}n(h)&space;&&space;=&space;&&space;1&space;&plus;&space;n(h-1)&space;&plus;&space;n(h-2)\\&&space;>&space;&&space;2n(h-2)\end{array}" title="\begin{array}{rcl}n(h) & = & 1 + n(h-1) + n(h-2)\\& > & 2n(h-2)\end{array}" />
</p>

We now assume the induction hypothesis that the stated AVL height property holds for any AVL tree with height less than <i>h</i>.

By unrolling the inequality of recurrence relation repeatedly, we get
<p align="center">
<img src="https://latex.codecogs.com/svg.image?n(h)&space;=&space;2^i&space;n(h-2i)" title="n(h) = 2^i n(h-2i)" />
  </p>
Solving for the base case <i>n(1) = 1 </i>, we get
<p align+"center">
<img src="https://latex.codecogs.com/svg.image?n(h)&space;=&space;2^{h/2-1}" title="n(h) = 2^{h/2-1}" />
</p>

which implies <i>log n(h) > h/2-1</i>, or <i>h < 2log n(h) </i>.  
The total number of nodes in a tree is always greater than the the number of internal nodes in the tree. Therefore, the height of an AVL tree is 
  always less than <i>2 log n</i>, where <i>n</i> is the number of nodes in the AVL tree.