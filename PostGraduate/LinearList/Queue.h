//
// Created by xieyipeng on 2019/10/4.
//

#ifndef POSTGRADUATE_QUEUE_H
#define POSTGRADUATE_QUEUE_H

#endif //POSTGRADUATE_QUEUE_H

#include "stdbool.h"
#include "malloc.h"
#include "stdio.h"
#include "stdlib.h"

#define Maxsize 100

typedef int ElemType;
typedef struct {
    ElemType data[Maxsize];
    int front, rear;
} Queue;

void InitQueue(Queue *queue);

bool QueueEmpty(Queue queue);

bool EnQueue(Queue *queue, ElemType e);

bool DeQueue(Queue *queue, ElemType *e);

void GetHead(Queue queue, ElemType *e);

void ClearQueue(Queue *queue);
