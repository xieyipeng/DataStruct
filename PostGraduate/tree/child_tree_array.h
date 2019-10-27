//
// Created by xieyipeng on 2019/10/25.
//

#ifndef POSTGRADUATE_CHILD_TREE_ARRAY_H
#define POSTGRADUATE_CHILD_TREE_ARRAY_H

#endif //POSTGRADUATE_CHILD_TREE_ARRAY_H

#define DEGREE 3
#define MAXSIZE 20
typedef char datatype;

typedef struct child_array {
    datatype data;
    int child[DEGREE];
} child_array_tree;
child_array_tree tree[MAXSIZE];
int root;
int length;
