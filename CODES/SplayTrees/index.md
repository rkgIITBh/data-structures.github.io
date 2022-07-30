```
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int info;
   struct node *left;
   struct node *right;
   struct node *parent;
} NODE;

typedef struct splay_tree {
   struct node *root;
} SPLAYTREE;

NODE* newNode(int i) {
   NODE *n = malloc(sizeof(NODE));
   n->info = i;
   n->parent = NULL;
   n->right = NULL;
   n->left = NULL;

   return n;
}

SPLAYTREE* newSplayTree() {
   SPLAYTREE *t = malloc(sizeof(SPLAYTREE));
   t->root = NULL;

   return t;
}

NODE* maximum(SPLAYTREE *t, NODE *x) {
   while(x->right != NULL)
        x = x->right;
   return x;
}

void leftRotate(SPLAYTREE *t, NODE *p) {
   // Rotation with reference to the parent node
   // Right child and parent to be rotated left 
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

void splay(SPLAYTREE *t, NODE *n) {
   while(n->parent != NULL) { 
        // n is not the root
        if(n->parent == t->root) { 
             // n is a child of the root
             // apply single rotation
             if(n == n->parent->left) {
                  rightRotate(t, n->parent);
             }
             else {
                  leftRotate(t, n->parent);
             }
        }
        else {
             NODE *p = n->parent;
             NODE *g = p->parent; // Grandparent of n

             if(n->parent->left == n && p->parent->left == p) {
                  // Both p and n are left children
                  rightRotate(t, g);
                  rightRotate(t, p);
             } else if(n->parent->right == n && p->parent->right == p) {
                 // Both p and n are right children
                  leftRotate(t, g);
                  leftRotate(t, p);
             } else if(n->parent->right == n && p->parent->left == p) {
                  leftRotate(t, p);
                  rightRotate(t, g);
             } else if(n->parent->left == n && p->parent->right == p) {
                  rightRotate(t, p);
                  leftRotate(t, g);
             }
       }
   }
}

void insert(SPLAYTREE *t, NODE *n) {
    NODE *y = NULL;
    NODE *temp = t->root;
    while(temp != NULL) {
          y = temp;
          // BST insertion
          if(n->info < temp->info)
                temp = temp->left;
          else
                temp = temp->right;
    }
    n->parent = y;

    if(y == NULL) { 
          // New node is the root
          t->root = n;
    } else if(n->info < y->info) {
          // New node is left child of parent
          y->left = n;
    }
    else {
          // New node is right child of parent
          y->right = n;
    }
    // Apply splay 
    splay(t, n);
}

NODE* search(SPLAYTREE *t, NODE *n, int x) {
    if(x == n->info) {
          splay(t, n);
          return n;
    } else if(x < n->info)
          return search(t, n->left, x);
    else if(x > n->info)
          return search(t, n->right, x);
    else
          return NULL;
}

void delete(SPLAYTREE *t, NODE *n) {
    
   // Splay brings the node to root
   splay(t, n);

   SPLAYTREE *leftSubtree = newSplayTree();
   leftSubtree->root = t->root->left;
   if(leftSubtree->root != NULL) {
        // Root of left subtree  is new root
        leftSubtree->root->parent = NULL;
   }

   SPLAYTREE *rightSubtree = newSplayTree();
   rightSubtree->root = t->root->right;
   if(rightSubtree->root != NULL) {
        // Root of left subtree  is new root
        rightSubtree->root->parent = NULL;
   }
   // Free old root's heap memory
   free(n);

   if(leftSubtree->root != NULL) {
        // Largest left descendant is new root 
        NODE *m = maximum(leftSubtree, leftSubtree->root);
        splay(leftSubtree, m);
        leftSubtree->root->right = rightSubtree->root;
        t->root = leftSubtree->root;
   } else {
        // Smallerst right descendant at the root
        t->root = rightSubtree->root;
   }
}

```

[Back to Splay Tree Operations](../HTML/InsertDeleteSplay.md)
