```
#ifndef STACK_H
#define STACK_H

typedef struct stack {
    int top;
    int limit;
    int * info;
} STACK;


STACK * createStack(int capacity) {
     STACK *s = (STACK *) malloc(sizeof(STACK));
     if (s == NULL) {
         printf("Error:malloc failed\n");
         return s;
     }
     s->info = (int *) malloc(sizeof(int)*capacity);
     if (s->info == NULL) 
        printf("Error:malloc failed\n");
     s->top = -1;
     s->limit = capacity-1;
     printf("%d\n", s->top);
     return s;          
}

int isEmpty(STACK *s) {
    return (s->top == -1);
}

int isFull(STACK *s) {
     return s->top == s->limit;
}

int top(STACK *s) {
     if (isEmpty(s)) {
         printf("Error: stack empty\n");
         return -1;
     } else 
         return s->info[s->top]; 
}

void push(STACK *s, int element) {
    if(isFull(s)) {
        printf("Error: stack full\n") ;
        return ;
    }
    s->info[++s->top] = element ; // pointer to end of list
    return ;
}

int pop(STACK * s) {
    if (isEmpty(s)) {
         printf("Error: stack empty\n");
         return -999; // Indicates no element;
    } else 
         return s->info[s->top--];
}

void printStack(STACK *s) {
    int i;
    if(isEmpty(s)) {
        printf("Stack is empty\n") ;
        return ;
    }
    i = -1; 
    while (i < s->top) 
        printf ("%d\t", s->info[++i]) ; // print elements
    
    printf("\n") ;
    return ;
}
#endif
```
