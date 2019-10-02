//
// Created by xieyipeng on 2019/9/28.
//

#ifndef POSTGRADUATE_LINKLIST_H
#define POSTGRADUATE_LINKLIST_H

#endif //POSTGRADUATE_LINKLIST_H

#include "malloc.h"
#include "stdio.h"
#include "stdlib.h"


typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList ListHeadInsert(LinkList linkList);

LinkList ListTailInsert(LinkList linkList);

void PrintLinkList(LinkList linkList);

LinkList GetElemFromI(LinkList linkList, int i);

LinkList GetElemFromV(LinkList linkList, ElemType e);

LinkList InsertI(LinkList linkList, int i, ElemType e);

LinkList DeleteElemFromI(LinkList linkList, int i);

int LinkListLength(LinkList linkList);

LinkList LinkListReverse(LinkList linkList);
