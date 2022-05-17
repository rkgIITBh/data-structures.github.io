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

Next consider deletion of 5. It does not create any double black node. Therefore, we can delete the node without any problem.
It is an example of the symmetric subcase 1 of case 1 of deletion explained earlier. The tree after deletion of 5 becomes:

<p style="text-align:center;"><img src="../images/rbt_ex1delete5.jpg"></p>

If we now remove 6 from the above tree, it creates excess black problem. Node 4's right child is a leaf with excess black. 
The configuration is a symmetric case of case 2 (black sibling with a red child).  Since both children of the black sibling
are red we can apply restructuring and color compensation for either of the two subcases. More preceisely, we apply a right
rotation on left sibling of the node with excess black. It pushes the sibling one level up and the parent one level down. 
Hence, the black heights at parent is adjusted appropriately. The result is shown in the figure below.

<p style="text-align:center;"><img src="../images/rbt_ex1delete6.jpg"></p>
