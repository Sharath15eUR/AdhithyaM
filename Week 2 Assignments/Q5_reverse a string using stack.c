#include <stdio.h>
#include <string.h>
#define SIZE 100

struct Stack{
    int top;
    char items[SIZE];
};

void initialize(struct Stack *stack){
    stack->top = -1;
    }

void push(struct Stack *stack, char item){
    if (stack->top == SIZE - 1){
            printf("Stack is Full\n");
    return;
    }
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack){
    if (stack->top == -1) {
        printf("Stack is Empty\n");
        }
    return stack->items[stack->top--];
}

void reversestr(char *string){
    struct Stack stack;
    initialize(&stack);
    for (int i = 0; i < strlen(string); i++){
            push(&stack, string[i]);
    }
    for (int i = 0; i < strlen(string); i++){
            string[i] = pop(&stack);
    }
}

int main() {
    char a[SIZE];
    printf("Enter String to be reversed: ");
    scanf("%[^\n]s",&a);
    printf("\nString before reversal: %s \n", a);
    reversestr(a);
    printf("\nString after reversal: %s \n", a);

}
