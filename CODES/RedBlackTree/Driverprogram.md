Preorder and inorder lists can be used to reconstruct the tree. The input may included repeated elements. In case of repeated
elements, one becomes the parent of the other repeated element. 

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Needed for random seed 
#include "rbTree.h"
int main() {
    RBTREE *t = createRBtree();
    int r;
    RBNODE *a; 
    
    srand(time(0));
    printf("Input");
    printf("\n------------ \n");
    for (int i=0; i < 12; i++) {
        r = randNumber(); 
        a = createRBnode(r);
        printf("%d ", a->info); // Print input
        insert (t, a);
    }
    printf("\n------------ \n");

    printf("Inorder");
    printf("\n------------ \n");
   
    inorder(t, t->root);
    printf("\n------------ \n");

    printf("Preorder");
    printf("\n------------ \n");
   
    preorder(t, t->root);
    printf("\n------------ \n");

    return 0;
}
```
