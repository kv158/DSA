#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int hight;
};

struct node *createnode(int key)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->hight = 1;
    return n;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int gethight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->hight;
}
int max(int x, int y)
{
    return x > y ? x : y;
}

int getbalancefactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return gethight(n->left) - gethight(n->right);
}

// for a tree
//       y                                 x
//      / \      right  rotation-->       / \
//     x   t3    <--left  rotation      t1   y
//    / \                                   / \
//  t1   t2                                t2  t3

struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->hight = max(gethight(y->right), gethight(y->left)) + 1;
    x->hight = max(gethight(x->right), gethight(x->left)) + 1;
    return x;
}

struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    y->hight = max(gethight(y->right), gethight(y->left)) + 1;
    x->hight = max(gethight(x->right), gethight(x->left)) + 1;
    return y;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return createnode(key);
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    node->hight = 1 + max(gethight(node->left), gethight(node->right));
    int bf = getbalancefactor(node);

    // left left case
    if (bf > 1 && key < node->left->key)
    {
        return rightrotate(node);
    }
    // right right case
    if (bf < -1 && key > node->right->key)
    {
        return leftrotate(node);
    }
    // left right case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    // right left case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }

    return node;
}

int main()
{
    // construct node
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 56);
    root = insert(root, 55);

    inorder(root);
    printf("\n");

    return 0;
}