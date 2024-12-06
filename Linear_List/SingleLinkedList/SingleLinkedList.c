#include "SingleLinkedList.h"

void SingleLinkedListPrintf(Node *node) {
    Node *nodePtr = node;
    while (nodePtr->next != NULL) {
        nodePtr = nodePtr->next;
        printf("%d->", nodePtr->data);
    }
}

Node *InitSingleLinkedList() {
    Node *head = (Node *) malloc(sizeof(Node)); // 头节点
    head->data = -1;
    head->next = NULL;
    return head;
}

void SingleLinkedListInsert(Node *node, int position, ElementType data) {
    assert(node);
    if (position < 0) {
        return;
    }
    Node *nodePtr = node;
    Node *positionPtr = NULL;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    while (nodePtr != NULL && position-- > 0) {
        positionPtr = nodePtr;
        nodePtr = nodePtr->next;
    }
    newNode->next = nodePtr;
    positionPtr->next = newNode;
}

void SingleLinkedListTailInsert(Node *node, ElementType data) {
    assert(node);
    Node *nodePtr = node;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    while (nodePtr->next != NULL) {
        nodePtr = nodePtr->next;
    }
    nodePtr->next = newNode;
    newNode->next = NULL;
}

void SingleLinkedListHeadInsert(Node *node, ElementType data) {
    assert(node);
    Node *nodePtr = node;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = nodePtr->next;
    nodePtr->next = newNode;
}

int GetSingleLinkedListLength(Node *node) {
    int result = 0;
    Node *nodePtr = node;
    while (nodePtr->next != NULL) {
        result++;
        nodePtr = nodePtr->next;
    }
    return result; // 因为带头结点的了,所以要减1
}

int GetElementPosition(Node *node, int position) {
    Node *nodePtr = node;
    while (nodePtr != NULL && position-- > 0) {
        nodePtr = nodePtr->next;
    }
    return nodePtr->data;
}

Node *GetElementValue(Node *node, ElementType value) {
    Node *nodePtr = node;
    while (nodePtr != NULL) {
        nodePtr = nodePtr->next;
        if (nodePtr->data == value) {
            return nodePtr;
        }
    }
    return NULL;
}

void DeleteNode(Node *node, int position) {
    Node *nodePtr = node;
    for (int i = 0; nodePtr != NULL && i < position - 1; i++) {
        nodePtr = nodePtr->next;
    }
    Node *deleteNode = nodePtr->next;
    nodePtr->next = deleteNode->next;
    free(deleteNode);
}
