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
<p>
  <img src="../images/

In case of binary trees <i>k=2</i>. We distinguish between two the subtrees The subtrees as  the left subtree and the right subtree.  
