//
// Created by xieyipeng on 2019/10/3.
//

#ifndef POSTGRADUATE_DLINKLIST_H
#define POSTGRADUATE_DLINKLIST_H

#endif //POSTGRADUATE_DLINKLIST_H

#include "malloc.h"
#include "stdio.h"
#include "stdlib.h"

typedef int ElemType;
typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;
