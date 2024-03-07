#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val){
    if (rear == SIZE-1)
    {
        printf("\n Queue is Full \n");
    }
    else{
            if (front == -1){
                front = 0;
    }
    rear++;
    queue[rear] = val;
    }
}

void dequeue(){
    if (front==-1 || front>rear){
        printf("Queue is empty\n");
        return;
    }
    front++;
}

int is_empty(){
    if (front==-1 || front>rear){
        return 1;
    }
    return 0;
}

void display(){
    if (rear == -1){
        printf("Queue is empty\n");
    }
    else{
            int i;
    for (i = front; i <= rear; i++){
            printf("%d ", queue[i]);
    }
    printf("\n");
    }
}

int count(){
    int count = 0;
    if (rear == -1)
        printf("Queue is empty\n");

    else if(front != -1 && rear != -1){
        for (int i = front; i <= rear; i++){
            count++;
        }
    }
    return count;
}

int main()
{
    int choice, data;
    printf("\nQueue Operations:\n");
        printf("1. Check Whether Queue is Empty\n");
        printf("2. Enqueue\n");
        printf("3. Dequeue\n");
        printf("4. Display Count\n");
        printf("5. Display \n");
        printf("6. Exit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
             case 1:
                printf("Check wheteher Queue is empty? %s\n",is_empty() ? "Queue is empty" : "Queue is not empty");
                break;
            case 2:
                printf("Enter the element to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 3:
                dequeue(queue);
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 4:
                printf("Count of elements in the queue: %d\n",count(queue));
                break;
            case 5:
                printf("\nElements of the queue are : ");
                display();
                break;
            case 6:
                printf("Exiting Program\n");
                break;

            default:
                printf("Enter between 1 & 6\n");
        }
    } while (choice != 6);

}

