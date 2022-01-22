## AVL Tree

The average case analysis of Binary Search Trees (BST) shows that the any operation (search, inserion, deletion)  
on balanced BSTs requires worst-case time of <i>O(log n)</i>. Before proceeding further, let us formally define the balance property. 

<strong>Balance Property</strong>: A BST is possesses balance property if the difference between the heights of the left and the right subtrees of every node of the tree is 1, 0, or -1. 

A leaf node node has no left or right child. Therefore, the height difference between its left and right subtree is 0. In other words, every leaf node
of a binary tree possesses the balance property.

We cannot always depend a nice random input distribution to expect that the tree preserves balance property. 
However, as a BST undergoes a series of insertions and deletions, balance property is disturbed. 
Therefore, for the worst-case time of <i>O(log n)</i> per operation on BST, tree should maintain balance property in presence of a sequence of
insertions and deletions that can happen in any order. It basically implies that we need to address the following question. 

- How the balance property in a BST could be restored after each mutating operation like an insertion or a deletions? 

We refer to an insertion or a deletion as a mutating operation, because the BST is altered by such an operation. On the other hand, a search is a non-mutating operation because it never modifies a tree. 

Adelson-Velsky-Landis (AVL) proposed a recursive O(1) operation to balance a BST if it loses the balance property. The operation is known as rotation. 
Rotation is required after every operation when a disbalance occurs in the tree. AVL tree requires a node to also maintain height information along with 
other required information as needed for a BST node. We use a define an AVL tree node minimally as follows:
```
typedef struct node {
    int info, ht;
    struct node *left,*right;
} AVLNODE;
```

Since AVL tree is a BST, the rest of BST operations may be applied on an AVL tree. However, often a mutating operation causes a disbalance at a node. 
AVL tree augments BST by incorporating additinal features to restore balance after a mutating operation. 

The operation which restores balance is known as rotation. A rotation involves a tri-node structure in a BST. The tri-node structure consists of 
- a node, one of its child and its grand child.
There are two types rotations:
- A single rotation
- A double rotation
A double rotation consists of two single rotations applied in sequence. 

A single rotation may either be a left or a right rotation depending on the direction of rotation. Figure below illustrates single rotation types. 
<p align="center">
<img src="../images/avlSingleLeft.jpg">
</p>
<p align="center">
<img src="../images/avlSingleRight.jpg">
</p>
A single rotation is applicable to a pattern like above which we refer to as <i>zig-zig</i> pattern. A zig-zig pattern is formed due to one of the following configurations:

- The node losing balance, its left child and the left grand child. 
- The node losing balance, its right child and the right grand child. 

We can refer the first one as as <i>left zig-zig</i> and the second as the
<i>right zig-zig</i> pattern respectively.

Figure below illustrates two different double rotations types.
<p align="center">
<img src="../images/avlDoubleLR.jpg">

<img src="../images/avlDoubleRL.jpg">
</p>
A double rotation is applicable to a <i>zig-zag</i> or <i>zag-zig</i> pattern. 

- The zig-zag configuration consists of a node, its right child and the left grand child. 
- The zag-zig pattern consists of a node its left child and the right grand child.  

A double rotation consists of two single rotations in which the first rotation converts:

- A zig-zag pattern to a left zig-zig pattern, or
- A zag-zig pattern to a right zig-zig pattern.

Then applying another appropriate single rotation restores to the new zig-zig pattern restores the balance at the node. 


