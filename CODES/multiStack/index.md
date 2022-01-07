## Stack with Multiple Element Types 

```
#ifndef MSTACK_H
#define MSTACK_H
#define MAX 10

enum {
    INT, CHAR, FLOAT 
};

typedef struct items{
    int itemtype;
    union {
       int ival;
       float fval;
       char cval;
    } itemval;
} ITEMS;

typedef struct stack{
    int top;
    ITEMS * element;
} STACK;


STACK * createStack(){
    STACK *p;

    p = (STACK *) malloc(sizeof(STACK));
    if (p != NULL) {
        p->element = (ITEMS *) malloc(sizeof(ITEMS)*MAX);
        if (p->element != NULL) {
            p->top = -1;
            return p;
        }
    }
    return NULL;
}

void push(STACK *s, ITEMS * item) {
    if(s->top == MAX-1)
        printf("Stack Overflow\n");
    else
        s->element[++s->top] = *item;
}

ITEMS  pop(STACK *s) {
    if(s->top == -1)
        printf("Stack Underflow\n");
    else
        return s->element[s->top--];
}

void printStack(STACK *s) {
     printf("The Stack items are:\n");
     for(int i = 0; i <= s->top; i++) {
         printf("The index %d has type = ", i);
         switch(s->element[i].itemtype) {
             case INT : printf("INT and value = %d\n", s->element[i].itemval.ival); // Tag INT print int formatting string
                        break;
             case FLOAT: printf("FLOAT and value = %f\n", s->element[i].itemval.fval); // Tag FLOAT print float formatting string
                        break;
             case CHAR: printf("CHAR and value = %c\n", s->element[i].itemval.cval); // Tag CHAR print char formatting string
                        break;                        
             default : printf("Invalid data type\n");
         }
     }
     printf("\n");
}
#endif
```
[Back to Index](../../index.md)