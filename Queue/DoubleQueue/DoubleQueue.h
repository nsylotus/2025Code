#ifndef __DOUBLEQUEUE_H__
#define __DOUBLEQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

#define MAXSIZE 10

typedef int ElementType;

typedef struct DoubleQueue {
    int length;
    int front;
    int rear;
    ElementType array_queue[MAXSIZE];
} Queue;

Queue *InitDoubleQueue();

bool isQueueEmpty(Queue *queue);

void frontEnQueue(Queue* queue, ElementType data);

void frontDeQueue(Queue* queue);

void rearEnQueue(Queue *queue, int data);

void rearDeQueue(Queue* queue);

bool isFull(Queue *queue);

// 返回队列头部的数据(不弹出),如果没有数返回-1
ElementType Front(Queue *queue);

// 返回队列尾部的数据(不弹出),如果没有数返回-1
ElementType Rear(Queue *queue);

void PrintfDoubleQueue(Queue *queue);

#endif //__DOUBLEQUEUE_H__