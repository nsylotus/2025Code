#include "ArrayStack.h"

Stack *InitStack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->top = 0;
    return stack;
}

void Push(Stack *stack, ElementType data) {
    stack->array_stack[stack->top] = data;
    stack->top++;
}

ElementType Pop(Stack *stack) {
    int result = stack->array_stack[stack->top];
    stack->top--;
    return result;
}

ElementType GetTop(Stack *stack) {
    return stack->array_stack[stack->top];
}

bool isStackEmpty(Stack *stack) {
    return stack->top == 0;
}

void PrintfStack(Stack *stack) {
    int temp = stack->top;
    while (temp-- > 0) {
        printf("%d", stack->array_stack[temp]);
    }
    printf("\n");
}