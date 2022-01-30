## Fixing Height Violation in AVL Tree

Let <i>h</i> be the height of an AVL tree T before an insertion. After a new insertion, one of the following conditions may occur:

- No height violation is caused, or
- A height violation is caused. 

The first case requires no fixing or rotation, as the height invariance is maintained at every node. The BST property is maintained by the insertion.
Therefore, the tree preserves both height balance property and the BST property.  

A height violation may occur after an insertion into <pre><code>$T_R$</code></pre> where T_R is the right subtree of T. We only consider the insertions into 
T_R. Symmetric cases occur if the insertion were made to T<sub>L</sub>. 
<p align="center">
<img src="../images/htVioAVL1.jpg">
</p>

T_R must be as taller than T_L for the height violation to take place. Since the height of the orignal tree T is <i>h</i>,   

- The height of T<sub>R</sub> should be <i>h-1</i>, and 
- The height of T<sub>L</sub> should be <i>h-2</i>. 

After an insertion the height of T_R becomes <i>h</i>, and the height of T becomes <i>h+1</i>. The difference between heights of T_R and 
T_L increase to 2. Obviously, T_R cannot be empty. If so, then T_L is empty, and <i>h = 0</i>. Let us expand T_R into its components subtrees.

- Its left subtree is referred to as inner tree and denoted by T_{in},
- Its right subtree is referred as outer tree, and denote by T_{out}. 

Let us consider insertion in T<sub>out</sub>. What would be heights of T<sub>in</sub> and T<sub>out</sub>? For a height violation, the height of T<sub>out</sub>
should be as high as possible. Therefore, 

- The height of T<sub>out</sub> should be <i>h-2</i>

The insertion can be either in T<sub>out</sub> or T<sub>in</sub>.  The first figure below illustrates the insertion into T<sub>o</sub> 
<p align="center">
<img src="../images/htVioAVL2.jpg">
</p>
The second depicts the insertion scenario for T<sub>in</sub>. 
<p align="center">
<img src="../images/htVioAVL3.jpg">
</p>

Let us examine the two scenarios in the figures above. In the first one, the height of T<sub>in</sub> can be either <i>h-3</i> or <i>h-2</i>. 
The height violation takes place only if T<sub>out</sub> is as tall as possible. Its height should be <i>h-2</i>. If the height of T<sub>in</sub> 
is <i>h-3</i>, then the lowest node where height violation occurs at the root of T<sub>R</sub>. Fixing height violation at the lowest node autmatically
resolve height violations at ancestors.
<p align="center">
<img src="../images/htVioAVL4.jpg">
</p>
If T<sub>in</sub>'s height is <i>h-2</i>, then a single left rotation should be ok to fix the tree. We have already proved that left rotation preserves BST
property. The next figure illustrates the case of both subtrees with same height.
<p align="center">
<img src="../images/htVioAVL5.jpg">
</p>

We leave it to the reader to convince that a similar set of arguments can prove that fixing height violation at the lowest node restores height invariant for 
the AVL tree. However, double rotations are needed for fixing height violations due to insertions in T<sub>in</sub>.

[Back to Index](../index.md)
