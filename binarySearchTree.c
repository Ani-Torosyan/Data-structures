#include <stdio.h>
#include <stdlib.h>

struct TreeNode 
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int value) 
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int value) 
{
    if (root == NULL) 
    {
        return createNode(value);
    }
    if (value < root->data) 
    {
        root->left = insertNode(root->left, value);
    } 
    else if (value > root->data) 
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}

struct TreeNode* minValueNode(struct TreeNode* node) 
{
    struct TreeNode* current = node;
    while (current && current->left != NULL) 
    {
        current = current->left;
    }
    return current;
}

struct TreeNode* deleteNode(struct TreeNode* root, int value) 
{
    if (root == NULL)
    {
        return root;
    }
    if (value < root->data) 
    {
        root->left = deleteNode(root->left, value);
    } 
    else if (value > root->data) 
    {
        root->right = deleteNode(root->right, value);
    } 
    else 
    {
        if (root->left == NULL) 
        {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        struct TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct TreeNode* search(struct TreeNode* root, int value) 
{
    if (root == NULL || root->data == value) 
    {
        return root;
    }
    if (value < root->data) 
    {
        return search(root->left, value);
    }
    return search(root->right, value);
}

void inorderTraversal(struct TreeNode* root) 
{
    if (root != NULL) 
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() 
{
    struct TreeNode* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    struct TreeNode* searchResult = search(root, 40);
    if (searchResult != NULL) 
    {
        printf("Element 40 found in the BST.\n");
    } else 
    {
        printf("Element 40 not found in the BST.\n");
    }

    root = deleteNode(root, 40);
    printf("Inorder traversal after deleting 40: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
