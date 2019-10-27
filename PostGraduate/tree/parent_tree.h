//
// Created by xieyipeng on 2019/10/21.
// 双亲表示法
//

#ifndef POSTGRADUATE_PARENT_TREE_H
#define POSTGRADUATE_PARENT_TREE_H

#endif //POSTGRADUATE_PARENT_TREE_H

#define MAXSIZE 100

typedef char datatype;
typedef struct node {
    datatype data;
    int parent;
} temp;

typedef struct parent_tree {
    temp treeList[MAXSIZE];
    int length, root; //root:根节点的下标
};