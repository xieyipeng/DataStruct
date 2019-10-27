//
// Created by xieyipeng on 2019/10/27.
//

#ifndef POSTGRADUATE_MATRIX_H
#define POSTGRADUATE_MATRIX_H

#endif //POSTGRADUATE_MATRIX_H

#include "stdlib.h"
#include "stdio.h"

#define MAXSIZE 100
#define FINITY 5000
typedef int VertexType;
typedef float EdgeType;

typedef struct {
    VertexType vertex[MAXSIZE];
    EdgeType edge[MAXSIZE][MAXSIZE];
    int n, e;
} MGraph;

void create(MGraph *graph, int c);

void dfs(MGraph graph, int i);

void dfsTraverse(MGraph graph);

