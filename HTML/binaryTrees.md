An internal node of a tree may have up to k > 0 children, where k is a finite number. That is the number of 
children of an internal node in tree may vary between 1 to k. The value k is known as the arity of the tree. 
If the children of a nod are always programmatically accessed in the order they appear in storage, then the 
tree is an ordered tree. If the prgoram ignores the storage order of the children, then we have an unordered
tree. Typically, storage order children is known as left to right order:
<ul>
  <li> The immediate predecessor sibling of a node is called its left sibling,</li>
  <li> and the immediate successor sibling is called the right sibling.</li>
</ul>    
If the arity of a tree T is two, then we call T as a binary tree. As explained in the previous blog
every node in a binary tree may have 0, or 1, or two children. We distinguish between the twp possible 
orientation of children of an internal node in a binary tree. Formally, the definition of a binary tree is 
as follows:
<div class="alert alert-success">
   <strong>Definition</strong> A binary tree may be an empty tree or a tree in which each node may have 
  no child, a left child, a right child or both a left and a right child.  
</div>
For the purpose of illustration, we draw the left child o node to the left of the vertical passing through 
it, and the right child to the right of the vertical. The figure below illustrates a binary tree with 7 nodes. The 
root is labeled as R 
<p align="center">
<img src="https://github.com/rkgIITBh/data-structures.github.io/raw/gh-pages/images/binary_tree.jpg" width="250" height="200">
 </p>
