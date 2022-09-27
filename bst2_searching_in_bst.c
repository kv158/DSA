#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node * search(struct node * root,int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root ->data == key)
    {
        return root;
    }
    else if (root ->data > key)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
    
}
// struct node * search(struct node * root,int key)
// {

// }



int main()
{
    // construct node
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);

    // linking node
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorder(p);
    printf("\n");
    struct node *n=search(p,4);

    if (n!=NULL)
    {
    printf("found %d",n->data);
    }
    else
    {
            printf("element not found");

    }
    
    

   
    

    return 0;
}