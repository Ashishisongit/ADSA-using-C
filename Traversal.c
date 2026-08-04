

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int root;
    struct node *left;
    struct node *right;
};


struct node *insert(struct node *root, int val);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
void clear(struct node *root);


struct node *insert(struct node *root, int val)
{
    if (root == NULL)
    {
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));

        temp->root = val;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }

    if (val > root->root)
    {
        root->right = insert(root->right, val);
    }
    else
    {
        root->left = insert(root->left, val);
    }

    return root;
}


void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->root);
    inorder(root->right);
}


void preorder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->root);
    preorder(root->left);
    preorder(root->right);
}


void postorder(struct node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->root);
}


void clear(struct node *root)
{
    if (root == NULL)
        return;

    clear(root->left);
    clear(root->right);
    free(root);
}


int main()
{
    struct node *root = NULL;
    int n, val, i;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter the value of node %d: ", i);
        scanf("%d", &val);

        root = insert(root, val);
    }

    printf("\nInorder Traversal:\n");
    inorder(root);

    printf("\nPreorder Traversal:\n");
    preorder(root);

    printf("\nPostorder Traversal:\n");
    postorder(root);

    clear(root);

    getch();
    return 0;
}