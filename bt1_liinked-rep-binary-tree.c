#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};



int main()
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data=2;
    p->left = NULL;
    p->right = NULL;

    struct node *p1 = (struct node *)malloc(sizeof(struct node));
    p1->data=3;
    p1->left = NULL;
    p1->right = NULL;

    struct node *p2 = (struct node *)malloc(sizeof(struct node));
    p2->data=4;
    p2->left = NULL;
    p2->right = NULL;

     p->left = p1;
    p->right = p2;



    return 0;
}