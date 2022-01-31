## C Header File for Operations on AVL Tree

```
#ifndef AVL_H
#define AVL_H

// Define AVL node structure
typedef struct Node {
    int info;
    struct Node *left;
    struct Node *right;
    int ht;
} AVLNODE;

// Get height of a node
int height(AVLNODE *N) {
    if (N == NULL)
        return 0;
    return N->ht;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a node
AVLNODE *createNode(int val) {
    AVLNODE *node = (AVLNODE *) malloc(sizeof(AVLNODE));
    if (node != NULL) {
        node->info = val;
        node->left = NULL;
        node->right = NULL;
        node->ht = 1;
    } else {
        printf("Error: malloc failure\n");
        exit(1);
    }
    return (node);
}

// Rotate right to fix zig-zig pattern of trinode configuration (g,p,c)
AVLNODE *rotateRight(AVLNODE *g) {
    AVLNODE *p = g->left;
    AVLNODE *T2 = p->right;

    p->right = g;
    g->left = T2;

    g->ht = max(height(g->left), height(g->right)) + 1;
    p->ht = max(height(p->left), height(p->right)) + 1;

    return p;
}

// Rotate left to fix zag-zag pattern of trinode configuration (g,p,c)
AVLNODE *rotateLeft(AVLNODE *g) {
    AVLNODE *p = g->right;
    AVLNODE *T2 = p->left;

    p->left = g;
    g->right = T2;

    g->ht = max(height(g->left), height(g->right)) + 1;
    p->ht = max(height(p->left), height(p->right)) + 1;

    return p;
}

// Get the balance factor of a node
int getBalance(AVLNODE *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Insert a node into an AVL tree. Similar to BST insertion except for rebalancing
AVLNODE *insertNode(AVLNODE *node, int val) {
    int bf; // Stores balance factor

    if (node == NULL)
        return (createNode(val)); 

    if (val < node->info)
        node->left = insertNode(node->left, val);
    else if (val > node->info)
        node->right = insertNode(node->right, val);
    else
        return node;

    // Update the balance factor of each node and rebalance the tree if needed 
    node->ht = 1 + max(height(node->left), height(node->right));

    bf = getBalance(node);
    if (bf > 1 && val < node->left->info)
        // Creates zig-zig pattern for tri-node
        return rotateRight(node);

    if (bf < -1 && val > node->right->info)
        // Creates zag-zag pattern for tri-node
        return rotateLeft(node);

    if (bf > 1 && val > node->left->info) {
        // Creates zig-zag pattern for tri-node
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (bf < -1 && val < node->right->info) {
        // Creates zag-zig pattern for tri-node
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Locate inorder successor of a node
AVLNODE *minValueNode(AVLNODE *node) {
    AVLNODE *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Deletes a node of the AVL tree
AVLNODE *deleteNode(AVLNODE *root, int val) {
    // Find the node and delete it
    int bf;  // Used for computing balance factor
    AVLNODE *temp; // Used for swapping and copying 
    
    if (root == NULL)
        return root;

    if (val < root->info)
        root->left = deleteNode(root->left, val);

    else if (val > root->info)
        root->right = deleteNode(root->right, val);

    else {
        // Located the node to be deleted
        if ((root->left == NULL) || (root->right == NULL)) {
            // May have either no child or one child
            temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp); // Free memory allocated for deleted node
        } else {
            // Node has two children, locate its inorder successor which will replace the deleted node
            temp = minValueNode(root->right);
            root->info = temp->info; // Copy value of inorder successor
            // Delete inorder successor will have one or no child
            root->right = deleteNode(root->right, temp->info);
        }
    }

    if (root == NULL)
        return root;

    // Update the balance factor of each node and rebalance the tree if needed
    root->ht = 1 + max(height(root->left), height(root->right));

    bf = getBalance(root);
    if (bf > 1 && getBalance(root->left) >= 0)
        // Trinode configuration creates zig-zig pattern
        return rotateRight(root);

    if (bf > 1 && getBalance(root->left) < 0) {
        // Trinode configuration creates zig-zag pattern
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (bf < -1 && getBalance(root->right) <= 0)
        // Trinode configuration creates zag-zag pattern
        return rotateLeft(root);

    if (bf < -1 && getBalance(root->right) > 0) {
        // Trinode configuration creates zag-zig pattern
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Print the tree with node heights in preorder. Inorder or Postorder printing can be used here
void printPreOrder(AVLNODE *root) {
    if (root != NULL) {
        printf("(%d,%d) ", root->info,root->ht);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

#endif
```

A driver program should be written to test out the code.

[Back to Index](../../index.md)
