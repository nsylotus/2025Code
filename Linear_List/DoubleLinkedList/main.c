#include "DoubleLinkedList.h"
#include <windows.h>

void DoubleLinkedListTest(){
    Node* node = InitDoubleLinkedList();
    DoubleLinkedListTailInsert(node, 10);
    DoubleLinkedListTailInsert(node, 20);
    DoubleLinkedListTailInsert(node, 30);
    DoubleLinkedListHeadInsert(node, 100);
    DoubleLinkedListHeadInsert(node, 200);
    DoubleLinkedListPrintf(node);
    printf("链表的长度是%d\n", GetDoubleLinkedListLength(node));
    DeleteList(node, 3);
    // DeleteList(node, GetDoubleLinkedListLength(node)); bug
    DoubleLinkedListPrintf(node);
    DoubleLinkedListInsert(node,4,666);
    DoubleLinkedListPrintf(node);
    // DoubleLinkedListInsert(node, 6,999); // bug
    // DoubleLinkedListPrintf(node);
}

int main(int argc, char const *argv[]) {
    SetConsoleOutputCP(65001);
    DoubleLinkedListTest();
    return 0;
}
