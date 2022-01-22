## AVL Tree

The average case analysis of Binary Search Trees (BST) shows that any operation (search, insertion, deletion)  on balanced BSTs requires the worst-case time of 
<i>O(log n)</i>. Before proceeding further, let us formally define the balance property. 

<strong>Balance Property</strong>: A BST possesses balance property if the difference between the heights of the left and the right subtrees of every node of the tree is 1, 0, or -1. 

A leaf node has no left or right child. Therefore, the height difference between its left and right subtree is 0. In other words, every leaf node
of a binary tree possesses the balance property.

We cannot always depend on a nice random input distribution to expect the tree to preserve balance property. However, as a BST undergoes a series of insertions 
and deletions, the balance property is disturbed. Therefore, for the worst-case time of <i>O(log n)</i> per operation on a BST, it should maintain balance property in the presence of a sequence of insertions and deletions that can happen in any order. It implies that we need to address the following question. 

How could the balance property in a BST be restored after each mutating operation, like insertion or deletions? 

We refer to an insertion or a deletion as a mutating operation because such an operation modifies the BST. On the other hand, a search is a non-mutating operation because it never alters a tree. 

Adelson-Velsky-Landis (AVL) proposed a recursive O(1) operation to balance a BST if it loses the balance property. The operation is known as rotation. 
Rotation is required after every operation when a disbalance occurs in the tree. AVL tree also requires a node to maintain height information and 
other required information as needed for a BST node. We use a define an AVL tree node minimally as follows:
```
typedef struct node {
    int info, ht;
    struct node *left,*right;
} AVLNODE;
```

Since the AVL tree is a BST, the rest of the BST operations apply to an AVL tree. However, often a mutating operation causes a disbalance at a node. 
AVL tree augments BST by incorporating additional features to restore balance after mutating. 

The operation which restores balance is known as rotation. A rotation involves a tri-node structure in a BST. The tri-node structure consists of 
- a node, one of its child and its grandchild.
There are two types of rotations:
- A single rotation
- A double rotation

A single rotation may either be a left or a right rotation, depending on the direction of rotation. The left rotation applies to the pattern where the 
imbalance of node occurs due to a left subtree of its left child. The tri-node configuration involving an imbalanced node, its left child, and its left grandchild form a pattern we refer to as a zig-zig pattern. A single rotation can restore the balance in the case of a left zig-zig pattern. The figure
below illustrates the tri-node configuration and the result of a single left rotation.
<p align="center">
<img src="../images/avlSingleLeft.jpg">
</p>
On the other hand, if the tri-node configuration forms a zag-zag pattern (consisting node, its right child and right grand child), a  single right rotation
can restores the balance. A single right rotation has been illustrated in the figure below.
<p align="center">
<img src="../images/avlSingleRight.jpg">
</p>

Imbalance at a node can occur due to the right subtree of the left child of a node in a BST; we refer to the configuration of tri-node structure as zig-zag patter. There 
is also a symmetric pattern of zag-zig where the tri-node structure consists of a node, its right child, and its left grandchild. A single rotation cannot fix the
balance in the case of a zig-zag or zag-zig configuration. The figure below indicates that a single rotation only flips one configuration to the other.
<p align="center">
    <img src="../images/needForDR.jpg">
</p>
A double rotation consists of two rotations in sequence. It is either 
- A single right followed by a single left rotation, or
- A single left followed by a single right rotation.

The two rotations types are shown in the figures below. In the first figure we consider the tri-node configuration forming a zig-zag pattern. The first rotation
converts the tri-node configuration to zig-zig pattern. Therefore, a single right rotation can restore the balance factors of the node. 
<p align="center">
<img src="../images/avlDoubleLR.jpg">
</p>
In contrast, a single right rotation on the zig-zag pattern converts it so zag-zag pattern. Now a single left rotation can restore the balance of the node. 
<p align="center">
<img src="../images/avlDoubleRL.jpg">
</p>




