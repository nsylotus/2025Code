#include "DoubleQueue.h"

Queue *InitDoubleQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->length = 0;
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

bool isQueueEmpty(Queue *queue) {
    return queue->length == 0;
}

void frontEnQueue(Queue *queue, ElementType data) {
    if (queue->length == MAXSIZE) {
        return;  // 队列已满
    }
    // 将front指针前移一个位置 (考虑环状队列)
    queue->front = (queue->front--) % MAXSIZE;

    // 在新的front位置插入数据
    queue->array_queue[queue->front] = data;
    queue->length++;  // 增加队列长度
}

void frontDeQueue(Queue *queue) {
    if (queue->length == 0) {
        return;
    }
    queue->array_queue[(queue->front++) % MAXSIZE];
    queue->length--;
}

void rearEnQueue(Queue *queue, int data) {
    if (queue->length == MAXSIZE) {
        return;
    }
    queue->array_queue[(queue->rear++) % MAXSIZE] = data;
    queue->length++;
}

void rearDeQueue(Queue *queue) {
    if (queue->length == 0) {
        return;
    }
    queue->array_queue[(queue->rear--) % MAXSIZE];
    queue->length--;
}

bool isFull(Queue *queue) {
    return queue->length == sizeof(queue->array_queue) / sizeof(queue->array_queue[0]);
}

// 返回队列头部的数据(不弹出),如果没有数返回-1
ElementType Front(Queue *queue) {
    return queue->array_queue[(queue->front) % MAXSIZE];
}

// 返回队列尾部的数据(不弹出),如果没有数返回-1
ElementType Rear(Queue *queue) {
    return queue->array_queue[(queue->rear) % MAXSIZE];
}

void PrintfDoubleQueue(Queue *queue) {
    int i = (queue->front) % MAXSIZE;
    while (i != queue->rear) {
        printf("%d", queue->array_queue[i % MAXSIZE]);
        i++;
    }
    printf("\n");
}
