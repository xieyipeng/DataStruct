//
// Created by xieyipeng on 2019/10/3.
//

#ifndef POSTGRADUATE_STACK_H
#define POSTGRADUATE_STACK_H

#endif //POSTGRADUATE_STACK_H

#include "stdbool.h"
#include "malloc.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#define MAXSIZE 100

typedef char ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int top;
} SqStack;

void InitStack(SqStack *sqStack);

bool StackEmpty(SqStack sqStack);

bool Push(SqStack *sqStack, ElemType e);

bool Pop(SqStack *sqStack, ElemType *e);

bool GetTop(SqStack sqStack, ElemType *e);


