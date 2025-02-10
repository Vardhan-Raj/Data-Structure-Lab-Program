// Create the complete binary tree
#include <stdio.h>
#include <stdlib.h>
// decleration/ structure of Tree
struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} *root;
// function to create node
void createNode(struct Node **node, int data)
{
    *node = (struct Node *)malloc(sizeof(struct Node));
    (*node)->value = data;
    (*node)->left = NULL;
    (*node)->right = NULL;
}
// traversing the CBT in Inorder
void inorder(struct Node *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right); 
    }
}
// traversing the CBT in Preorder
void preorder(struct Node *root){
    if(root){
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}
// traversing the CBT in Postorder
void postorder(struct Node *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}
// searching an element in Inorder manner
void search(struct Node *root, int key)
{
    if(root == NULL)
        return ;
    search(root->left, key);
    if(root->value == key)
        printf("%d element found\n", key);
    search(root->right, key);
}

// main method
int main()
{
    createNode(&root, 12);
    createNode(&(root->left), 56);
    createNode(&(root->left->left), 9);
    createNode(&(root->left->left->left), 34);
    createNode(&(root->left->left->right), 21);
    createNode(&(root->left->right), 16);
    createNode(&(root->left->right->left), 26);
    createNode(&(root->right), 64);
    createNode(&(root->right->left), 20);
    createNode(&(root->right->right), 30);
    printf("The CBT in Inorder is : ");
    inorder(root);
    printf("\n");
    printf("The CBT in Preorder is : ");
    preorder(root);
    printf("\n");
    printf("The CBT in Postoredr is : ");
    postorder(root);
    printf("\n");
    search(root, 12);
    return 0;
}