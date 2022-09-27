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


struct node *inorderpredesessor(struct node *root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;
}

struct node *delete (struct node *root, int key)
{
    struct node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (key < root->data)
    {
        root->left=delete (root->left, key);
    }
    else if (key > root->data)
    {
     root->right= delete (root->right, key); 
    }
    else
    {
        ipre = inorderpredesessor(root);
        root->data = ipre->data;
         root->left= delete (root->left, ipre->data);
    }
    return root;
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

    // struct node *p = createnode(delete(p,3));
    delete(p,4);
    

    inorder(p);
    printf("\n");


    return 0;
}