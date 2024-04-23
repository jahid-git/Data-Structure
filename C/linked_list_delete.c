#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createLinkedList(int arr[], int size);
void Print(struct Node *head);

struct Node *delete(struct Node *head, int data);

int main(){
    int arr[5] = { 5, 10, 30, 45, 50 };
    struct Node *head;
    head = createLinkedList(arr, 5);
    Print(head);
    head = delete(head, 45);
    Print(head);
    return 0;
}

struct Node *delete(struct Node *head, int data){
    struct Node *dummyHead = (struct Node *) malloc(sizeof(struct Node));
    dummyHead->next = head;
    struct Node *temp = dummyHead;
    while(temp->next != NULL){
        if(temp->next->data == data){
            temp->next = temp->next->next;
            break;
        }
        temp = temp->next;
    }
    return dummyHead->next;
}

struct Node *createLinkedList(int arr[], int size){
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    
    int i;
    for(i = 0;i < size;i++){
        temp = (struct Node *) malloc(sizeof(struct Node));
        temp->data = arr[i];
        temp->next = NULL;
        if(head == NULL){
            head = temp;
            current = temp;
        } else {
            current->next = temp;
            current = current->next;
        }
    }
    
    return head;
}

void Print(struct Node *head){
    struct Node *current = head;
    while(current != NULL){
        printf("%d => ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}