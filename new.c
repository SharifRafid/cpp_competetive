#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct Node {
    int key;
    struct Node *left, *right;
};

// Function to create a new node with a given value
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to search for a node with a specific key
struct Node* searchNode(struct Node* root, int target) {
    if (root == NULL || root->key == target)
        return root;
    if (target < root->key)
        return searchNode(root->left, target);
    return searchNode(root->right, target);
}

// Function to insert a node
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->key)
        root->left = insertNode(root->left, value);
    else if (value > root->key)
        root->right = insertNode(root->right, value);
    return root;
}

// Post-order traversal
void postOrder(struct Node* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->key);
    }
}

// In-order traversal
void inOrder(struct Node* root) {
    if (root) {
        inOrder(root->left);
        printf(" %d ", root->key);
        inOrder(root->right);
    }
}

// Pre-order traversal
void preOrder(struct Node* root) {
    if (root) {
        printf(" %d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Find the node with the minimum value
struct Node* findMin(struct Node* root) {
    if (root == NULL || root->left == NULL)
        return root;
    return findMin(root->left);
}

// Delete a node from the tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            struct Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

int main() {
    struct Node* root = NULL;

    // Insert nodes
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Search for key 60
    if (searchNode(root, 60))
        printf("60 found\n");
    else
        printf("60 not found\n");

    // Traversals
    printf("Post-order:");
    postOrder(root);
    printf("\n");

    printf("Pre-order:");
    preOrder(root);
    printf("\n");

    printf("In-order:");
    inOrder(root);
    printf("\n");

    // Delete node 70
    root = deleteNode(root, 70);
    printf("In-order after deleting 70:");
    inOrder(root);
    printf("\n");

    return 0;
}
