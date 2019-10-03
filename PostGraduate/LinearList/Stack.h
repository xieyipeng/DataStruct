//
// Created by xieyipeng on 2019/10/3.
//

#ifndef POSTGRADUATE_STACK_H
#define POSTGRADUATE_STACK_H

#endif //POSTGRADUATE_STACK_H

#include "malloc.h"
#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 100

typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack sqStack);

void StackEmpty(SqStack sqStack);

void Push(SqStack sqStack, ElemType e);

void Pop(SqStack sqStack, ElemType e);

void GetTop(SqStack sqStack, ElemType *e);

void ClearStack(SqStack sqStack);

