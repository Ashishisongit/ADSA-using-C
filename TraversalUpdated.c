#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
    int data; 
    struct node *left;
    struct node *right;
};


struct node *insert(struct node *root, int val);
struct node *search(struct node *root, int key);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);
void clear(struct node *root);


struct node *search(struct node *root, int key)
{
    
    if (root == NULL || root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}

struct node *insert(struct node *root, int val)
{
    if (root == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if (val > root->data)
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
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;

    
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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
    int n, val, i, k;

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
    printf("\n\n");

    
    printf("Enter the key to search: ");
    scanf("%d", &k);
    
    struct node *result = search(root, k);
    if (result != NULL)
    {
        printf("Element %d found in the BST!\n", result->data);
    }
    else
    {
        printf("Element %d was not found in the BST.\n", k);
    }

    
    clear(root);
    
    printf("\nPress any key to exit...");
    getch();
    return 0;
}
