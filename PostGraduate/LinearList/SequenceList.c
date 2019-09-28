//
// Created by xieyipeng on 2019/9/23.
//

#include "SequenceList.h"

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

/**
 * 构造函数，使得线性表大小等于0
 * @param sqList 线性表对象
 */
void InitList(SqList_Static *sqList) {
    sqList->size = 0;
    FILE *file = fopen("E:\\DataStructure\\PostGraduate\\LinearList\\text", "r");
    if (file == NULL) {
        printf("file open error!");
        return;
    } else {
        char ch[1024];
        int i = 0;
        while (!feof(file)) {
            fgets(ch, 1024, file);
            //ch[strlen(ch) - 1] = '\0';
            ListInsert(sqList, i, atoi(ch));
            i++;
        }
        fclose(file);
    }
}

/**
 * 销毁线性表
 * @param sqList 线性表对象
 */
void DestroyList(SqList_Static *sqList) {
//    free(sqList);
}

/**
 * 输出
 * @param sqList
 */
void PrintList(SqList_Static sqList) {
    for (int i = 0; i < sqList.size; i++) {
        printf("%d ", sqList.data[i]);
    }
}

/**
 * 返回元素e所在位置，返回值从1开始，到 <sqList.size> ，sqList中不存在元素e，则返回0
 * @param sqList list
 * @param e 元素e
 * @return 所在位置
 */
int LocateElem(SqList_Static sqList, ElementType e) {
    for (int i = 0; i < sqList.size; i++) {
        if (sqList.data[i] == e) return i + 1;
    }
    return 0;
}

/**
 * 删除，下标从1开始到 <sqList.size>
 * @param sqList
 * @param i
 * @param e 返回被删除元素的引用
 */
bool ListDelete(SqList_Static *sqList, int i, ElementType *e) {
    if (i < 1 || i > sqList->size) return false;
    *e = sqList->data[i - 1];
    for (int j = i; j < sqList->size; j++) {
        sqList->data[j - 1] = sqList->data[j];
    }
    sqList->size--;
    return true;
}

/**
 * 取值
 * @param sqList
 * @param i
 * @return
 */
ElementType GetElem(SqList_Static sqList, int i) {
    return sqList.data[i];
}

/**
 * 判空
 * @param sqList
 * @return
 */
bool Empty(SqList_Static sqList) {
    return (sqList.size == 0) ? true : false;
}

/**
 * 长度
 * @param sqList
 * @return
 */
int Length(SqList_Static sqList) {
    return sqList.size;
}

/**
 * 顺序表的逆置
 * @param sqList
 */
void Reverse(SqList_Static *sqList) {
    int i = 0;
    int j = sqList->size - 1;
    while (i < j) {
        int temp = sqList->data[i];
        sqList->data[i] = sqList->data[j];
        sqList->data[j] = temp;
        i++;
        j--;
    }
}

//int main() {
//    SqList_Static sqList;
//    InitList(&sqList);
//    PrintList(sqList);
//    DestroyList(&sqList);
//}
