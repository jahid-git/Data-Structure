#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createLinkedList(int arr[], int size);

void reverseLinkedList(struct Node *head);

int main(){
    int arr[6] = { 5, 10, 30, 292, 62, 782 };
    struct Node *head;
    head = createLinkedList(arr, 6);
    struct Node *newHead = head;
    while(head != NULL){
        printf("%d => ", head->data);
        head = head->next;
    }
    printf("NULL\n");
    reverseLinkedList(newHead);
    return 0;
}

void reverseLinkedList(struct Node *head){
    struct Node *prev = NULL, *current = head, *next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    while(head != NULL){
        printf("%d => ", head->data);
        head = head->next;
    }
    printf("NULL \n");
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