// preorder traversal: root, left, right
// postorder traversal: left, right, root
// inorder traversal: left, root, right
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *left;
    struct node *right;
    int data;
} node;

node *createNode(int data)
{
    node *ptr = malloc(sizeof(node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

// black magic fr fr
// literally just copy the definition cuz ts is peak
void preorderTraversal(node *root)
{
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(node *root)
{
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void inorderTraversal(node *root)
{
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    node *root = createNode(67);
    node *p1 = createNode(69);
    node *p2 = createNode(420);
    root->left = p1;
    root->right = p2;
    preorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    return 0;
}
