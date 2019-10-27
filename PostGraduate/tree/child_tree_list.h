//
// Created by xieyipeng on 2019/10/21.
// 孩子表示法(链表方式)
//

#ifndef POSTGRADUATE_CHILD_TREE_H
#define POSTGRADUATE_CHILD_TREE_H

#endif //POSTGRADUATE_CHILD_TREE_H

#define MAXSIZE 50

typedef char datatype;
typedef struct child_node {
    int child;
    struct child_node *next;
} child_node, *child_point;
typedef struct {
    datatype data;
    child_point first_child;
} temp;
typedef struct {
    temp treeList[MAXSIZE];
    int length,root;
}child_tree;
