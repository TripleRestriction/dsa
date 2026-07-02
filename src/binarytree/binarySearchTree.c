// properties
// all values in the left sub tree are less than the value of parent node
// all values in the right sub tree are greater than the value of parent node
// no duplicate values
// fact:
// inorder traversal of a bst gives an ascending sorted array
// so you can just calculate the inorder and if it is sorted ascending 
// then the structure is a bst
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isBST(node *root)
{
    static node* prev = NULL;
    if (root != NULL) {
        if (!isBST(root->left)) {
	    return false;
        }
        if (prev != NULL && root->data <= prev->data) {
	    return false;
        }
        prev = root;
	return isBST(root->right);
    } else {
	return true;
    }
}

int main()
{
    node *root = createNode(5);
    node *p1 = createNode(3);
    node *p2 = createNode(6);
    node *p3 = createNode(1);
    node *p4 = createNode(4);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorderTraversal(root); // will be ascending
    printf("\n");
    if (isBST(root)) {
        printf("is a bst\n");
    } else {
	printf("not a bst\n");
    }
    return 0;
}
