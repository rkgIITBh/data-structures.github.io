## Deletion Operations on Red-Black Trees (Examples)

We have studied the principles governing deletion operation on red-black trees in the previous blog. In this blog 
our focus is on the applications of these principles on specific examples. Let us start with an example of a red-black tree. Consider the tree below:

<p style="text-align:center;"><img src="../images/rbtDeletion_ex1.jpg"></p>

Suppose we want to delete 7. Since 7 is a black node, its deletion creates an access black with leaf node 
replacing 7 as shown in the right half of the above figure. We need to remove the excess black by restructuring 
and color compensation. As we can see sibling is black with black children. It fits into subcase 1 of case 2.
We just need to recolor the sibling to red. The result is given below.

<p style="text-align:center;"><img src="../images/rbtDeletion_ex1solved.jpg"></p>

Flip the color of the sibling 5 from black to red. It reduces the black height of 5  to 1. Now eliminate the excess 
color from right leaf of 6. It reduces the black height of right subtree of 6 which becomes 1. Therefore, the left and 
subtrees of 6 are balanced. The black heights of the subtrees of the root 4 are also become balanced. 

