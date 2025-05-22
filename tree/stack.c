#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** top, int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode; 
}

int pop(Node** top){
    if(*top == NULL) return -1;
    Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int peek(Node* top){
    if(top == NULL){
        return -1;
    }
    return top->data;
}

int isEmpty(Node* top){
    return top == NULL;
}

int main(){
    Node* stack = NULL;
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    printf("Top of stack: %d\n", peek(stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Popped: %d\n", pop(&stack));
    printf("Top of stack: %d\n", peek(stack));
    return 0;
}