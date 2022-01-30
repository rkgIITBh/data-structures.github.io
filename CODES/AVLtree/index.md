## C Header File for Operations on AVL Tree

```
#ifndef AVL_H
#define AVL_H 
#define MAX(X,Y) ((X) < (Y)) ? (X) : (Y)

// Node structure for an AVL tree node
typedef struct node {
    int info;
    struct node *left;
    struct node *right;
    int ht;
} AVLNODE;

// Retrins height
int ht(AVLNODE *N) {
    if (N == NULL)
       return 0;
    return N->ht;
}

// Create a new AVL node
AVLNODE *createNode(int val) {
    AVLNODE *node = (AVLNODE *) malloc(sizeof(AVLNODE));
    if (node != NULL) {
        node->info = val;
        node->left = NULL;
        node->right = NULL;
        node->ht = 1;
        return (node);
    }
    else { 
        // Cannot create node, exit the program 
        printf("Error: malloc failed\n");
        exit(1); 
    }
}

// Right rotate
AVLNODE *rotateRight(AVLNODE *g) {
    // Tri-node forms a zig-zig pattern 
    AVLNODE *p = g->left;   // p goes to top 
    AVLNODE *T2 = p->right; // g > p > T2 

    p->right = g;  // p < g 
    g->left = T2;  // T2 < g 

    g->ht = MAX(ht(g->left), ht(g->right)) + 1; 
    p->ht = MAX(ht(p->left), ht(p->right)) + 1;

    return p;
}


// Single left rotate for zag-zag pattern 
AVLNODE *rotateLeft(AVLNODE *g) {
    // Tri-node forms a zag-zag pattern 
    AVLNODE *p = g->right; // y > x
    AVLNODE *T2 = p->left; // x < T2 < y  

    p->left = g;
    g->right = T2; 

    g->ht = MAX(ht(g->left), ht(g->right)) + 1;
    p->ht = MAX(ht(p->left), ht(p->right)) + 1;

    return p;
}

// Single right rotate for zig-zig pattern
AVLNODE *rotateRightLeft(AVLNODE *g) {
    // Double rotation for zig-zag pattern
    AVLNODE *p = g->left;
    AVLNODE *c = p->right;
    g->left = rotateLeft(c);
    return rotateRight(g);
} 

// Double rotation for zag-zig pattern
AVLNODE *rotateLeftRight(AVLNODE *g) {
    AVLNODE *p = g->right;
    AVLNODE *c = p->left;
    g->left = rotateRight(c);
    return rotateLeft(g);
} 

// Computes the balance factor
int getBF(AVLNODE *n) {
    if (n == NULL)
        return 0;
    return ht(n->left) - ht(n->right);
}

// Inserts node into an AVL tree
AVLNODE *insertNode(AVLNODE *node, int val) {
    
    int bf; // For computing balance factor
    
    // Find the position to insert the node 
    if (node == NULL)
        return (createNode(val));

    if (val < node->info) // Insert into left subtree
        node->left = insertNode(node->left, val);
    else if (val > node->info) // Insert into right subtree
        node->right = insertNode(node->right, val);
    else
        return node;

    // Update balance factor of each node 
    node->ht = 1 + MAX(ht(node->left), ht(node->right));

    bf = getBF(node);
    if (bf > 1 && val < node->left->info)
        return rotateRight(node);

    if (bf < -1 && val > node->right->info)
        return rotateLeft(node);

    if (bf > 1 && val > node->left->info) 
        return rotateLeftRight(node->left);
    

    if (bf < -1 && val < node->right->info) 
        return rotateRightLeft(node->right);

    return node;
}

AVLNODE *minValueNode(AVLNODE *node) {
    AVLNODE *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Delete a nodes
AVLNODE *deleteNode(AVLNODE *root, int val) {
    // Find the node and delete it
    if (root == NULL)
        return root;

    if (val < root->info)
        root->left = deleteNode(root->left, val);

    else if (val > root->info)
        root->right = deleteNode(root->right, val);

    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            AVLNODE *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
            *root = *temp;
            free(temp);
        } else {
            AVLNODE *temp = minValueNode(root->right);

            root->info = temp->info;

            root->right = deleteNode(root->right, temp->info);
        }
    }

    if (root == NULL)
        return root;

        // Update the balance factor of each node and
        // balance the tree
        root->ht = 1 + MAX(ht(root->left), ht(root->right));

        int bf = getBF(root);
        if (bf > 1 && getBF(root->left) >= 0)
            return rotateRight(root);

        if (bf > 1 && getBF(root->left) < 0) 
            return rotateLeftRight(root->left);
        

        if (bf < -1 && getBF(root->right) <= 0)
            return rotateLeft(root);

        if (bf < -1 && getBF(root->right) > 0) 
            return rotateRightLeft(root->right); 

        return root;
}

// Print tree in inOrder
void printInOrder(AVLNODE *root) {
    if (root != NULL) {
         printInOrder(root->left);
         printf("%d ", root->info);
         printInOrder(root->right);
    }
}

// Print tree in preOrder
void printPreOrder(AVLNODE *root) {
    if (root != NULL) {
         printf("%d ", root->info);
         printPreOrder(root->left);
         printPreOrder(root->right);
    }
}

// Print tree in postOrder
void printPostOrder(AVLNODE *root) {
    if (root != NULL) {
         printPostOrder(root->left);
         printPostOrder(root->right);
         printf("%d ", root->info);
    }
}

#endif
```
