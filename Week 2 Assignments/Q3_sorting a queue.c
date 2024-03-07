#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

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

void sort(){
    int i, j, temp;
    int n = rear - front + 1;
    for (i = 0; i < n - 1; i++){
        for (j = i + 1; j < n; j++){
            if (queue[i] > queue[j]){
                queue[i]=queue[i]+queue[j];
                queue[j]=queue[i]-queue[j];
                queue[i]=queue[i]-queue[j];
            }
        }
    }
}

int main()
{
    enqueue(4);
    enqueue(2);
    enqueue(7);
    enqueue(5);
    enqueue(1);
    printf("\nElements of the queue before sorting : ");
    display();
    printf("\nElements of the queue after sorting : ");
    sort();
    display();
}
