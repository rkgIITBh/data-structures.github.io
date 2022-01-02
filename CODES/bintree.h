--
## Source code for Binary Trees
--
    
```
#ifndef B_TREE_H
#define B_TREE_H
typedef struct treenode {
    int info;
    struct treenode * left;
    struct treenode * right;
} TREENODE;

void preOrder(TREENODE *t) {
    if (t != NULL) {
        printf("%d\t", t->info);
        preOrder(t->left);
        preOrder(t->right);
    }
}

void postOrder(TREENODE *t) {
    if (t != NULL) {
        postOrder(t->left);
        postOrder(t->right);
        printf("%d\t", t->info);
    }
}

void inOrder(TREENODE *t) {
    if (t != NULL) {
        inOrder(t->left);
        printf("%d\t", t->info);
        inOrder(t->right);
    }
}

TREENODE * createNode() {
    TREENODE *p;
    int x;
    printf("Enter data:");
    scanf("%d",&x);
    if (x == -1) 
        return NULL;
    else {
        p = (TREENODE *) malloc(sizeof(TREENODE));
        if (p != NULL) {
            p->info = x;
            printf("p->info = %d\n",p->info);
            p->left = NULL;
            p->right = NULL;
         }
         return p;
    }
}

TREENODE * createBinaryTree() {
    TREENODE * p;
    p = createNode();
    if (p != NULL) {
        p->left = createBinaryTree();
        p->right = createBinaryTree();
    }
    return p;
    printf("done\n");
}

TREENODE * search(TREENODE * t, int x) { 
    TREENODE *p ;
    if ((t == NULL) || ( t->info == x))
       return t ;
    p = search(t->left, x);
    if (p == NULL) 
        p = search(t->right, x) ;
    return p;
}

int isInternal(TREENODE *t) {
    int n = 0;
    n = (t != NULL) && ((t->left != NULL) || (t->right != NULL)) ;
    return n;
}

int treeHeight(TREENODE *t) {
   int rHeight, lHeight;
   int maxHeight = -1;
   if(t == NULL) {
     return -1; 
   } else {
      lHeight = treeHeight(t->left); 
      rHeight = treeHeight(t->right);
      if (rHeight > lHeight) {
          if (maxHeight < rHeight)
              maxHeight = rHeight; 
      } else {
          if (maxHeight < lHeight)
              maxHeight = lHeight; 
     }
     return maxHeight+1;
    }
}

int treeSize(TREENODE *t) {
    int size;
    if (t == NULL) 
        return 0;
    else {
        size = 1 + treeSize(t->left) + treeSize(t->right);
        return size;
    }
}
#endif
```
