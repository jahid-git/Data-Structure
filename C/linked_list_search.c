#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createLinkedList(int arr[], int size);

int searchInLinkedList(struct Node *head, int value);

int main(){
    int arr[6] = { 5, 10, 30, 292, 62, 782 };
    struct Node *head;
    head = createLinkedList(arr, 6);
    printf("\nIndex: %d \n", searchInLinkedList(head, 10));
    return 0;
}

int searchInLinkedList(struct Node *head, int value){
    int index = 1;
    while(head != NULL){
        if(head->data == value){
            return index;
        }
        index++;
        head = head->next;
    }
    return -1;
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