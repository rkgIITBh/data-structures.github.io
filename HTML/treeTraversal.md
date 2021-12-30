## Traversal of Binary Trees

The processing of information in a tree data structure requires each node of the tree to be accessed at least once. A tree is accessible from its root node. 
As every node stores a pointer to its children, we can access  the children of a given node. Therefore, starting with the root, it is possible to access all
nodes by repeatedly following the children pointers from the node which has been visited. The three possible way of traversing a tree are: 
<ul>
  <li> Preorder traversal</li>
  <li> Postorder traversal</li>
  <li> Inorder traversal</li>
  </ul>
The output of a traversal procedure is a list of nodes ordered by their visit sequence.  It is convenient to visualize the each traversals as a recursive procedure: 
<ol>
  <li> If the tree is empty then the empty sequence represents the preorder/postorder/inorder traversal list for the given tree </li>
  <li> If the tree consists of oonly the root node then root is also the sequence of preorder/postorder/inorder traveral list of the tree.</li>
    <li> If tree consists of root <i>r</i>, and <i>k</i> subtrees T<sub>1</sub>, T<sub>2</sub>, ..., T<sub>k</sub>.
      <ul>
        <li> Preorder traversal of T is sequence obtained by the root concatenated with preorder traversal sequences of T<sub>1</sub>, T<sub>2</sub>, ...,
          T<sub>k</sub>. </li>
        <li> Postorder traversal of T is sequence obtained by the concatenation of postorder traversal sequences of T<sub>1</sub>, T<sub>2</sub>, ...,
          T<sub>k</sub>. </li> then the root.
      <li> Inorder traversal of T is sequence obtained by the concatenation of inorder traversal sequences of T<sub>1</sub> followed by the root then 
      the inorder sequences of subtrees T<sub>2</sub>, ..., and T<sub>k</sub>. </li>
    </ol>
    </ul>


In case of binary trees <i>k=2</i>. The subtrees of the toot of a binary tree are referred to as the left subtree and the right subtree.  
