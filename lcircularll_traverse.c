#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct node *next;
};
void traverse(struct Node *head )
{
    struct Node *ptr=head;
   
    do
    {
    printf("element = %d \n",ptr->data);
    ptr= ptr->next;
    }
    while(ptr!=head);

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
third->next=head    ;

traverse (head);
return 0;
}