## CircularArray Implementation of Queues

In the last blog, we discussed operations on queues and circular array implementation of a queue. In this blog, we look at the 
functions for implementing the queue operations in C. Let us begin with the definition of a queue for storing elements using a 
C-struct. 
```
typedef struct queue{
   int * info; // Storage for queue elements
   int size; // Capacity of the queue
   int front; // End for deletion
   int rear; // End for insertion
} QUEUE;
```
The advantage of using C lies in the dynamic allocation of space to store the items in a queue. We declared the storage as a 
pointer to the memory space where elements will be stored. It is possible to allocate space for a circular array depending on 
requirements. We need three other fields for identifying the two ends of the queue and the size of the queue, respectively.  


Before the beginning, function newQueue() must be invoked to instantiate a queue. The function requires the queue's capacity, and it returns a pointer to an empty queue with the given capacity. The function appears below:

```
QUEUE * newQueue() {
   QUEUE * q;
   q = (QUEUE *) malloc(sizeof(QUEUE));
   if (q ==NULL) {
       printf("Error: malloc failed\n");
       return NULL;
   }
   q->info = (int *) malloc(MAXSIZE*sizeof(int));
   if (q->info == NULL) {
       printf("Error: malloc failed\n");
       return NULL;
   }
   q->size = MAXSIZE-1;
   q->rear = q->size;
   q->front = 0;

   return q;
}
```
The capacity MAXSIZE is a global constant defined using C-preprocessor directive #define.  

After an instance of a queue has been created, we can create helper functions that will be required for insertion and deletion 
operations. Three helper functions are:

``` 
    addOne(int)
    isEmpty(QUEUE*)
    isFull(QUEUE*) 
```
 
As explained already, front and rear are indices of the array that are used to implement the storage area as a circular array. 
So, for incrementing front and rear, we need a function addOne that implements plus 1 mod n. The two other helper functions are for detecting queue empty and queue full conditions.


Insertion operation on a queue is called enqueue and deletion operation is known as dequeue. Enqueuing requires two parameters: a pointer to a queue and the item to be inserted. It inserts the input item at the rear end of a queue and should insert only if the queue is not full. Dequeuing returns the element at the front of a non-empty queue and requires just a pointer to a queue. The code snippets for the two functions appear below.

``` 
void enQueue(QUEUE * q, int x) {
      if (isFull(q)) { 
          printf("Error: queue full\n");
          printf("%d cannot be enqueued\n",x);
          return;
      }
      q->rear = addOne(q->rear);
      q->info[q->rear] = x;
      return;
}

int deQueue(QUEUE * q) {
     int x;
     if (isEmpty(q)) {
          printf("Error: queue is empty\n");
          return -999;
      }

      x = q->info[q->front];
      q->front = addOne(q->front);
      return x; 
}
```
 
Sometimes an operation called getFront() returns the elements at the front of a queue. It is given below. 

```
int getFront(QUEUE * q) {
     if  (isEmpty(q)) { 
         printf("Error: queue empty\n");
         return -999;
     } else 
         return q->info[q->front];
}
```
Click [here](https://rkgiitbh.github.io/data-structures.io/CODES/circularQueue/) for the complete source code.

[Back to Index](https://rkgiitbh.github.io/data-structures.github.io/)
