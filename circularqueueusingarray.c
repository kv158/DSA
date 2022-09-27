#include <stdio.h>
#include <stdlib.h> 
struct cqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct cqueue *q)
{
    if((q->r+1)%q->size==q->f)    //change for cqueue
    {
        return 1;
    }
    return 0;
}

int isempty(struct cqueue *q)
{
    if(q->r==q->f)  
    {
        return 1;
    }
    return 0;
}
void enqueue(struct cqueue *q,int val)
{
        if(isfull(q))
        {
            printf("queue is full \n");
        }
    else
    {
        q->r=(q->r+1)%q->size;  //change for cqueue
        q->arr[q->r]=val;
        printf("enqueued element is %d \n",val);

    }
}

int dequeue(struct cqueue *q)
{
    int a=-1; 
        if(isempty(q))
        {
            printf("queue is empty \n");
        }
    else
    {
        // q->f++;
         q->f=(q->f+1)%q->size; //change for cqueue
        return q->arr[q->f];
    }
}

int main()
{
    struct cqueue q;

    q.size=5;
    q.f=0;
    q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));

     if(isempty(&q))
    {
        printf("queue is empty \n");
    }
    
    enqueue(&q,65);
    enqueue(&q,87);
    enqueue(&q,32);
    enqueue(&q,24);

        printf("dequing element %d \n",dequeue(&q));
        printf("dequing element %d \n",dequeue(&q));
        printf("dequing element %d \n",dequeue(&q));
        printf("dequing element %d \n",dequeue(&q));

    enqueue(&q,65);
    enqueue(&q,45);
    enqueue(&q,75);

        printf("dequing element %d \n",dequeue(&q));
        printf("dequing element %d \n",dequeue(&q));
        printf("dequing element %d \n",dequeue(&q));




    if(isempty(&q))
    {
        printf("queue is empty \n");
    }

    if(isfull(&q))
    {
        printf("queue is full  \n");
    }

return 0;
}