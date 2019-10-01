//
// Created by xieyipeng on 2019/9/28.
//

#include "LinkList.h"

/**
 * 带头结点-头插法建立单链表
 * @param linkList
 * @return
 */
LinkList ListHeadInsert(LinkList linkList) {
    FILE *file = fopen("E:\\DataStructure\\PostGraduate\\LinearList\\text", "r");
    linkList = (LinkList) malloc(sizeof(LinkList));
    linkList->next = NULL;
    LinkList temp;
    if (file == NULL) {
        printf("file open error!");
    } else {
        while (!feof(file)) {
            char ch[1024];
            fgets(ch, 1024, file);
            temp = (LinkList) malloc(sizeof(LinkList));
            temp->data = atoi(ch);
            printf("%d-", temp->data);
            temp->next = linkList->next;
            linkList->next = temp;
        }
    }
    return linkList;
}

/**
 * 带头结点-尾插法建立单链表
 * @param linkList
 * @return
 */
LinkList ListTailInsert(LinkList linkList) {
    FILE *file = fopen("E:\\DataStructure\\PostGraduate\\LinearList\\text", "r");
    linkList = (LinkList) malloc(sizeof(LinkList));
    linkList->next = NULL;
    LinkList temp, r = linkList;
    if (file == NULL) {
        printf("file open error!");
    } else {
        char ch[1024];
        while (!feof(file)) {
            fgets(ch, 1024, file);
            temp = (LinkList) malloc(sizeof(LinkList));
            temp->data = atoi(ch);
            r->next = temp;
            r = temp;
        }
        r->next = NULL;
    }
    return linkList;
}

/**
 * 输出链表
 * @param linkList
 */
void PrintLinkList(LinkList linkList) {
    LinkList p = linkList;
    while (p->next != NULL) {
        p = p->next;
        printf("%d ", p->data);
    }
}

/**
 * 按序号查找
 * 返回带有头节点的链表序列
 * @param linkList
 * @return
 */
LinkList GetElemFromI(LinkList linkList, int i) {
    LinkList p = linkList;
    if (i == 0) return linkList;
    if (i < 1) return NULL;
    while (p && i > 0) {
        p = p->next;
        i--;
    }
    LinkList res;
    res = (LinkList) malloc(sizeof(LinkList));
    res->next = p;
    return res;
}

/**
 * 按值查找
 * 返回带有头节点的链表序列
 * @param linkList
 * @return
 */
LinkList GetElemFromV(LinkList linkList, ElemType e) {
    LinkList p = linkList;
    while (p != NULL && p->data != e) {
        p=p->next;
    }
    LinkList res;
    res = (LinkList) malloc(sizeof(LinkList));
    res->next = p;
    return res;
}

/**
 * 插入操作
 * @param linkList
 * @param i 插入位置
 * @return
 */
LinkList InsertI(LinkList linkList, int i){

}

