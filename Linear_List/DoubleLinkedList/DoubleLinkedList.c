#include "DoubleLinkedList.h"

Node *InitDoubleLinkedList() {
    Node *head = (Node *) malloc(sizeof(Node));
    head->data = -1;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

void DoubleLinkedListPrintf(Node *node) {
    Node *nodePtr = node;
    while (nodePtr->next != NULL) {
        nodePtr = nodePtr->next;
        printf("%d->", nodePtr->data);
    }
    printf("\n");
}

void DoubleLinkedListTailInsert(Node *node, ElementType data) {
    Node *nodePtr = node;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    while (nodePtr->next != NULL) {
        nodePtr = nodePtr->next;
    }
    nodePtr->next = newNode;
    newNode->prev = nodePtr;
}

void DoubleLinkedListHeadInsert(Node *node, ElementType data) {
    Node *nodePtr = node;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = nodePtr->next;
    nodePtr->next->prev = newNode;
    nodePtr->next = newNode;
    newNode->prev = nodePtr;
}

void DoubleLinkedListInsert(Node *node, int position, ElementType data) {
    Node *nodePtr = node;
    Node *positionPrev = NULL;
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    while (nodePtr != NULL && position-- > 0) {
        positionPrev = nodePtr;
        nodePtr = nodePtr->next;
    }
    positionPrev->next = newNode;
    newNode->next = nodePtr;
    newNode->prev = positionPrev;
    nodePtr->prev = newNode;
}

void DeleteList(Node *node, int position) {
    Node *nodePtr = node;
    Node *positionPrev = node;
    while (nodePtr->next != NULL && position-- > 0) {
        positionPrev = nodePtr;
        nodePtr = nodePtr->next;
    }
    positionPrev->next = nodePtr->next;
    nodePtr->next->prev = positionPrev;
    nodePtr->prev = NULL;
    nodePtr->next = NULL;
    free(nodePtr);
}

int GetDoubleLinkedListLength(Node *node) {
    Node *nodePtr = node;
    int count = 0;
    while (nodePtr->next != NULL) {
        count++;
        nodePtr = nodePtr->next;
    }
    return count;
}