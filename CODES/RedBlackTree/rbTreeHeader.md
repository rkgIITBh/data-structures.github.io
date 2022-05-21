The header file consists of functions required for implementation of red-black tree. The node structure consists of five
fields including three links. It uses a field for color and information. The rest of the fields are links to left, right 
and parent of the node. We use a separate structure for tree and a single dummy node representing external leaf. All 
leaf nodes have their right and left links pointing to this dummy external link. It saves allocation of space for external
leaves. In-line comments give further explanation of code.  
```
#ifndef RBTREE_H
#define RBTREE_H
enum COLOR {Red, Black}; // Can be read or Black

typedef struct node{
   int info;
   struct node *right;
   struct node *left;
   struct node *parent;
   enum COLOR color;
} RBNODE;

typedef struct tree {
   RBNODE *root; // Initially each node is a tree 
   RBNODE *NIL;  // Single dummy node for external leaves 
} RBTREE;

RBNODE * createRBnode(int data) {
   RBNODE * temp = malloc(sizeof(RBNODE));
   temp->left = NULL;
   temp->right = NULL;
   temp->parent = NULL;
   temp->info = data;
   temp->color = Red;

   return temp;
}

RBTREE * createRBtree() {
    
   // Defines a new tree
   RBTREE *t = malloc(sizeof(RBTREE)); 
   

   // Create a dummy null node
   RBNODE *temp = malloc (sizeof(RBNODE));

   temp->left = NULL; 
   temp->right = NULL;
   temp->parent = NULL;
   temp->color = Black;
   temp->info = 0; 

   // Define a dummy tree node 
   t->NIL = temp;  
   
   // Set root to dummy node 
   t->root = t->NIL;  

   return t;
}

void leftRotate(RBTREE *t, RBNODE *x) {
    
    // Left rotate about x  
    RBNODE *y = x->right;

    x->right = y->left; // 
    if(y->left != t->NIL) { // y->left not an dummy external leaf
        y->left->parent = x;
    }
    y->parent = x->parent; // Set grandparent as parent
    if(x->parent == t->NIL) { //x is the root & slips 1 level down 
        t->root = y; // y is promoted to root  
    }
    else if(x == x->parent->left) { //x is left child
        x->parent->left = y;
    }
    else { //x is right child
        x->parent->right = y;
    }
    y->left = x; // y is promoted level up
    x->parent = y; // x slips down one level
}

void rightRotate(RBTREE *t, RBNODE *x) {
    
    // Right rotate about x
    RBNODE *y = x->left;
    x->left = y->right;
    if(y->right != t->NIL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == t->NIL) { //x is root
        t->root = y;
    }
    else if(x == x->parent->right) { //x is left child
        x->parent->right = y;
    }
    else { //x is right child
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void insertionFixup(RBTREE *t, RBNODE *z) {
    while(z->parent->color == Red) {
        if(z->parent == z->parent->parent->left) { // z.parent is the left child

             RBNODE *y = z->parent->parent->right; // Uncle of z

             if(y->color == Red) { // Case 1
                  z->parent->color = Black;
                  y->color = Black;
                  z->parent->parent->color = Red;
                  z = z->parent->parent;
             }
             else { //case2 or case3
                  if(z == z->parent->right) { // Case2
                       z = z->parent; // Marked z->parent as new z
                       leftRotate(t, z);
                  }
                  // Case3
                  z->parent->color = Black; //Recolor parent black
                  z->parent->parent->color = Red; // Recolor grandparent red
                  rightRotate(t, z->parent->parent);
             }
        }
        else { //z.parent is the right child
             RBNODE *y = z->parent->parent->left; // Uncle of z

             if(y->color == Red) {
                   z->parent->color = Black;
                   y->color = Black;
                   z->parent->parent->color = Red;
                   z = z->parent->parent;
             }
             else {
                  if(z == z->parent->left) {
                       z = z->parent; // Marked z->parent as new z
                       rightRotate(t, z);
                  }
                  z->parent->color = Black; // Recolor parent black
                  z->parent->parent->color = Red; // Recolor grandparent red
                  leftRotate(t, z->parent->parent);
             }
        }
     }
     t->root->color = Black;
}

void insert(RBTREE *t, RBNODE *z) {
     RBNODE* y = t->NIL; // Denotes the parent of the added node
     RBNODE* temp = t->root;

     while(temp != t->NIL) {
        y = temp;
        if(z->info < temp->info)
            temp = temp->left;
        else
            temp = temp->right;
     }
     z->parent = y;

     if(y == t->NIL) { // New incoming node is root
          t->root = z;
     }
     else if(z->info < y->info) // Data of child is smaller than its parent, left child
          y->left = z;
     else
          y->right = z;

     z->right = t->NIL;
     z->left = t->NIL;

     insertionFixup(t, z);
}

void inorder(RBTREE *t, RBNODE *n) {
     if(n != t->NIL) {
        inorder(t, n->left);
        printf("%d(%d) ", n->info, n->color);
        inorder(t, n->right);
     }
}
void preorder(RBTREE *t, RBNODE *n) {
     if(n != t->NIL) {
        printf("%d(%d) ", n->info, n->color);
        preorder(t, n->left);
        preorder(t, n->right);
     }
}

int randNumber() {
    return (rand()%100);
}
#endif
```

[Back to Insertion Examples](../../HTML/rbInsertionExamples.md)
