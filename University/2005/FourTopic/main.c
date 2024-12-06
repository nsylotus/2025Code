/*
 * 设一个长度大于1的循环单链表中,
 * 既无头节点也无头指针,
 * P为指向该链表中某个节点的指针
 * 写一个删除该节点直接前驱节点的算法
 * */

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node {
    ElementType data;
    struct Node *next;
} Node; // 全局变量

Node* InitNodeList();
void printfNode();

Node* InitNodeList(int data){
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main(int argc, char const *argv[]) {
    for(int i =0;i<5;i++){

    }
    return 0;
}