#include "SingleLinkedList.h"
#include <windows.h>

void SingleLinkedListTest() {
    Node *node = InitSingleLinkedList();
    SingleLinkedListTailInsert(node, 10);
    SingleLinkedListTailInsert(node, 20);
    SingleLinkedListTailInsert(node, 30);
    SingleLinkedListHeadInsert(node, 100);
    SingleLinkedListHeadInsert(node, 200);
    SingleLinkedListInsert(node, 3, 666);
    SingleLinkedListInsert(node, 1, 888);
    SingleLinkedListInsert(node, GetSingleLinkedListLength(node)+1, 999);
    SingleLinkedListPrintf(node);
    printf("\n链表的长度是%d\n", GetSingleLinkedListLength(node));
    printf("%d\n", GetElementValue(node, 30)->data);
    printf("第%d节点是%d\n", 2,GetElementPosition(node, 2));
    DeleteNode(node, 2);
    SingleLinkedListPrintf(node);
    printf("\n");
    DeleteNode(node, GetSingleLinkedListLength(node));
    SingleLinkedListPrintf(node);
}

int main(int argc, char const *argv[]) {
    SetConsoleOutputCP(65001);
    SingleLinkedListTest();
    return 0;
}