## More on Trees and Binary Trees

An internal node of a tree may have up to k > 0 children, where k is a finite number. That is the number of 
children of an internal node in tree may vary between 1 to k. The value k is known as the arity of the tree. 
If the children of a node in a tree are always programmatically accessed in the order they appear in the storage, then
it  is an ordered tree. If a program ignores the storage order of the children, then it treats the tree as unordered
Typically, the storage order children is assumed to be left to right order:
<ul>
  <li> The immediate predecessor sibling of a node is called its left sibling,</li>
  <li> and the immediate successor sibling is called the right sibling.</li>
</ul>  
We have learned that the terminology associated with trees is derived from family trees, especially, the
relationships among the nodes in a tree. However, we still require a few other 
associated terminology before going deeper into tree data structure. We discuss these with reference to the
diagram appearing below.
<p align="center">
<img src="https://github.com/rkgIITBh/data-structures.github.io/raw/gh-pages/images/tree_terminology.jpg" width="450" height="350">
 </p>
The root of the tree <i>a</i> is an <i>ancestor</i> of all nodes including itself. Similarly, all nodes including
<i>a</i> are descendants of <i>a</i>. However, the set of proper ancestors of a node excludes the node. Likewise, the
set of proper descendant of a node exclude itself. The level of the root is 0 and the children of root at level 1. In
general, if the level of a node is <i>i</i> then all its children at level <i>i+1</i>. For example,
<ul>
  <li> level of <i>a</i> in above tree is 0,</li>
  <li> nodes <i>b</i>, <i>c</i>, and <i>d</i> are at level 1,</li>
  <li> nodes <i>e</i>, <i>g</i>, and <i>h</i> are at level 2,</li> 
    <li> nodes <i>i</i>, <i>j</i>, and <i>k</i> are at level 3.</li> 
  </ul>
Alternatively, the level of a node is  known as the depth of the node, as it represents the number of links from 
the root to the concerned node. The depth of the farthest leaf node down from the root is equal to height of the
tree. In above example, the nodes at level 3 are farthest from the root. Therefore, the height of the tree is 3. 
<br>
<br>

Now let us deal with binary trees. If the arity of a tree T is two, then we call T as a binary tree. As explained in 
the previous blog
every node in a binary tree may have 0, or 1, or two children. We distinguish between the twp possible 
orientation of children of an internal node in a binary tree. Formally, the definition of a binary tree is 
as follows:
<div class="alert alert-success">
   <strong>Definition</strong> A binary tree may be an empty tree or a tree in which each node may have 
  no child, a left child, a right child or both a left and a right child.  
</div>
<br>
<br>
For the purpose of illustration, we draw the left child o node to the left of the vertical passing through 
it, and the right child to the right of the vertical. The figure below illustrates a binary tree with 7 nodes. The 
root is labeled as R 
<p align="center">
<img src="https://github.com/rkgIITBh/data-structures.github.io/raw/gh-pages/images/binary_tree.jpg" width="250" height="200">
 </p>
The next blog will focus on traversals of binary trees.
