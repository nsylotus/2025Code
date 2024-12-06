#ifndef __SINGLELINKEDLIST_H__
#define __SINGLELINKEDLIST_H__

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node {
    ElementType data;
    struct Node *next;
} Node; // 全局变量

void SingleLinkedListPrintf(Node *node);

Node *InitSingleLinkedList();

void SingleLinkedListInsert(Node *node, int position, ElementType data);

void SingleLinkedListTailInsert(Node *node, ElementType data);

void SingleLinkedListHeadInsert(Node *node, ElementType data);

int GetSingleLinkedListLength(Node *node);

int GetElementPosition(Node *node, int position);

Node *GetElementValue(Node *node, ElementType value);

void DeleteNode(Node *node, int position);

#endif // __SINGLELINKEDLIST_H__
