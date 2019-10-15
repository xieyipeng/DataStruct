//
// Created by xieyipeng on 2019/10/4.
//

#include "Queue.h"

void InitQueue(Queue *queue) {
    queue->front = queue->rear = 0;
}

bool QueueEmpty(Queue queue) {
    if (queue.rear == queue.front) return true;
    else return false;
}

bool EnQueue(Queue *queue, ElemType e) {
    if ((queue->rear + 1) % Maxsize == queue->front) return false;
    queue->data[queue->rear] = e;
    queue->rear = (queue->rear + 1) % Maxsize;
    return true;
}

bool DeQueue(Queue *queue, ElemType *e) {
    if (queue->front == queue->rear) return false;
    *e = queue->data[queue->front];
    queue->front = (queue->front + 1) % Maxsize;
    return true;
}

void GetHead(Queue queue, ElemType *e) {
    *e = queue.data[queue.front];
}

int GetSize(Queue queue) {
    return queue.rear - queue.front;
}


void ClearQueue(Queue *queue) {
    queue->front = queue->rear = 0;
}


//int main() {
//    Queue queue;
//    InitQueue(&queue);
//    printf("queue: %d\n", QueueEmpty(queue) ? 0 : 1);
//    for (int i = 0; i < 99; ++i) { //牺牲一个存储单元判满
//        bool b = EnQueue(&queue, 12);
//        printf("i=%d,size: %d\n", i, GetSize(queue));
//    }
//
//    for (int j = 0; j < 100; ++j) {
//        ElemType e;
//        DeQueue(&queue, &e);
//    }
//    printf("size: %d\n", GetSize(queue));
//    return 0;
//}