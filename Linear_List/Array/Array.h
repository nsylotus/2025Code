#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 10

typedef int ElementType;

typedef struct Array_Linear {
  ElementType data[MAXSIZE];
  int length;
} SeqList;

void InitList(SeqList *linear_array);

void PrintList(SeqList *linear_array);

bool ListInsert(SeqList *linear_array, int position, ElementType elementData);

ElementType DeleteListElement(SeqList *linear_arraya, int position);

int SearchListElement(SeqList *linear_array, ElementType value);

#endif // __ARRAY_H__
