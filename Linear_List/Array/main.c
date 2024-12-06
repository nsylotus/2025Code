#include "Array.h"
#include <stdio.h>

void Linear_Array_Test() {
  SeqList seqlist;
  InitList(&seqlist);
  ListInsert(&seqlist, 1, 10);
  ListInsert(&seqlist, 2, 20);
  ListInsert(&seqlist, 3, 30);
  ListInsert(&seqlist, 2, 40);
  PrintList(&seqlist);
  printf("\n");
  DeleteListElement(&seqlist, 2);
  PrintList(&seqlist);
  printf("\n");
  printf("%d\n", SearchListElement(&seqlist, 20));
};

int main(int argc, char const *argv[]) {
  Linear_Array_Test();
  return 0;
}