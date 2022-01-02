```
#ifndef LIST_H
#define LIST_H

typedef struct node {
    int info;
    struct node *next;
} NODE;

int isEmpty(NODE *list){
    return (list->next == NULL);
}

NODE * newNode() {
    NODE *p;
    p = (NODE *) malloc(sizeof(NODE));
    return p;
}

NODE * newList() {
    NODE *p = newNode();

    if (p != NULL) {
        p->info = -1;
        p->next = NULL;
        return p;
    } else { 
        printf("Memory allocation error\n");
        return NULL;
    }
}

NODE *firstNode(NODE *list) {
    return list->next;
}

NODE * findLast(NODE *list) {
    NODE *p = list;

    if (isEmpty(list)) 
        return p;
    while (p->next != NULL)
        p = p->next;
    printf("Last element %d\n",p->info);
    return p;
}

NODE * find(NODE *list, int x) {
    NODE *p = firstNode(list);

    if (p != NULL)  
        while (p->info != x && p->next != NULL) 
            p = p->next;

    return p;
}

NODE * findPred(NODE *list, int x) {
    NODE *q; // Previous
    NODE *p; // Next 
    
    if (isEmpty(list)) {
        printf("List empty\n");
        return list;
    }
    q = list; 
    p = q->next;
    while (p->info != x && p->next != NULL) {
        q = p; 
        p = p->next;
    }
    if (p->info == x) {
        printf("found %d\n",p->info);
        return q;
    } else
        return list;
}

NODE * findSucc(NODE *list, int x) {
    NODE *p = list;

    if (isEmpty(list)) {
        printf("List empty\n");
        return list;
    } 

    while (p->info != x) 
        p = p->next;
    
    if (p != NULL) 
        p = p->next;
    return p;
}


void printList(NODE *list) {
    NODE *p;
    if (isEmpty(list)) {
        printf("List is empty\n");
        return;
    }
    p = firstNode(list);
    while (p!=NULL) {
        printf("%d\t",p->info);
        p = p->next;
    }
    printf("\n");
    return;
}

void insertBefore(NODE *list, int x, int y) {
    NODE *pred = findPred(list,x);
    NODE *p, *r; 

    if (pred == NULL) { 
        printf("%d not found, insert failed\n",x);
        return;
    }

    p = newNode();
    if (p == NULL) {
       printf("Memory allocation error\n");
       return;
    }

    p->info = y;
    p->next = pred->next;
    pred->next = p;
    return;
}

void insertAfter(NODE * list, int x, int y) {
    NODE *p, *q;

    q = find(list, x);
    if (q != NULL) {
        p = newNode();
        if (p!=NULL) {
           p->info = y;
           p->next = q->next;
           q->next = p;
        } else
           printf("Memory allocation error\n");
    }
    return;
}

void prepend(NODE *list, int x) {
    NODE *p;

    p = newNode();
    if (p == NULL) {
        printf("Memory allocation error\n");
        return;
    }

    insertBefore(list,list->info,x);
    return;
}

// Could use insertAfter(), but it become inefficient 
void append(NODE *list, int x) {

    if (isEmpty(list)) {
        prepend(list, x);
        return;
    }

    NODE *last = findLast(list);

    NODE *p = newNode();
    if (p == NULL) { 
       printf("Memory allocation error\n");
       return;
    }
    p->info = x;
    p->next = NULL;
    last->next = p;
    return;
}

void removeVal(NODE *list, int x) {
    NODE *pred = findPred(list,x);

    pred = findPred(list, x);
    if (pred == NULL) {
        printf("%d is not present, remove failed\n", x);
        return;
    }

    NODE * succ = findSucc(list, x);
   
    pred->next = succ; 
    return;
}

int length(NODE * list) {
    NODE * p;
    int len = 0;
    if (isEmpty(list)) 
        return 0;
    p = list->next;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}
#endif
```
![Back to Index](../../index.md)
