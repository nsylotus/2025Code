#ifndef __CIRCULARDOUBLELINKEDLIST_H__
#define __CIRCULARDOUBLELINKEDLIST_H__

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct CircularDoubleLinkedList {
    struct CircularDoubleLinkedList *prev;
    ElementType data;
    struct CircularDoubleLinkedList *next;
} Node;

Node *InitCircularDoubleLinkedList();

void ListHeadInsert(Node *node, int data);

void ListTailInsert(Node *node, int data);

void ListInsert(Node *node, int position, int data);

int GetLength(Node *node);

void PrintList(Node *node);

#endif // __CIRCULARDOUBLELINKEDLIST_H__