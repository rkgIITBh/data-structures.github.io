## Queues 

Queues are familiar to everyone. Almost daily, we join one or more queues to seek some service. The service may be entry to an 
airport, boarding a bus or train, teller counter of a bank or event a milk booth. A queue is formed to ensure that the service 
seekers get their service in the time order of their joining of the queue. So, a queue is a linear list that allows insertion at 
one end and deletion from the other end. We will call the joining end as rear and from which people leave as the front. The 
person at the front must have joined the queue before all others in the queue. Therefore, a queue is also known as the first-in, 
first-out (FIFO) list. The following two questions may come almost immediately to anyone viewing this blog
 
- ### How do we view the queue as an ADT? 
- ### Where do we use a queue in programming? 
- ### How do we implement a queue?

Let me begin by answering the easiest of the three questions. In programming, a queue is used in many places where we need to 
process items sequentially in their arrival order. For example, a server queue is maintained to service the client requests strictly in arrival order. However, there may be minor variations such as priorities. For instance, in a job, scheduling priorities may be necessary. Unix uses multilevel queues for process scheduling. Processes move from one queue to another to ensure that processing priorities are honored, and there is no starving. The most important use of a queue is to hold or temporarily store items for processing according to arrival time. Mails are stored in a queue at mail servers; message queues hold messages until they can be delivered for processing. Having dealt with the use of queues in programming, let us view queues as an ADT. The operations are specified as follows:
```
// Operations on the universe of all queues of element type

new<element type> : -> queue<element type> // Creating an empty queue
empty<element type> : queue<element type> -> Boolean
full<element type>: queue<element type>  -> Boolean
remove<element type> : queue<element type> -> <element type> X queue<element type> // Modifier
insert<element type> : queue<element type> X <element type> -> queue<element type> // Modifier
```
Implementation of a queue is slightly more involved than a stack as we need to keep track of two different ends of the list. All 
insertions are at one end called rear, and all removals are from the other end called the front. We can implement a queue either 
using a linked list or an array.
 
Flat array implementation requires the left queue to make room for adding elements at the rear. Otherwise, it will not be 
possible to reclaim vacant slots of the removed elements. The situation is illustrated by the figure below.
 
![Flat Array](../images/queuePic1.jpg?raw=true "flat array")

It shows that the queue elements occupy array slots from index = 4 to r. Even if there are four vacant slots, no insertion is 
possible because insertion should occur at the rear. Shifting elements often lead to inefficient implementation. Shifting takes 
O(n) time if there are O(n) elements in the queue. A better implementation is to consider a circular array. It is easy to 
visualize circular array implementation as a fusion of two ends of a flat array as shown in the above figure. Logically, it 
will look like this:  

  ![Circular Array](../images/circularArray.jpg?raw=true "circular array")

After each insertion, the front advances circularly, and after every deletion, the rear advances circularly. The circular 
advance is equivalent to plus 1 mod n. Therefore, it is an implementation where the head of the queue appears to chase its 
tail. The difficulty is to distinguish between the empty and the full queue. Leaving an unused empty slot in the array makes 
the implementation faster and easier. 

Initially an empty queue is defined by Q.front=0, Q.rear=n-1. The queue empty condition will occur when 

(Q.rear+1) mod n == Q.front 

Since a full queue can have only n-1 elements, the full queue condition can be determined by 

Q.front = ((Q.rear+1) mod n+1) mod n == Q.front. 

For example, assume n=15, consider the following situations:
```
  Q.front =12, and Q.rear = 14, it means positions 12, 13, 14 are occupied. 
  A new insertion will be in position 0, because (14+1) mod 15 = 1. 
  All positions from 0 to 10 can be occupied leaving slot 11 free. 
  Q.front = 14, and Q.rear = 9, it means slots 14 and slots 0-9 are occupied. Insertions can be done in slots 10-12.  
  Q.rear=10, and Q.front=12, then ((10+1) mod 15) + 1) mod 15 = 12 = Q.front, which indicates queue full condition. So, no 
  further insertions will be allowed. 
```

Watch out for the next blog for C implementation of a circular array-based queue.  
