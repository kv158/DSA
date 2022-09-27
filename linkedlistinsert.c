#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct node *next;
};
void traverse(struct Node *ptr)
{
    while(ptr!=NULL)
    {
    printf("element = %d \n",ptr->data);
    ptr= ptr->next;
    }
}

struct Node * insfirst(struct Node*head ,int data)
{
     struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
     ptr-> next =head; 
     ptr-> data =data;
     return ptr; 
}

struct Node * insatindex(struct Node*head ,int data,int index)
{
     struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
     struct Node * p=head;
     int i=0;

     while(i!=index-1)
    {
        p=p->next;
        i++;
    }
     ptr-> data =data;
     ptr-> next =p->next;
     p->next=ptr;  
     return head; 
}

struct Node * inslast(struct Node*head ,int data)
{
     struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
     ptr-> data =data; 
     struct Node * p=head;

     while(p->next!=NULL )
    {
        p=p->next;
    }
     p->next=ptr;  
     ptr-> next =NULL;
     return head; 
}

struct Node * insafter  (struct Node*head,struct Node*prevnode ,int data)
{
     struct Node * ptr=(struct Node*)malloc(sizeof(struct Node));
     ptr-> data =data; 

     ptr->next=prevnode->next;
    prevnode->next=ptr;
     
     return head; 
}
int main()
{

struct Node*head;
struct Node*second;
struct Node*third;

head=(struct Node*)malloc(sizeof(struct Node));
second=(struct Node*)malloc(sizeof(struct Node));
third=(struct Node*)malloc(sizeof(struct Node));

head->data=5;
head->next=second;

second->data=4;
second->next=third;

third->data=35;
third->next=NULL;

traverse (head);


// head=insfirst(head,55);
// traverse (head);

insatindex(head,6,2);
// traverse (head);

inslast(head,12);
// traverse (head);

head=insafter(head,second,85);
traverse (head);

return 0;
}