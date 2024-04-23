#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createLinkedList(int arr[], int size);

int main(){
    int arr[6] = { 5, 10, 30, 292, 62, 782 };
    struct Node *head;
    head = createLinkedList(arr, 6);
    while(head != NULL){
        printf("%d => ", head->data);
        head = head->next;
    }
    return 0;
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