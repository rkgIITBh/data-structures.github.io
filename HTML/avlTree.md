## Maintaining a Balanced Binary Search Tree

The average case analysis of Binary Search Trees (BST) shows that any operation (search, insertion, deletion)  on balanced BSTs requires the worst-case time of 
<i>O(log n)</i>. Before proceeding further, let us formally define the balance property. 

<strong>Balance Property</strong>: A BST possesses balance property if the difference between the heights of the left and the right subtrees of every node of the tree is 1, 0, or -1. 

A leaf node has no left or right child. Therefore, the height difference between its left and right subtree is 0. In other words, every leaf node
of a binary tree possesses the balance property.

We cannot always depend on a nice random input distribution to expect that the tree to preserve balance property. However, as a BST undergoes a series of 
insertions and deletions, the balance property is disturbed. Therefore, for the worst-case time of <i>O(log n)</i> per operation on a BST, it should maintain 
balance property in the presence of a sequence of insertions and deletions that can happen in any order. It implies that we need to address the following 
question. 

- How the balance property be restored after each mutating operation, like insertion or deletions, on a BST? 

We view an insertion or a deletion as a mutating operation because such an operation modifies the BST. On the other hand, a search is a non-mutating operation 
because it never alters a tree. 

Adelson-Velsky-Landis (AVL) came up a recursive O(1) operation to balance a BST if it loses the balance property. The operation is known as <b>rotation</b>. 
A rotation is required after an operation if a disbalance occursat node in the tree. AVL tree also requires each node to maintain height information along with
other required information as needed for a BST node. We use a define an AVL tree node minimally as follows:
```
typedef struct node {
    int info, ht;
    struct node *left,*right;
} AVLNODE;
```

Since the AVL tree is a BST, the normal operations of the BST apply to an AVL tree. However, often a mutating operation causes a disbalance at a node. 
AVL tree augments BST by incorporating additional features to restore balance after mutating. 

The operation which restores balance is known as rotation. A rotation involves a tri-node structure in a BST. The tri-node structure consists of 
- A node where balance factore is disturbed,
- One of its child and
- One of its grandchild.

There rotation types depends on the pattern formed by the tri-node structure mentioned above. There are two types of rotations:
- A single rotation
- A double rotation

A single rotation may either be a left or a right rotation, depending on the direction of rotation. The left rotation applies to the pattern where the 
imbalance at a node occurs due to the left subtree of its left child. We refer the tri-node configuration  a <b>zig-zig</b> configuration if the balance factor
at a node is distrubed due to a mutating operations subtrees of the node. Essentially, we use "<b>zig</b>" to refer to a left and "<b>zag</b>" to refer to
a right branch.  A single right rotation can restore the balance in the case of a zig-zig pattern. The figure
below illustrates the zig-zig tri-node configuration and the result of a single right rotation.
<p align="center">
<img src="../images/avlSingleRight.jpg">
</p>
On the other hand, if the tri-node configuration forms a <b>zag-zag</b> pattern, it implies that the balance factor of a node is disturbed due to a sequence of 
insertions in its subtrees. A single left rotation shown below can restores the balance. 
<p align="center">
<img src="../images/avlSingleLeft.jpg">
</p>
The imbalance at a node can occur due to the right subtree of the left child of a node in a BST; we refer to the configuration of tri-node structure as 
<b>zig-zag</b> pattern. We can observe that rotation operation preserves BST property. Consider the right rotation, it changes parent pointers of at most
four subtrees T<sub>1</sub>, T<sub>2</sub>, T<sub>3</sub>, T<sub>4</sub> of node labeled c, p and g respectively. Since p goes to top and its value is smaller
than g. Further g's right subtree T<sub>4</sub> has elements larger than g; and therefore, p is smaller than the elements of T<sub>4</sub>. It implies  both
g and its right subtree T<sub>4</sub> are correctly placed by the right rotation. Similarly, c being left child of p, both of its subtrees T<sub>1</sub> and 
T<sub>2</sub> are correctly placed with respect to p. But p loses its right subtree T<sub>3</sub> which now becomes right subtree of g. Since T<sub>3</sub> 
consists of elements larger than p but smaller than g. Therefore, by placing T<sub>3</sub> as left subtree of g, the BST property is preserved.  

There is also a symmetric pattern of <b>zag-zig</b> where the tri-node structure consists of a node, its right child, and its left grandchild. A single 
rotation cannot fix the balance in the case of a zig-zag or zag-zig configuration. The figure below indicates that a single rotation only flips one configuration 
to the other.

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
In contrast, a single right rotation on the zag-zig pattern converts it so zag-zag pattern. Now a single left rotation can restore the balance of the node. 
<p align="center">
<img src="../images/avlDoubleRL.jpg">
</p>

We end this blog here. But continue with AVL tree in the next blog.

[Back to Index](../index.md)


