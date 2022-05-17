## Deletion Operations on Red-Black Trees (Examples)

We have studied the principles governing deletion operation on red-black trees in the previous blog. In this blog 
our focus is on the applications of these principles on specific examples. Let us start with an example of a red-black tree. Consider the tree below:

<p style="text-align:center;"><img src="../images/rbtDeletion_ex1.jpg"></p>

Suppose we want to delete 7. Since 7 is a black node, its deletion creates an excess of black color with a leaf node 
that replaces 7 as in the above figure. We need to remove the excess black by restructuring 
and color compensation. The sibling of the leaf with excess black is 5. Its both children are black. Thererfore, the 
configuration fits into subcase 1 of case 2 that we have discussed in the previous blog. We just need to flip the
color of the sibling 5 to red. The result is given below.

<p style="text-align:center;"><img src="../images/rbtDeletion_ex1solved.jpg"></p>

The black height of 5 becomes 1. Now eliminate the excess color from right leaf of 6. It balances the black height of right 
and left subtrees of 6. The black heights of the subtrees of the root 4 also are also balanced. 

