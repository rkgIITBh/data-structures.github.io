## Stack Implementation

The creation of a stack is simple. It requires allocating heap memory for storing stack elements, and two extra scalar 
variables. One for keeping track of the number of elements in the stack works as a cursor to the last item—the other for keeping 
track of the stack capacity. The function createStack appears below.
``` 
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
```

Once a stack has been created, we need functions that operate as per the specification stated in the previous blog. Two simple 
functions for checking the emptiness and fullness of the stack appear below. These functions are pretty straightforward. The 
first one checks if the top is set to -1 or not—the second check top against the capacity of the stack.
```
int isEmpty(STACK *s) {
     return s->top == -1;
}

int isEmpty(STACK *s) {
     return s->top == s->limit ;
}

int top(STACK *s) {
     if (isEmpty(s)) {
         printf("Error: empty stack\n");
         return -1;
     } else 
         return s->info[s->top]; 
}
```
Push function adds/inserts new elements into a stack. Pop., on the other hand, deletes an element from the stack. But the push 
function will work provided the stack is not full. Similarly, pop will work provided the stack is not empty. However, before 
applying the push or pop, we should check overflow and underflow conditions.   
```
void push(STACK *s, int element) {
    if(isFull(s)) {
        printf("Error: stack full\n") ;
        return;
    }
    s->info[++s->top] = element ; // pointer to end of list
    return;
}

int pop(STACK * s) {
    if (isEmpty(s)) {
         printf("Error: stack empty\n");
         return -999; // Indicates no element;
    } else
         return s->info[s->top--];
}
```
The last function is just to print the content of the stack.  
```
void printStack(STACK *s) {
    int i;
    if(isEmpty(s)) {
        printf("Stack is empty\n");
        return ;
    }

    i = -1;
    while (i < s->top)
        printf ("%d\t", s->info[++i]); // print elements
    printf("\n");
    
    return;
}
```
To get the full source code ![click here](../CODES/stackInC.md)

[Back to Index](https://rkgIITBh.github.io/data-structures.github.io)
