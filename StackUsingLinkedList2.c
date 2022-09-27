#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};
//  global variable
    struct Node* top=NULL; 


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

int pop (struct Node * tp)
{
    if(isempty(tp))
    {
        printf("stack is empty\n");
    }
    else
    {
         struct Node * n= top;
         top=(tp)->next;
        int x =n->data;
        free(n);
        return x;
    }
    

}

int peek(int pos)
{
    struct Node* ptr=top; 
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
    {
       ptr = ptr->next;
    //    printf("%d");
    }

    if (ptr!=NULL)
    {
        return ptr->data;
    }

    else
    {
        return -1;
    }
    
}

int stacktop()
{
    return top->data;
}

int stackbottom()
{
    return;
}
int main()
{
    // struct Node* top=NULL; make global variable for easy pop operatio
    top=push(top,25);
    top=push(top,6);
    top=push(top,9);
    top=push(top,5);
    top=push(top,3);    
traverse(top);

    int element=pop(top);  
    printf("poped ellement is %d\n",element);

traverse(top);

// printf("value at posistion 1 is %d",peek(1));

for (int i = 1; i <= 4; i++)
{
   printf("value at posistion %d is %d\n",i,peek(i));

}


return 0;
}