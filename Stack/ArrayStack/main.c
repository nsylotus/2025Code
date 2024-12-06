#include "ArrayStack.h"

void Stack_Test() {
    Stack *stack = InitStack();
    printf("%d\n", isStackEmpty(stack));
    for (int i = 0; i < MAXSIZE; i++) {
        Push(stack, i + 1);
    }
    PrintfStack(stack);
    Pop(stack);
    Pop(stack);
    PrintfStack(stack);
    GetTop(stack);
    PrintfStack(stack);
    printf("%d\n", isStackEmpty(stack));
}

int main(int argc, char const *argv[]) {
    Stack_Test();
    return 0;
}