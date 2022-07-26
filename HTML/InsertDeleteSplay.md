## Basic Operations on Splay Trees

We have learned about splaying operations on a BST. We have also learned about insert, delete, and
search operations on BST. Now we consider how these basic operations are implementable for spay 
trees. We use a basic structure of nodes. A splay tree node does not require any extra information
bit like AVL or Red Black tree. But splaying needs parent information. So, the definitions of
a splay tree and its node are as follows:
```
typedef struct node {
   int info; // Information field
   struct node *left; // Left child ptr
   struct node *right; // Right child ptr
   struct node *parent; // Parent ptr
} NODE;

typedef struct splay_tree {
   struct node *root;  // Root of the tree
} SPLAYTREE;
```
The left and right rotations are fundamental to a splay operation. We have already explained the 
rotations in the first blog on splay tree. So, we now deal with implementation of the rotation
operations. A double operation is a sequence of two rotations. So we need to focus only on 
two different types of single rotations: left and right rotations. The code inlcudes explanatory 
enough comments. Further the two rotations are symmetric. Therefore, it suffices to
focus on important points of the implementation of only one rotation. 

Let us consider left rotation. A node and its right child are involved in a left rotation. For 
completeness of description let us diagrammatically view the rotation once again.
<p style="text-align:center">
     <img src="../images/leftRotation.png">
</p>
The diagram does not show the part of the tree above <i>g</i>. The subtrees retain their topological 
positions after rotation. 
                                          
- The left subtree of <i>x</i> is linked as right subtree of <i>p</i>. 
- Node <i>g</i> becomes parent of <i>x</i>.
- Node <i>p</i> becomes left child of <i>x</i>.    
                                          
The code is exactly modifying the links as explained above. The readers may go through the embedded
comments in the code and observe the same. There are some corner cases such as handling the case when
the left subtree of <i>x</i> is NULL or the <i>p</i> is the root. The reader can easily understand the
code. 
                                          
```
void leftRotate(SPLAYTREE *t, NODE *p) {
   // Left rotation node p and g
   NODE *x = p->right;  // Get p's right child
   p->right = x->left;  
   if(x->left != NULL) {
        // p is now parent of x's left child
        x->left->parent = p;
   }
   // Grandparent adopts x as child
   x->parent = p->parent; 
   if(p->parent == NULL) { 
        // If parent was root, make x new root
        t->root = x; 
   } else if(p == p->parent->left) { 
        // p was left child of its parent
        p->parent->left = x;
   } else { 
        // p was right child of its parent
        p->parent->right = x; 
   }
   // p is now left child of x
   x->left = p; 
   p->parent = x; 
}

void rightRotate(SPLAYTREE *t, NODE *p) {
   // Rotation with reference to the parent node
   // Left child and parent to be rotated right 
   NODE *x = p->left;
   p->left = x->right;
   if(x->right != NULL) {
        // p is now parent of x's right child
        x->right->parent = p;
   }
   // Grandparent adopts x as child
   x->parent = p->parent;
   if(p->parent == NULL) { 
        // If p was root make x as new root
        t->root = x;
   }
   else if(p == p->parent->right) {
        // p is left child
        p->parent->right = x;
   }
   else {
        // p is right child
        p->parent->left = x;
   }
   // p is now left child of x
   x->right = p;
   p->parent = x;
}
```
The next basic operation is splaying. Splaying is applied whenever a node is accessed. As already
explained, splaying brings the accessed node to the root's position. It requires repeated rotations
depending on the different patterns for a tri-node configuration consisting of the node, its 
parent, and its grandparent. We apply either a double right 
or a double LR rotation depending on the configuration. However, a single rotation is sufficient if the accessed node's parent is the root. The code for splaying appears below. We have inserted enough comments to explain the rotation type corresponding to the node configuration, its parent, and its
grandparent.

```
void splay(SPLAYTREE *t, NODE *n) {
   while(n->parent != NULL) { 
        // n is not the root
        if(n->parent == t->root) { 
             // n is a child of the root
             // apply single rotation
             if(n == n->parent->left) {
                  // Zig pattern
                  rightRotate(t, n->parent);
             }
             else {
                  // Zag pattern
                  leftRotate(t, n->parent);
             }
        }
        else {
             NODE *p = n->parent;
             NODE *g = p->parent; // Grandparent of n

             if(n->parent->left == n && p->parent->left == p) {
                  // Zig-zig pattern
                  rightRotate(t, g);
                  rightRotate(t, p);
             } else if(n->parent->right == n && p->parent->right == p) {
                 // Zag-zag pattern
                  leftRotate(t, g);
                  leftRotate(t, p);
             } else if(n->parent->right == n && p->parent->left == p) {
                  // Zag-zig pattern
                  leftRotate(t, p);
                  rightRotate(t, g);
             } else if(n->parent->left == n && p->parent->right == p) {
                  // Zig-zag pattern 
                  rightRotate(t, p);
                  leftRotate(t, g);
             }
       }
   }
}


```
Insert and delete operations are similar to corresponding BST operations except that splaying is
needed after acessing the node. We, therefore, leave it to the readers to convince themselves 
that the code works as expected.

[C Program for Splay Trees](../CODES/SplayTree/index.md)

[Back to Index](../index.md)
