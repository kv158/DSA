#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isempty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isfull(q))
    {
        printf("queue is full \n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        printf("enqueued element is %d \n", val);
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isempty(q))
    {
        printf("queue is empty \n");
    }
    else
    {
        q->f++;
        return q->arr[q->f];
    }
}

int main()
{
    struct queue q;

    q.size = 4;
    q.f = -1;
    q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    if (isempty(&q))
    {
        printf("queue is empty \n");
    }

    enqueue(&q, 65);
    enqueue(&q, 87);
    enqueue(&q, 32);
    enqueue(&q, 24);

    printf("dequing element %d \n", dequeue(&q));
    printf("dequing element %d \n", dequeue(&q));
    printf("dequing element %d \n", dequeue(&q));
    printf("dequing element %d \n", dequeue(&q));

    enqueue(&q, 65);
    enqueue(&q, 45);
    enqueue(&q, 75);

    printf("dequing element %d \n", dequeue(&q));
    printf("dequing element %d \n", dequeue(&q));
    printf("dequing element %d \n", dequeue(&q));

    if (isempty(&q))
    {
        printf("queue is empty \n");
    }

    if (isfull(&q))
    {
        printf("queue is full  \n");
    }

    return 0;
}