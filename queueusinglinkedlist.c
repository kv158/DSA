#include <stdio.h>
#include <stdlib.h>

struct node *f = NULL;
struct node *r = NULL;

struct node
{
    int data;
    struct node *next;
};

void display(struct node *ptr)
{
    printf("display element\n");

    while (ptr != NULL)

    {
        printf("element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    printf("insert sucsess\n");
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("queue is full \n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    // printf("insert sucsess\n");
    struct node *ptr = f;
    if (f == NULL)
    {
        printf("queue is empty \n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    // struct node *f = NULL;
    // struct node *r = NULL;

    display(f);

    printf("dequing element %d \n", dequeue());
   
    enqueue(54);
    enqueue(23);
    enqueue(8);

    printf("decuing element %d \n", dequeue());
    printf("decuing element %d \n", dequeue());

    display(f);

    return 0;
}