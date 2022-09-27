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

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;

        if (root->data == key)
        {
            printf("%d is already in bst", key);
            return;
        }

        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = createnode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

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

    // tree

    //              5
    //             / \ 
    //            3   6
    //           / \ 
    //          1   4

    inorder(p);
    printf("\n");

    insert(p, 7);
    insert(p, 2);
    printf("\n");

    inorder(p);
    printf("\n");

    printf("%d \n", p->right->right->data);
    printf("%d", p->left->left->right->data);

    return 0;
}