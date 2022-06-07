<strong>Deletion:</strong> If the element <i>x</i> for deletion is not located in a leaf then we can replace <i>x</i> by
the largest element <i>y</i> in the left subtree of <i>x</i>. The key <i>y</i> must be located in a leaf node. So, the 
deletion process is essentially a generalization of the deletion in BST. All deletions occur in leaf nodes. It may lead to
an underflow. An underflow occurs when the number of keys in a leaf node is reduced to <i>M/2 - 1</i>. If the sibling 
node has surplus keys to share, keys can be moved to deficient node and restore the requirement of B-Tree. However, if 
the sibling has just <i>M/2</i> keys we can merge the two siblings to form one node. Merging may percolate up and 
require merging at a level up. When children of the root merge together to form one node a new root is created which
decrements the height by 1. Thus repeated deletions may lead to a reduction in tree height.
 
 
Before we describe the node structures, it is important to know about amortized cost.

<strong>Amortized cost:</strong> is defined over a sequence or a set of operations. If some operations of a given set are 
costly because future operations become cheap, we say time is amortized over the given set of operations. We have learned 
about amortized cost earlier in the context of <b>union</b> and <b>find</b> instructions on disjoint sets. The reader 
might remember that a sequence of O(<i>n</i>) unions and finds can be executed in O(<i>nG(n</i>)) time where <i>G(n)</i>
is an extremely slow-growing function. So, for all practical purpose, each operation of sequence take O(1) amortized
time. Loosely speaking, amortized time is time partitioned over many operations. We will return to amortized time in 
the analysis of B-Tree at a later point.

