---
## Abstract Data Types
---
The abstract concept of a list is just a sequence element. There are two types of list: (i) order lists and (ii) unordered 
lists. An ordered list an order sequence in which every element has a position. In other words, the elements of a list are 
arranged based on some inherent characteristic. For example, roll list of students in class is arranged in ascending order or 
alphabetically. So, an element determines its position in the list. For example, if we have a list of ascending values: 98, 83, 
75, 67, 51, 46, 34, 24, then the new element 92 can be placed only between 98 and 83.

![Ordered List](https://github.com/rkgIITBh/Data-Structures.io/blob/gh-pages/images/orderlist.jpg?raw=true "ordered list")

An unordered list is just a collection of elements. The position of a component is not fixed, unlike that in an ordered list. 

![Unordered List](https://github.com/rkgIITBh/Data-Structures.io/blob/gh-pages/images/unorderedlist.jpg?raw=true "ordered list")

The organization of elements in an unordered list is determined by its user. The user may place a new element anywhere in the 
list, front, rear, or somewhere in the middle. A do-it-list, a check-list or a shopping list can be organized in an unordered 
fashion as no inherent element characteristic determines its position.

However, unlike an array, it does not allow random access. Only, the first element is accessible. 

An element of a list represents a composite item consisting of an information part and a next part. An element of a list is most 
commonly referred to as a node. In terms of C each node of a list is a record that may store one or more values and the next
field. For implementation, we use struct construct. However, it is important to understand the list as an ADT.

Every item except the last has a next or a successor item. Similarly, every item except the first one has a predecessor. The 
possible set of  operations on list are as follows:

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

In the next blog I will discuss the implementation aspects of the list operations in some details and provide a link to the 
source code in C. 

![Back to Index](../index.md)
