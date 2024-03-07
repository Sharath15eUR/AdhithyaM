#include <stdio.h>
#include <stdlib.h>

struct node{
int data;
struct node* link;
};

void add(struct node** a, int data){
struct node* newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = data;
newnode->link = NULL;

if(*a == NULL){
    *a=newnode;
}else{
struct node* current = *a;
while(current->link != NULL){
    current = current->link;
}
current->link = newnode;
}
}

void display(struct node* head){
struct node* current = head;
while (current != NULL){
    printf(" %d   ",current->data);
    current = current->link;
}
printf("\n");
}

void remove_dupes(struct Node* head){
    if (head == NULL)
        return;
    struct node* current = head;
    while (current->link != NULL){
            if (current->data == current->link->data){
                struct Node* temp = current->link;
    current->link = current->link->link;
    free(temp);
    }
    else{
            current = current->link;
        }
    }
}

int main()
{
struct node* head = NULL;

add(&head,2);
add(&head,3);
add(&head,3);
add(&head,4);
 printf("Linked List before removing duplicates : ");
    display(head);
    remove_dupes(head);
    printf("Linked List after removing duplicates: ");
    display(head);

}
