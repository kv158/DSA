#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * push(struct Node *top,int data)
{
    if(isfull(top))
    {
        printf("stack is full\n");
    }
    else
    {
        struct Node * n=(struct Node *)malloc(sizeof(struct Node));
        n->data=data;
        n->next=top;
        top=n;
        return top;

    }
}

void traverse(struct Node *ptr)
{
    while(ptr!=NULL)
    {
    printf("element = %d \n",ptr->data);
    ptr= ptr->next;
    }
}


int isempty(struct Node *top)
{
        if (top==NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
}

int isfull(struct Node *top)
{
    struct Node* q=(struct Node *)malloc(sizeof(struct Node));

    if(q==NULL)
    {
        return 1; 
    }
     else
        {
            return 0;
        }
}

int pop (struct Node ** top)
{
    if(isempty(*top))
    {
        printf("stack is empty\n");
    }
    else
    {
         struct Node * n= *top;
        *top=(*top)->next;
        int x =n->data;
        free(n);
        return x;
    }
    

}
int main()
{
    struct Node* top=NULL;
    top=push(top,25);
    top=push(top,6);
    top=push(top,9);
    top=push(top,3);
traverse(top);

    int element=pop(&top);  
    printf("poped ellement is %d\n",element);

traverse(top);

return 0;
}