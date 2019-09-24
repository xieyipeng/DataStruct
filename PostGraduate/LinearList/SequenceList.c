//
// Created by xieyipeng on 2019/9/23.
//

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

//TODO: 函数声明
void InitList(SqList_Static *sqList);

void DestroyList(SqList_Static *sqList);

void LocateElem(SqList_Static sqList, ElementType e);

void GetElem(SqList_Static sqList, int i);

/**
 * 前插法
 * @param sqList
 * @param i
 * @param e
 */
bool ListInsert(SqList_Static *sqList, int i, ElementType e);

/**
 * 删除
 * @param sqList
 * @param i
 * @param e 返回被删除元素的引用
 */
void ListDelete(SqList_Static *sqList, int i, ElementType *e);

void PrintList(SqList_Static sqList);

void Empty(SqList_Static sqList);

void Length(SqList_Static sqList);


int main() {
    SqList_Static sqList;
    InitList(&sqList);
    for (int i = 0; i < sqList.size; ++i) {
        printf("%d ",sqList.data[i]);
    }
}

//TODO: 函数实现

/**
 * 构造函数，使得线性表大小等于0
 * @param sqList 线性表对象
 */
void InitList(SqList_Static *sqList) {

    sqList->size=0;

    FILE *file = fopen("E:\\DataStructure\\PostGraduate\\LinearList\\text", "r");
    if (file != NULL) {
        char ch[1024];
        int i = 0;
        while (!feof(file)) {
            fgets(ch, 1024, file);
            printf("%s\n",ch);
            ListInsert(sqList, i, (ElementType) ch);
            i++;
        }
    }
    printf("====\n");

}

/**
 * 销毁线性表
 * @param sqList 线性表对象
 */
void DestroyList(SqList_Static *sqList) {
    free(sqList);
}

void LocateElem(SqList_Static sqList, ElementType e) {

}



/**
 * 前插
 * @param sqList
 * @param i
 * @param e
 */
bool ListInsert(SqList_Static *sqList, int i, ElementType e) {
    if (i < 0 || i >= sqList->size + 1) return false;
    if (sqList->size == SequenceMaxsize) return false;
    for (int j = sqList->size; j >= i; j--) {
        sqList->data[j] = sqList->data[j - 1];
    }
    sqList->data[i] = e;
    sqList->size++;
    return true;
}
