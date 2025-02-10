// Create the complete binary search tree
#include <stdio.h>
#include <stdlib.h>
// decleration/ structure of Tree
struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} *root;
// function to insert node
void BST_insert(struct Node **root, int key)
{
    if (*root == NULL)
    {
        *root = (struct Node *)malloc(sizeof(struct Node));
        (*root)->value = key;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (key < (*root)->value)
        BST_insert(&((*root)->left), key);
    else if (key > (*root)->value)
        BST_insert(&((*root)->right), key);
}
// traversing the BST in Inorder
void inorder(struct Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}
// traversing the BST in Preorder
void preorder(struct Node *root)
{
    if (root)
    {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}
// traversing the BST in Postorder
void postorder(struct Node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}
// searching an element in Inorder manner
void search(struct Node *root, int key)
{
    if (root == NULL)
        return;
    search(root->left, key);
    if (root->value == key)
        printf("%d element found\n", key);
    search(root->right, key);
}
// main methdo
int main(){
    int n, data, item;
    printf("Enter the size of tree : ");
    scanf("\n%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value : ");
        scanf("\n%d", &data);
        BST_insert(&root, data);
    }
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    printf("Enetr the item to find : ");
    scanf("\n%d", &item);
    search(root, item);
    return 0;
}