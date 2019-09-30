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
