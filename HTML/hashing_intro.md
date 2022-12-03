## Introduction to Hashing 

So far we have learned about BST and balanced BSTs as possible alternative data structures for dictionary operations. As
we know already insert, search and delete together constitute the dictionary operations. Balanced binary search trees 
only ensure worstcase time of O(log <i>n</i>) per operation. In application involving lage database table dictionary operations
are performed with high frequencies. Therefore, if an application requires a large set of dictionary operations 
then even O(log <i>n</i>) worstcase time per operation is unacceptable. We will need a data structure that would allow
us to perform the operations in O(1) time in average per operation for a given set operations. A simple yet powerful
way to store the elements in a tabular form and use index to the table to access and retrieve them when required. The
most clever part of the suggested scheme is computing the index for an element. Since the access has to be performed in O(1)
time, the index should be computable in O(1) time. But the question is: how do we actually compute index in O(1) time?
The answer is to define hash function. 

A hash function function is a mapping <i>h:x &#8594; i<i>, where <i>x</i> is element of the table and <i>i &#8712; {0, 1, 2 ... }</i>.
The toughest part of hashing is to design a the hash function which spreads the elements or symbols evenly among the 
available table slots. How does spreading evenly help? More precisely, if more than one symbols maps to the same index then 
attempt to retrieve one specific value may actually produce some random value that we are not interested. To make sense of
out of confusion involving collisions in storing symbols in hash table, we should know about types of hashing. 
  
There are two types of hashing:
 
- Hashing by chaining
- Hashing by open addressing
  
Hashing by chaining uses separate linked lists to store the elements that collide on same index value. All elements mapping
to same index are chained togther in linked list. The table index actully points to the first element of the list. To access a
desired element we have to traverse the linked list. The important aspect of this type of hashing is to ensure that only
O(1) items may collide with same hash value when hash function is applied. The picture of hashing by separate chaining
is given below.
 
 
