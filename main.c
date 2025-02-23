#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

void printList(struct Node *head){
    struct Node *ptr;
    ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    struct Node *head, *second, *third;
    
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    head->data = 10;
    head->prev = NULL;
    head->next = second;

    second->data = 11;
    second->prev = head;
    second->next = third;
    
    third->data = 12;
    third->prev = second;
    third->next = NULL;

    printList(head);

    struct Node *new;
    new = (struct Node*) malloc(sizeof(struct Node));
    new->next = head;
    new->prev = NULL;
    new->data = 9;

    head->prev = new;
    head = new;

    printList(head);

    struct Node *last;
    last = (struct Node*) malloc(sizeof(struct Node));
    last->next = NULL;
    last->data = 13;
    
    struct Node *temp;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = last;
    last->prev = temp;

    printList(head);

    struct Node *mid;
    mid = (struct Node*) malloc(sizeof(struct Node));
    mid->data = 100;
     
    int pos;
    printf("Enter Position To Insert : ");
    scanf("%d", &pos);
    
    struct Node *ptr;
    ptr = head;
    for(int i=0; i<pos-1; i++){
        ptr = ptr->next;
    }

    mid->next=ptr->next->next;
    ptr->next->next->prev = mid;
    ptr->next = mid;
    mid->prev = ptr;

    printList(head);    

    return 0;

}