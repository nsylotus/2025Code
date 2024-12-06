#ifndef __DATASTRUCT_DOUBLELINKEDLIST_H__
#define __DATASTRUCT_DOUBLELINKEDLIST_H__

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node {
    struct Node* prev;
    ElementType data;
    struct Node *next;
} Node; // 全局变量

Node* InitDoubleLinkedList();

void DoubleLinkedListPrintf(Node* node);

void DoubleLinkedListTailInsert(Node* node, ElementType data);

void DoubleLinkedListHeadInsert(Node* node, ElementType data);

void DoubleLinkedListInsert(Node* node, int position, ElementType data);

void DeleteList(Node* node, int position);

int GetDoubleLinkedListLength(Node* node);

#endif //__DATASTRUCT_DOUBLELINKEDLIST_H__
