#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *link_prev;
    struct node *link_next;
};

int size = 0;
struct node *head, *tail = NULL;

void add(char data) {
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
        printf(" %c ", head->data);
        head = head->link_next;
    }
    printf(" \n ");
}

void rotate_by_n(int n){
    struct node *current = head;
	int i;
    if(n == 0 || n >= size){
	    return;
	}
    else{
        for(i = 1; i < n; i++){
                current = current->link_next;
        }
        tail->link_next = head;
        head = current->link_next;
        head->link_prev = NULL;
        tail = current;
        tail->link_next = NULL;
    }
}

int main()
{
    add('a');
    add('b');
    add('c');
    add('d');
    add('e');
    add('f');
    add('g');
    add('h');
    printf("Doubly linked list before rotation: ");
    display(head);
    int n;
	printf("Enter the number of rotation:");
	scanf("%d",&n);
    rotate_by_n(n);
    printf("Doubly Linked List after rotation by %d nodes: ",n);
    display(head);
}
