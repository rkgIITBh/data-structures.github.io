## Stacks as ADT

Stack allows insertions and deletions in one end. So, following a sequence of insertions, deletions produce the elements in 
reverse order. Due to reverse sequencing of the elements on deletion, a stack is also known as last in the first out list 
(LIFO). Considering a stack as an ADT, the following operations are important:

- ### Create an empty stack that will store elements of a given type.
- ### Insert a new element into an existing stack with the same element type. It may lead to overflow if the stack is already full.
- ### Remove the top element from an existing stack. It may lead to underflow if the stack is empty.

```
// Operations on the universe of all queues of element type

new<element type> : → stack<element type> // Creating a stack
empty<element type> : stack<element type> → Boolean
full<element type>: stack<element type> → Boolean
pop<element type> : stack<element type> → <element type> × stack<element type> // Modifier
push<element type> : stack<element type> × <element type> → stack<element type> // Modifier

// Exception

overflow -> full stack // Occurs on attempt to insert into full stack
underflow -> empty stack // Occurs on attempt to remove from empty stack
```
After formulating ADT, the programmatic implementation of the stack becomes extremely simple. Apart from creating a space for 
storing elements, we need to keep track of the top. The storage may be created using an array or a linked list. The top is just 
the index of the last element if the stack elements are held in an array. If stack storage is a linked list, the top should be a 
pointer to the last incoming element. 

We end this blog with a C-structure of a stack using an array.  
```  
typedef struct stack {
      int *info;
      int limit; // Capacity of stack
      int top; // Index of the last incoming element
} STACK;
```
Now STACK can be used as a type for implementing stack operations. 

The next blog will deal with stack operations.

[Back to Index](https://rkgIITBh.github.io/data-structures.github.io/)
  
