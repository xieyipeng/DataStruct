//
// Created by xieyipeng on 2019/10/25.
//

#ifndef POSTGRADUATE_BINT_NODE_H
#define POSTGRADUATE_BINT_NODE_H

#endif //POSTGRADUATE_BINT_NODE_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "malloc.h"

typedef char datatype;
typedef struct bint_node {
    datatype data;
    struct bint_node *left, *right;
} bint_node, *bin_tree;

bin_tree createBinTree();

void preOrder(bin_tree tree);

void preOrder1(bin_tree tree);

void inOrder(bin_tree tree);

void inOrder1(bin_tree tree);

void postOrder(bin_tree tree);

void postOrder1(bin_tree tree);

void levelOrder(bin_tree tree);

int numOfNode(bin_tree tree);

int isEqual(bin_tree tree1,bin_tree tree2);

int depth(bin_tree tree);

//  >>>>>>>>>>>>>>>>>>>>>>>> queue

typedef bin_tree ElemType;
#define MAXSIZE 100

typedef struct {
    ElemType data[MAXSIZE];
    int front, rear;
} binQueue;

void init_binQueue(binQueue *queue);
void EnBinQueue(binQueue *queue,ElemType elemType);
void DeBinQueue(binQueue *queue,ElemType *elemType);



//  >>>>>>>>>>>>>>>>>>>>>>>> stack

typedef struct {
    ElemType data[MAXSIZE];
    int tag[MAXSIZE];
    int top;
} binStack;

bool binPush(binStack *binStack, ElemType e);

ElemType binPop(binStack *binStack);

