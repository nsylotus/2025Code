#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAXSIZE 10

typedef int ElementType;

typedef struct Stack {
    int top;
    ElementType array_stack[MAXSIZE];
} Stack;

Stack *InitStack();

void Push(Stack *stack, ElementType data);

ElementType Pop(Stack *stack);

ElementType GetTop(Stack *stack);

bool isStackEmpty(Stack *stack);

void PrintfStack(Stack *stack);

#endif //__ARRAYSTACK_H

