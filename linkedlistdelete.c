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

struct Node* delfirst(struct Node * head){
    struct node* ptr=head;
    head=head->next;
    free(ptr);
    return head;

}

struct Node* delatindex(struct Node * head,int index)
{
    struct Node *p=head;
    struct Node *q=head->next;
    for (int i = 0; i < index-1; i++)
    {
       
         p = p ->next; 
         q = q ->next; 
    }
    
    p->next=q->next;
    free(q);
    return head;

}

struct Node* delatlast(struct Node * head)
{
    struct Node *p=head;
    struct Node *q=head->next;
while(q->next!=NULL)    {
       
         p = p ->next; 
         q = q ->next; 
    }
    
    p->next=NULL;
    free(q);
    return head;

}

struct Node* delatkey(struct Node * head,int key)
{
    struct Node *p=head;
    struct Node *q=head->next;
while(q->data!=key && q->next!=NULL)    {
       
         p = p ->next; 
         q = q ->next; 
    }

    if(q->data==key){
    p->next=q->next;
    free(q);

    }
    
    return head;

}

int main(){

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

// head=delfirst(head);
// traverse (head);

// head=delatindex(head,1);
// traverse (head);

// head=delatlast(head);
// traverse (head);

head=delatkey(head,4);
traverse (head);

return 0;
}