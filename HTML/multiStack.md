## Stack for Storing Multiple Item Types

So far, we worked with programs for handling a collection of homogeneous item types.  Sometimes we may want to create data structure for handling different 
types of items. For example, the collection of items may consists of:
<ul>
<li>a few items of <b>int</b> type</li>
<li>some items of <b>float</b> or </li>
<li>some items of <b>char</b>. </li>  
</ul>
C++ provides template. It is possible to pass data type to an object using the template. Therefore, we need not write different codes for different data types. 
However, only a particular type must be passed as a parameter to the template. To create a data structure of mixed types, we need to use a construct called
<b>union</b>. It works like a structure type in C. Using a  <b>union</b>, we define all data types of the collection we may want to represent as follows:
```
union collection {
    int a;
    char b;
    float c
    char *d;
};
```
It can represent any of the mentioned type in <b>union</b> declaration. The size of the storage is equal to the maximum size of the elements stored in 
the structure. 

In this blog, we confine ourselves to a stack that may possibly represent any of the types <b>int</b>, <b>float</b>, or <b>char</b>. We have already 
discussed stack operation in the previous blog. Therefore, we focus on the programming aspects, which require a bit of explanation. How do we know that
an element of the stack is of a specific type? Essentially, a logical tag must be associated with the data as we execute the stack operations. 
The problem occurs, especially when the stack contents are printed. We should use the correct formatting string to print the item type being poped or 
displayed. 

We create an enumerated type for all possible type of items that can ever be stored in the stack.  
```
enum {
    INT, CHAR, FLOAT 
};
```
A stack declaration uses a C-struct containing item type and <b>union</b> for
the storage of item types. 
```
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
```
The size of the above stack type element would be equal to the size of <b>struct</b> type ITEMS. We have already seen in the case of a stack of a single type, except for the <i>createStack()</i> function.
The function <i>createStack</i> should allocate
storage for STACK and also for ITEMS. However, the function should be easy to understand.
```
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
```
The first <i>malloc</i> allocate storage for STACK type, but does not allocate storage for elements. Therefore, we need another <i>malloc</i> inside
to explicitly allocate a fixed capacity storage for the elements. If any of the <i>malloc</i> fails then it returns NULL.

The only other function that may of interest is to examine how the <b>enum</b> type serves as a logical tag. The function <i>printStack</i> consists of a 
<b>switch case</b> statement for handling the tags and printing the data using correct formatting string. 
```
void printStack(STACK *s) {
     printf("The Stack items are:\n");
     for(int i = 0; i <= s->top; i++) {
         printf("The index %d has type = ", i);
         switch(s->element[i].itemtype) {
             case INT : printf("INT and value = %d\n", s->element[i].itemval.ival); // Tag INT: print int formatting string
                        break;
             case FLOAT: printf("FLOAT and value = %f\n", s->element[i].itemval.fval); // Tag FLOAT: print float formatting string
                        break;
             case CHAR: printf("CHAR and value = %c\n", s->element[i].itemval.cval); // Tag CHAR: print char formatting string
                        break;
             default : printf("Invalid data type\n");
         }
     }
     printf("\n");
}
```
Since <i>itemtype</i> is associated with each item, <i>printStack</i> examines the type and uses the correct formatting string for displaying the item. Please
using the [link here](../CODES/multiStack/index.md) for the full source code.

[Back to Index](../index.md)