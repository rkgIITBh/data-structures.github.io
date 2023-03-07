# Circular Queue Description


A queue is linear list where new elements are added to one end and the elements in queue are removed from the other end for 
    processing. The first end is called rear and the other is known as front. In the array implementation when 
    the elements are removed from the <samp>q.front</samp>, the positions to the beginning of the array are left vacant. So, the vacant 
    positions in the array before <samp>q._front</samp> cannot be used and we quickly run into the problem of inserting new elements.

However, if we utilize the vacated positions then it is possible to insert new elements as long as all positions are not filled. It
    can be done as follows. We shift the existing elements between <samp>q._front</samp> to <samp>q._rear</samp> to the beginning
    of the array as indicated in the figure below.
    
<p style="text-align:center">
<img src="{{url_for('static', filename='circularQNew.png')}}", width="350", height=210" />
</p>

The shifting operation should be carried out each time <samp>q._rear</samp> points the last position. This is expensive. A simpler way to 
consider the segment of occupied positions of the array as an arc in circle. It allows us to keep adding to positions after <samp>q._rear</samp> as 
long as vacant positions are available with the tail of the queue chasing the head. 

Therefore, the array implementation treats a queue logically as a 
    circular python array. To keep the tail distinct from the head, one 
    array position is left vacant when queue is full. It means we can
    fill all but one position of the array. We need to the access the 
    vacant positions of the array by filling again from the beginning. 

Insertion operation is known as enqueue. Enqueing is performed 
    at the <samp>q._rear</samp> by incrementint it. Since the array is
    treated as circular, we use modulo addition <samp>MAXSIZE</samp>. 
    Deletion operation is known as dequeue. Dequeue is performed by
    decrementing <samp>q._front</samp>. A dequeue operation shifts the
    head of the queue by one postion. So <samp>q._front</samp> is 
    decremented by modulo addition <samp>MAXSIZE</samp>.

Our implementation of Python App for queue operations is divided into four parts:</p>
    <ul>
        <li>Queue operations</li>
        <li>App routes</li>
        <li>Templates</li>
        <li>Styles</li>
    </ul>

The functions for implementing the queue operations in Python are defined in Python class. It has four fields: 
<samp>q._front</samp>, <samp>q._rear</samp>, <samp>q._size</samp>, and <samp>q._data</samp>. The last field store the actual data, and
is an array. 

An empty queue is defined by testing if the result of increment of <samp>q._rear</samp> modul0 <samp>MAXSIZE</samp> equates it to 
to <samp>q._front</samp>. So, the initially, we define:

```
    q._front = 0
    q._rear = MAXSIZE - 1
```

Since, Python array index starts with 0, when increment of <samp>q._rear</samp> is computed it becomes equal to <samp>q._front</samp>.
We define a field <samp>q._size</samp> for capacity of the queue. Therefore, the <samp>__init__()</samp> is as follows:

```
    def __init__(self):
        self._front = 0 # for empty queue.
        self._size = MAXSIZE - 1 # capacity of queue
        self._rear = self._size # initial value 
        self._data = [None] * QueueArray.SIZE  # data in an array of MAXSIZE
```

The helper helper function <samp>addOne()</samp> that perform 
    addition 1 modulo <samp>MAXSIZE</samp> should be globally available 
    to all methods of the <samp>Queue</samp> class. Its definition appears
    below. We use a fixed array size for the circular array 
    implementation. For keeping it simple, we did not consider resizing
    array to accommodate more data. However, by modifying 
    <samp>MAXSIZE</samp>, we can redfine a bigger or smaller array.

```
    def addOne(i):
        return (i + 1) % MAXSIZE # returns add 1 modulo MAXSIZE
```

The first four functions are simple as described below
<ul> 
         <li><samp>Makenull()</samp>: shrinks the queue and returns an empty queue.</li>
         <li><samp>isEmpty()</samp>: returns True if the queue is empty.</li>
         <li><samp>isFull()</samp>: returns True if the queue is full.</li>
         <li><samp>__len__()</samp>: returns length of the current queue.</li>
</ul>
                                                                                                                                                                 
```
    def makenull(self):
        self._front = 0
        self._size = MAXSIZE - 1 
        self._rear = self._size 
        self._data = [None] * QueueArray.SIZE 

    def __len__(self):
        if self.isEmpty():
            return 0
        if self._rear > self._front:
            return (self._rear - self._front) + 1 
        return MAXSIZE + (self._rear - self._front) + 1

    def isEmpty(self):
        if addOne(self._rear) == self._front:
            return 1
        return 0

    def isFull(self):
        if self._front == addOne(addOne(self._rear)):
            return 1
        return 0
 ```
The next two functions are non-mutating in nature. They access the queue ends and return the values. The first one returns 
<samp>q._front</samp> if the queue is not empty. Similarly, the second one returns <samp>queue._rear</samp> if queue is not iempty.
In both cases it return None if the queue is empty. 
                                                                                       
``` 
    def getFront(self):
        if (self.isEmpty()):
            print('Queue is empty') 
            return None
        return self._data[self._front] 

    def getRear(self):
        if (self.isEmpty()):
            print('Queue is empty') 
            return None 
        return self._data[self._rear] 
```

Insertion operation on a queue is called enqueue and deletion operation is known as dequeue. Enqueuing requires two parameters: a pointer to a queue 
and the item to be inserted. It inserts the input item at the rear end of a queue and should insert only if the queue is not full. Dequeuing 
returns the element at the front of a non-empty queue and requires just a pointer to a queue. The code snippets for the two functions appear below.
```
    def enqueue(self, ele):
        if self.isFull():
            print("Queue is full: " +str(ele)+ " not inserted") 
            return
        self._rear = addOne(self._rear)
        self._data[self._rear] = ele
        

    def dequeue(self):
        if self.isEmpty():
            print("Queue is empty, deletion not possible")
            return -999 

        x = self._data[self._front] 
        self._front = addOne(self._front)
        return x

```
Python Flask app expects each parameter to be provided in the form of a string. Therefore, we need to convert the collection elements in
a queue in the form of a string. This requirement will become clear when discuss Flask app for queue operations. We format the queue string by
indicating its front and the rear part. Each element from <samp>q._front</samp> to <samp>q._rear</samp> are accessed one at time
and placed in the string.
                                                         
```
    def to_list(self):
        if self.isEmpty():
            return "front-> <-rear"
        
        indx = self._front
        prnt = "front-> "+ str(self._data[indx])
        while indx != self._rear: 
            indx = addOne(indx)
            prnt += " "+str(self._data[indx])
        prnt += " <-rear"
        return prnt
```


[Click here](../CODES/queue_class.html) for the complete source code.



