#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link_prev;
    struct node *link_next;
};

int size = 0;
struct node *head, *tail = NULL;

//add to the end of doubly linked list
void add(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if(head == NULL){
        head = tail = newnode;
        head->link_prev = NULL;
        tail->link_next = NULL;
    }
    else{
        tail->link_next = newnode;
        newnode->link_prev = tail;
        tail = newnode;
        tail->link_next = NULL;
    }
    size+=1;
}

void display(struct node* head){
    while (head != NULL) {
        printf(" %d ", head->data);
        head = head->link_next;
    }
    printf(" \n ");
}

void addsorted(struct node** head,int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link_prev = NULL;
    newnode->link_next = NULL;
    if (*head == NULL){
            *head = newnode;
    }
    else if(data <= (*head)->data){
            newnode->link_next = *head;
            (*head)->link_prev = newnode;
            *head = newnode;
    }
    else{
            struct node* current = *head;
            while(current->link_next != NULL && current->link_next->data < data){
            current = current->link_next;
        }
        newnode->link_next = current->link_next;
        if (current->link_next != NULL){
            current->link_next->link_prev = newnode;
        }
        newnode->link_prev = current;
        current->link_next = newnode;
    }
}

int main()
{
    add(3);
    add(5);
    add(8);
    add(10);
    add(12);
    printf("Doubly linked list before insertion: ");
    display(head);
    addsorted(&head, 9);
    printf("Doubly linked list after insertion");
    display(head);
}
