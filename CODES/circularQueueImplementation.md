```
#ifndef QUEUE_H
#define QUEUE_H
typedef struct Q {
    int * info;
    int size;
    int rear;
    int front;
} QUEUE;

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

int addOne (int i) {
    return (i+1) % MAXSIZE;
}

int isEmpty(QUEUE * q) {
    if (addOne(q->rear) == q->front) 
        return 1;
    else
        return 0;
}

int isFull(QUEUE * q) {
    if (addOne(addOne(q->rear)) == q->front)
        return 1;
    else
        return 0;
}

int getFront(QUEUE * q) {
    if (isEmpty(q)) { 
        printf("Error: queue empty\n");
        return -999;
    } else 
        return q->info[q->front];
}
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

void printQueue(QUEUE *q) {
    int i = q->front;
    while (i != q->rear) { 
        printf("%d\t", q->info[i]);
        i = (i+1) % MAXSIZE;
    }
    printf("%d\n",q->info[i]);
}
#endif
```
