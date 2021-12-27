## Implementation of List in C
The first thing about implementation is to declare the memory requirement for the data structure. In the case of a list, we 
need at least two fields to define a node, namely, 

- ### Information content: to store an item of information in an element of the list.
- ### Successor element: to be able to fetch the successor from a given element of the list.  

A <b>struct</b> construct in C allows us to specify a user-defined record type as explained in the blog on Data Types and ADT. 

The function newNode() is not an object constructor like the one needed in C++ programming, but it is necessary to allocate 
storage.

```
NODE ∗ newNode () {
     NODE ∗p;
     p = (NODE ∗) malloc ( sizeof(NODE) );
     return p;
}
``` 
A new list is sometimes defined by a specially designated node called the header node. A header node usually is not used to 
store information, but its use simplifies the coding of other operations. It is possible to operate on a list without allocating 
a separate header node. However, an implementor has to be careful in isolating the case of applying list operation when the list 
is empty.
```
NODE ∗ newList() {
     NODE ∗p ;
     p = newNode() ;  // Creates the header node   
     if (p != NULL) {  
          p->info = −1; //  Indicates information is not useful
          p->next = NULL;
          return p ;
    } else // malloc encounters an error 
          printf("Error in memory allocation\n");
}
``` 
Operating with a long list may become simpler if we can identify the first and the  last node. The code for these two operations 
are simple and given below.
```
NODE * firstNode(NODE *list) {
     return (list->next); // Returns NULL if list is empty
}
```
Getting last node requires a helper function to find out if the list is empty.
```
int isEmpty(NODE *list) {
     return (list->next == NULL);
}

NODE * lastNode(NODE * list) {
    NODE * p = list; // Used for traversal of list
    if (isEmpty(list)) 
         return list;
    while (p->next != NULL) 
         p = p->next;
    return p; 
}
```
Let me end the blog by discussing two other list operations that will help in full implementation of list operations. The first 
one is insertBefore() and the second one is remove(). The function insertBefore() requires three arguments, namely,  list 
header,  the item before which insertion should be made, and item to be inserted. Removal requires two arguments, namely,  the 
list header and the item to be removed from the list. 
 
The attempt to access undefined pointers leads to core dumps. Therefore, it is always advisable to create an appropriate mental 
picture to ensure that code does not attempt to access undefined pointers, especially in C programming. Consider, for example, 
the case of inserting a new node into a given list before a particular node. The exact manipulation of the pointers is given in 
the diagram below.
<p align="center">
  <img width="260" height="150" src="https://github.com/rkgIITBh/Data-Structures.io/blob/gh-pages/images/listInsertBefore.jpg">
</p>
The existence of a dummy head node simplifies the modification of pointers when a new node is prepended to a list. Append to a 
list does not create any problem. The pseudo-code for insertion is given below. 
```
insertBefore(list, x, y) {
    pred = findPred(list, x);
    if (pred == NULL) {
         print "x does not exist, insert failed";
         return;
    }
    p = newNode(x); // Create new node for insertion
    if (p != NULL) {
        p->info = y;
        p->next = pred->next;
        pred->next = p;
    } else 
        print "Memory allocation error;
    return;
}
```
If the first node is known, than insertBefore() can also add a new node at the beginning. The use of a dummy head node again 
simplifies the code. It is possible to get the predecessor of any node in the list, including the first element. In the pseudo 
code, we have used a function called findPred() to get the predecessor of a given node.

The deletion of an element from the list is pretty simple. The manipulation of pointers for realizing deletion is shown in the 
figure below. Here again, the dummy head node simplifies the pointer updates to remove a node. We navigate the list until
hitting the predecessor of the node to be removed. The pointer adjustments for removal of a node requires fetching the 
predessor and setting its next to the successor of the node to be removed as depicted in the diagram below.
<p align="center">
  <img width="260" height="150" src="https://github.com/rkgIITBh/Data-Structures.io/blob/gh-pages/images/listRemoveNode.jpg">
</p>
The code snippet for removal of node is given below:
```
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
```
For the source code of the rest of the operations on list please follow this [link](../CODES/listHeader.md)
