#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* createNode(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data){
    if(root == NULL) return createNode(data);
    if(data < root->data) root->left = insertNode(root->left, data);
    else root->right = insertNode(root->right, data);
    return root;
}

Node* searchNode(Node* root, int key){
    if(root == NULL || root->data == key) return root;
    if(key < root->data) return searchNode(root->left, key);
    else return searchNode(root->right, key);
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

Node* findMin(Node* root){
    while(root && root->left != NULL) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key){
    if(root == NULL) return NULL;
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        root = insertNode(root, arr[i]);

    printf("Inorder: "); inorder(root); printf("\n");
    printf("Preorder: "); preorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");

    int key = 60;
    Node* found = searchNode(root, key);
    if (found)
        printf("Key %d found in BST\n", key);
    else
        printf("Key %d not found\n", key);

    root = deleteNode(root, 30);
    printf("After deleting 30, Inorder: ");
    inorder(root); printf("\n");

    Node* minNode = findMin(root);
    printf("Minimum value in BST: %d\n", minNode->data);

    return 0;
}