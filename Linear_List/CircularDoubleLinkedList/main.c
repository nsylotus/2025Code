#include "CircularDoubleLinkedList.h"
#include <windows.h>

void CircularDoubleLinkedListTest() {
    Node *node = InitCircularDoubleLinkedList();
    ListHeadInsert(node, 1);
    ListHeadInsert(node, 2);
    ListHeadInsert(node, 3);
    ListTailInsert(node, 10);
    ListTailInsert(node, 20);
    PrintList(node);
    ListInsert(node, 3, 100);
    PrintList(node);
    printf("\n双循环链表的长度是%d", GetLength(node));
}

int main(int argc, char const *argv[]) {
    SetConsoleOutputCP(65001);
    CircularDoubleLinkedListTest();
    return 0;
}