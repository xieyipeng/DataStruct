//
// Created by xieyipeng on 2019/9/28.
//

#ifndef POSTGRADUATE_SEQUENCELIST_H
#define POSTGRADUATE_SEQUENCELIST_H

#endif //POSTGRADUATE_SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SequenceMaxsize 100
typedef int ElementType;

//TODO: 数组静态分配
typedef struct {
    ElementType data[SequenceMaxsize];
    int size;
} SqList_Static;

//TODO: 数组动态分配
//typedef struct {
//    ElementType *data;
//    int length;
//} SqList_Dynamic;


bool ListInsert(SqList_Static *sqList, int i, ElementType e);
void InitList(SqList_Static *sqList);
void DestroyList(SqList_Static *sqList);
void PrintList(SqList_Static sqList);
int LocateElem(SqList_Static sqList, ElementType e);
bool ListDelete(SqList_Static *sqList, int i, ElementType *e);
ElementType GetElem(SqList_Static sqList, int i);
bool Empty(SqList_Static sqList);
int Length(SqList_Static sqList);
void Reverse(SqList_Static *sqList);
