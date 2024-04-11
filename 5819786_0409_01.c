#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5

typedef int element;
element stack[MAX_STACK_SIZE];

int top = -1;

//is_full
int is_full() {
    return (top == MAX_STACK_SIZE - 1);
}

//is_empty
int is_empty() {
    return(top == -1);
}

//push 
void push(element item) {
    if (is_full()) {
        fprintf(stderr, "Stack is Full!\n");
        return;
    }
    else {
        top += 1;
        stack[top] = item;
    }
}

element pop() {
    element r;
    if (is_empty()) {
        fprintf(stderr, "Stack is Empty!\n");
        return 1;
    }
    else
        return(stack[top--]);
}

element peek() {
    element r;
    if (is_empty()) {
        fprintf(stderr, "Stack is Empty!\n");
        exit(1);
    }
    else
        return(stack[top]);
}

void print_stack() {
    if (is_empty()) {
        printf("Stack is Empty!\n");
        return;
    }

    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    element e = 0;
    srand(time(NULL));
    for (int k = 0;k < 30;k++) {
        e = (rand() % 100) + 1;
        if (e % 2 == 0) { //짝수
            printf("current rand_num : %d | even\n", e);
            push(e);
            printf("Push %d\n", e);
            print_stack();
        }
        else if (e % 2 == 1) {
            printf("current rand_num : % d | odd\n", e);
            e = pop();
            printf("Pop %d\n", e);
            print_stack();
        }
    }
}
