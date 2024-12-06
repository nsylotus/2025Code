#include "CircularDoubleLinkedList.h"

Node *InitCircularDoubleLinkedList() {
    Node *head = (Node *) malloc(sizeof(Node));
    head->next = head;
    head->data = -1;
    head->prev = head;
    return head;
}

void ListHeadInsert(Node *node, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    if (node->next == node) {
        node->next = newNode;
        newNode->prev = node;
        newNode->next = node;
        node->prev = newNode;
    } else {
        newNode->next = node->next;
        newNode->prev = node;
        node->next = newNode;
        node->next->prev = newNode;
    }
}

void ListTailInsert(Node *node, int data) {
    assert(node);
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    newNode->prev = node->prev;
    node->prev->next = newNode;
    node->prev = newNode;
    newNode->next = node;
}

void ListInsert(Node *node, int position, ElementType data) {
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

int GetLength(Node *node) {
    int count = 0;
    Node *current = node;
    while (current->next != node) {
        count++;
        current = current->next;
    }
    return count;
}

void PrintList(Node *node) {
    Node *current = node;
    while (current->next != node) {
        current = current->next;
        printf("%d<=>", current->data);
    }
    printf("\n");
}