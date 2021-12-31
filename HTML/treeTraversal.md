## Traversal of Binary Trees

The processing of information stored in a tree data structure requires each node of the tree to be accessed at least once. A tree is accessible only by
its root node. However, as every node stores a pointer to its children, it is possible to access the children of a node when the latter is visited. 
Therefore, starting with the root, we can ccess all nodes of a tree by repeatedly following the children pointers from the node which has just been visited.
The three systematic ways of traversing a tree are: 
<ul>
  <li> Preorder traversal</li>
  <li> Postorder traversal</li>
  <li> Inorder traversal</li>
  </ul>
The output of a traversal procedure is a list of nodes ordered by their visit sequence.  It is convenient to visualize the each traversals as a recursive 
procedure: 
<ol>
  <li> For an empty tree, the empty sequence represents the preorder/postorder/inorder traversal list. </li>
  <li> If a tree consists of oonly the root node, then the root node represents the preorder/postorder/inorder traveral list.</li>
    <li> In general a tree T may be assumed to consist of a root <i>r</i>, and <i>k</i> subtrees T<sub>1</sub>, T<sub>2</sub>, ..., T<sub>k</sub>. 
      <ul>
        <li> Preorder traversal of T is the list obtained by the root concatenated with preorder traversal lists of T<sub>1</sub>, T<sub>2</sub>, ...,
          T<sub>k</sub>. </li>
        <li> Postorder traversal of T is the list obtained by the concatenation of postorder traversal lists of T<sub>1</sub>, T<sub>2</sub>, ...,
          T<sub>k</sub>. </li> followed by the root.
      <li> Inorder traversal of T is the list obtained by the concatenation of inorder traversal list of T<sub>1</sub> followed by the root then 
      the inorder lists of subtrees T<sub>2</sub>, ..., and T<sub>k</sub>. </li>
    </ol>
    </ul>
Consider an example tree shown below to understand how the tree traversal procedures work.
<p align="center">
  <img src="../images/ordered_tree.jpg">
  </p>
The preorder traversal list of the above tree is obtained by concatenating four lists, namely, {1} with the preorder traversal lists of three subtrees T<sub>2</sub>,T<sub>3</sub>, and T<sub>4</sub>. Using the recursive extension of preorder traversal to the three subtrees of the root, we obtain:
<ul>
    <li> Preorder list of T<sub>2</sub>: {2},</li>
    <li> Preorder list of T<sub>3</sub>: {3,5,8,9,6,10},</li>
    <li> Preorder list of T<sub>4</sub>: {4,7},</li>
</ul>
Therefore, the concatenating four lists {1} {3,5,8,9,6} {4,7} gives preorder traversal list of T as: 1,3,5,8,9,6,10,4,7. In the same manner we 
can obtain the postorder and the inorder traversal lists as:
<ul>
  <li>Postorder: concatenate postorder lists of T<sub>1</sub>, T<sub>2</sub>, T<sub>3</sub> and {1}: {2}, {8,9.5,10,6,3}, {7,4} </li>
  <li>Inorder: concatenate inorder lists of T<sub>1</sub>, {1}, T<sub>2</sub>, T<sub>3</sub>: {2}, {1}, {8,5,9,3,10,6}, {7,4} </li>
</ul>  
For  binary trees <i>k=2</i>, we distinguish between two subtrees, the subtrees are referred to as the left subtree and the right subtree. 
The preorder, postorder and inorder traversals procedures are same as dicussed above but we can put them more compactly as follows:
<ul>
  <li> Preorder: visit the root, traverse left subtree in preorder, traverse the right subtree in preorder.</li>
  <li> Postorder: traverse left subtree in postorder, traverse the right subtree in postorder, visit the root.</li>
  <li> Inorder: traverse left subtree in inorder, visit the root, traverse the right subtree in inorder.</li>
  </ul>

