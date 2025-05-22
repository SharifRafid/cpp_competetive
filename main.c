#include <stdio.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->prev = NULL;
    head->data = 10;

    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    second->prev = head;
    second->data = 11;
    head->next = second;

    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    third->prev = second;
    third->data = 12;
    second->next = third;

    struct Node *forth = (struct Node *)malloc(sizeof(struct Node));
    forth->prev = third;
    forth->data = 13;
    forth->next = NULL;
    third->next = forth;

    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    int position;
    printf("\nEnter Position To Delete : ");
    scanf("%d", &position);

    temp = head;
    // 10 11 12 13 
    for (int i = 1; i <= position-1; i++)
    {
        temp = temp->next;
        if(temp == NULL){
            printf("Limit Exceeded\n");
            return 0;
        }
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    }else{
        temp->next->prev = NULL;
        head = temp->next;
    }
    free(temp);

    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}