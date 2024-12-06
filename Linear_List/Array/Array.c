#include "Array.h"
#include <stdbool.h>

void InitList(SeqList *linear_array) { linear_array->length = 0; }

bool ListInsert(SeqList *linear_array, int position, ElementType elementData) {
  if (position < 1 || position > MAXSIZE + 1) {
    return false;
  }
  if (position > MAXSIZE) {
    return false;
  }
  for (int i = linear_array->length; i >= position; i--) {
    linear_array->data[i] = linear_array->data[i - 1];
  }
  linear_array->data[position - 1] = elementData;
  linear_array->length++;
  return true;
};

ElementType DeleteListElement(SeqList *linear_array, int position) {
  ElementType temp = linear_array->data[position - 1];
  for (int j = position; j < linear_array->length; j++) {
    linear_array->data[j - 1] = linear_array->data[j];
  }
  linear_array->length--;
  return temp;
}

int SearchListElement(SeqList *linear_array, ElementType value) {
  for (int i = 0; i < linear_array->length; i++) {
    if (value == linear_array->data[i]) {
      return i; // 返回其下标
    }
  }
  return -1;
}

void PrintList(SeqList *linear_array) {
  for (int i = 0; i < linear_array->length; i++) {
    printf("%d ", linear_array->data[i]);
  }
}