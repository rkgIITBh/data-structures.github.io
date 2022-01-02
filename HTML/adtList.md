---
## Abstract Data Types
---
The abstract concept of a list is just a sequence element. There are two types of lists: (i) order lists and (ii) unordered lists. An <i>ordered list</i> is an order 
sequence in which every element has a position. In other words, the elements of a list are arranged based on some inherent characteristic. For example, the roll list of 
students in class is arranged in 
ascending order or alphabetically. So, an element determines its position in the list. For example, if we have a list of ascending values: 98, 83, 75, 67, 51, 46, 34, 24, then the 
new element 92 can be placed only between 98 and 83.
<p align="center">
  <img width="360" height="100" src="https://rkgiitbh.github.io/data-structures.github.io/images/orderlist.jpg">
</p>
An unordered list is just a collection of elements. The position of a component is not fixed, unlike that in an ordered list. 
<p align="center">
  <img width="360" height="100" src="https://rkgiitbh.github.io/data-structures.github.io/images/unorderedlist.jpg?">
</p>
The organization of elements in an unordered list is determined by its user. The user may place a new element anywhere in the 
list, front, rear, or somewhere in the middle. A do-it-list, a check-list or a shopping list can be organized in an unordered 
fashion as no inherent element characteristic determines its position.

However, unlike an array, it does not allow random access. Only the first element is accessible. 

An element of a list represents a composite item consisting of an information part and a subsequent part. An element of a list is most 
commonly referred to as a node. In terms of C each node of a list is a record that may store one or more values and the next
field. For implementation, we use struct construct. However, it is crucial to understand the list as an ADT.

Every item except the last has a next or a successor item. Similarly, every item except the first one has a predecessor. The 
a possible set of  operations on the list are as follows:

- newNODE(): Allocates memory and creates a new node
- isEmpty(L): Finds if L is empty.
- find(L, x): Given L and an element x returns ptr to node
- containing x if it exists.
- findNext(L, x): Returns a ptr to node after node having x, if
  it exists.
- findPrevious(L, x): Returns a ptr to node before the node
  having x if it exists.
- prepend(L, x): Inserts x at the beginning of L.
- append(L, x): Inserts x at the beginning of L.
- insert(L, x, y): Inserts y after x in L.
- remove(L, x): Returns a ptr to L after deleting x if it exist.
- last(L): Returns a ptr to the last element in L.

In the next blog, we will discuss the implementation aspects of the list operations in some detail and provide a link to the 
source code in C. 

[Back to Index](https://rkgiitbh.github.io/data-structures.github.io/)
