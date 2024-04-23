#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createLinkedList(int arr[], int size);
void printList(struct Node *head);

struct Node *insertAtBeginning(struct Node *head, int data);
struct Node *insert(struct Node *head, int position, int data);
struct Node *insertAtTheEnd(struct Node *head, int data);

int main(){
    int arr[5] = { 5, 10, 30, 35, 40 };
    struct Node *head;
    head = createLinkedList(arr, 5);
    printList(head);
    head = insertAtBeginning(head, 1);
    head = insert(head, 1, 555);
    head = insertAtTheEnd(head, 60);
    return 0;
}

void printList(struct Node *head){
    struct Node *current = head;
    while(current != NULL){
        printf("%d => ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node *insertAtBeginning(struct Node *head, int data){
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = head;
    printList(temp);
    return temp;
}

struct Node *insert(struct Node *head, int position, int data){
    struct Node *temp = head;
    int i;
    for(i = 0;temp != NULL;i++){
        if(i == position){
            struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
        }
        temp = temp->next;
    }
    printList(head);
    return head;
}

struct Node *insertAtTheEnd(struct Node *head, int data){
    struct Node *current = head;
    while(current->next != NULL){
        current = current->next;
    }
    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    current->next = temp;
    printList(head);
    return head;
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