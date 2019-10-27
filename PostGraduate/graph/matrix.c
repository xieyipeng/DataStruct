//
// Created by xieyipeng on 2019/10/27.
//

#include <mbstring.h>
#include <stdbool.h>
#include "matrix.h"

/**
 * 邻接矩阵创建图
 * @param graph
 * @param c 有向（1）或无向（0）图
 */
void create(MGraph *graph, int c) {
    graph->n = 0;
    graph->e = 0;
    int i, j;
    char ch[20];
    FILE *edge = fopen("E:\\DataStructure\\PostGraduate\\graph\\edge.txt", "r");
    FILE *vertex = fopen("E:\\DataStructure\\PostGraduate\\graph\\vertex.txt", "r");
    if (!edge || !vertex) {
        printf("file open error!!");
    } else {
        while (!feof(vertex)) {
            fscanf(vertex, "%d", &graph->vertex[graph->n]);
            graph->n++;
        }
        for (int m = 0; m <= graph->n; ++m) {
            for (int k = 0; k <= graph->n; ++k) {
                graph->edge[m][k] = FINITY;
            }
        }
        while (!feof(edge)) {
            fscanf(edge, "%d %d %s", &i, &j, ch);
            graph->edge[i][j] = atof(ch);
            graph->edge[j][i] = atof(ch);
            graph->e++;
        }
//        for (int k = 0; k < graph->n; ++k) {
//            printf("%d-", graph->vertex[k]);
//        }
//        printf("\n");
//
//        for (int l = 0; l < graph->n / 3; ++l) {
//            for (int k = 0; k < graph->n / 3; ++k) {
//                printf("%.2f ", graph->edge[l][k]);
//            }
//            printf("\n");
//        }
    }
}

bool visited[MAXSIZE];

void dfs(MGraph graph, int i) {
    printf("%d->", graph.vertex[i - 1]);
    visited[i] = true;
    for (int j = 1; j <= graph.n; ++j) {
        if (!visited[j] && graph.edge[i][j] != FINITY) {
//            printf("!visited[%d] && graph.edge[%d][%d] != FINITY  distance:%f   \n",j,i,j,graph.edge[i][j]);
            dfs(graph, j);
        }
    }
}

/**
 * 标记位从0开始，实际节点编号从1开始
 * @param graph
 */
void dfsTraverse(MGraph graph) {
    for (int i = 1; i <= graph.n; ++i) {
        visited[i] = false;
    }
    for (int i = 1; i <= graph.n; ++i) { //用于有多个图
        if (!visited[i]) dfs(graph, i);
    }
}

//正确序列
//1->2->6->7->8->12->13->5->4->14->15->16->17->18->38->36->33->32->27->25->22->21->19->11->10->9->3->20->23->24->43->44->4
//5->46->47->48->49->39->37->35->34->40->41->42->26->28->29->30->31->