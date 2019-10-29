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
    FILE *edge = fopen("E:\\DataStructure\\PostGraduate\\graph\\dijks_edge.txt", "r");
    FILE *vertex = fopen("E:\\DataStructure\\PostGraduate\\graph\\djiks_vertex.txt", "r");
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
            if (c == 0) {
                graph->edge[j][i] = atof(ch);
            }
            graph->e++;
        }
//        for (int k = 0; k < graph->n; ++k) {
//            printf("%d-", graph->vertex[k]);
//        }
//        printf("\n");
//
//        for (int l = 1; l <= graph->n; ++l) {
//            for (int k = 1; k <= graph->n; ++k) {
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

void bfs(MGraph graph, int i) {
    if (!visited[i]) {
        printf("%d->", graph.vertex[i - 1]);
        visited[i] = true;
    }
    int temp[MAXSIZE];
    int rear = 0, front = 0;
    for (int j = 1; j <= graph.n; ++j) {
        if (!visited[j] && graph.edge[i][j] != FINITY) {
            //访问并入队
            printf("%d->", graph.vertex[j - 1]);
            visited[j] = true;
            temp[rear] = j;
            rear++;
        }
    }
    while (rear != front) {
        bfs(graph, temp[front]);
        front++;
    }
}

/**
 * bfs广度优先遍历
 * @param graph
 * @return 连通分量的个数
 */
int bfsTraverse(MGraph graph) {
    int count = 0;
    for (int i = 1; i <= graph.n; ++i) {
        visited[i] = false;
    }
    for (int j = 1; j <= graph.n; ++j) {
        dfs(graph, j);
        count++;
    }
    return count;
}

/**
 * 最小生成树prim算法
 * @param graph
 */
void prim(MGraph graph) {
    edge tree[graph.n - 1];
    edge temp;
    EdgeType min, d;
    int s = 0, v;
    for (int i = 1; i <= graph.n; ++i) {
        tree[i - 1].begin = 1;
        tree[i - 1].end = i + 1;
        tree[i - 1].length = graph.edge[1][i + 1];
    }
    for (int k = 0; k <= graph.n - 3; ++k) {
        min = tree[k].length;
        s = k;
        for (int j = k + 1; j <= graph.n - 2; ++j) {
            if (tree[j].length < min && tree[j].length != FINITY) {
                min = tree[j].length;
                s = j;
            }
        }
        v = tree[s].end;
        temp = tree[s];
        tree[s] = tree[k];
        tree[k] = temp;
        for (int j = k + 1; j <= graph.n - 2; ++j) {
            d = graph.edge[v][tree[j].end];
            if (d < tree[j].length) {
                tree[j].length = d;
                tree[j].begin = v;
            }
        }
    }
    printf("the minimum cost spanning tree is :\n");
    for (int j = 0; j <= graph.n - 2; ++j) {
        printf("%d---%d %.2f \n", tree[j].begin, tree[j].end, tree[j].length);
    }
    printf("the root is %d\n", graph.vertex[0]);
}

/**
 * 对边排序
 * @param edges
 * @param left
 * @param right
 */
void sort(edge *edges, int left, int right) {
    int i = 0, j = 0;
    edge x;
    if (left < right) {
        i = left;
        j = right;
        x = edges[i];
        while (i < j) {
            while (i < j && x.length < edges[j].length) j--;
            if (i < j) edges[i++] = edges[j];
            while (i < j && x.length > edges[i].length) i++;
            if (i < j) edges[j--] = edges[i];
        }
        edges[i] = x;
        sort(edges, left, i - 1);
        sort(edges, i + 1, right);
    }
}

void GetEdge(MGraph graph, edge edges[]) {
    int count = 0;
    for (int i = 0; i <= graph.n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (graph.edge[i][j] != 0 && graph.edge[i][j] != FINITY) {
                edges[count].begin = i;
                edges[count].end = j;
                edges[count].length = graph.edge[i][j];
                count++;
            }
        }
    }
}

/**
 * kruskal算法
 * @param graph
 */
void kruskal(MGraph graph) {
    int k = 0;
    int cnvx[graph.n];
    edge edges[graph.e];
    edge tree[graph.n - 1];
    GetEdge(graph, edges);
    sort(edges, 0, graph.e - 1);
    for (int j = 0; j < graph.n; ++j) {//初始化连通分量
        cnvx[j] = j;
    }
    for (int i = 0; i < graph.n - 1; ++i) {
        while (cnvx[edges[k].begin - 1] == cnvx[edges[k].end - 1]) k++;
        tree[i] = edges[k];
        int temp = cnvx[edges[k].end - 1];
        for (int j = 0; j < graph.n; ++j) {
            if (cnvx[j] == temp) {
                cnvx[j] = cnvx[edges[k].begin - 1];
            }
        }
        k++;
    }
    printf("the minimum cost spanning tree is :\n");
    for (int l = 0; l < graph.n - 1; ++l) {
        printf("%d---%d %.2f \n", tree[l].begin, tree[l].end, tree[l].length);
    }
}


void print_pgd(MGraph graph, int path[], float dist[]) {
    for (int j = 0; j < graph.n; ++j) {
        path[j] = path[j] - 1;
    }
    int st[graph.n], pre, top = -1;
    for (int i = 0; i < graph.n; ++i) {
        printf("\nDistance: %.2f , path: ", dist[i]);
        st[++top] = i;
        pre = path[i];
        while (pre != -1) {
            st[++top] = pre;
            pre = path[pre];
        }
        while (top > 0) {
            printf("%2d", (st[top--] + 1));
        }
    }
}

/**
 * dijkstra算法求单源最短路径
 * @param graph
 * @param v0
 */
void dijkstra(MGraph graph, int v0) {
    float min = 0;
    int v = 0;
    float dist[graph.n];
    int path[graph.n];
    bool final[graph.n];
    for (int i = 0; i < graph.n; ++i) {
        final[i] = false;
        dist[i] = graph.edge[v0][i + 1];
        if (dist[i] < FINITY && dist[i] != 0) path[i] = v0;
        else path[i] = 0;
    }
    final[v0 - 1] = true;
    dist[v0 - 1] = 0;
    for (int i = 2; i <= graph.n; ++i) {
        //找到dist内最小距离
        min = FINITY;
        for (int k = 0; k < graph.n; ++k) {
            if (!final[k] && dist[k] < min) {
                v = k;
                min = dist[k];
            }
        }
        printf("%d---%.2f\n", v, min);
        if (min == FINITY) {
            return;
        } else {
            final[v] = true;
        }
        final[v] = true;
        //修改dist和path数组
        for (int k = 0; k < graph.n; ++k) {
            if (!final[k] && (min + graph.edge[v + 1][k + 1] < dist[k])) {
                dist[k] = min + graph.edge[v + 1][k + 1];
                path[k] = v + 1;
            }
        }
    }
    print_pgd(graph, path, dist);
}

/**
 * floyd算法
 * @param graph
 */
void floyd(MGraph graph) {
    int dist[graph.n][graph.n];
    int path[graph.n][graph.n];
    for (int i = 0; i < graph.n; ++i) {
        for (int j = 0; j < graph.n; ++j) {
            dist[i][j] = graph.edge[i][j];
            if (i != j && dist[i][j] < FINITY) {
                path[i][j] = i;
            } else {
                path[i][j] = -1;
            }
        }
    }
    for (int k = 0; k < graph.n; ++k) {
        for (int i = 0; i < graph.n; ++i) {
            for (int j = 0; j < graph.n; ++j) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][k] = k;
                }
            }
        }
    }
}
