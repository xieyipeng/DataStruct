//
// Created by xieyipeng on 2019/10/29.
//

#include "kmp.h"

/**
 * next数组
 * @param p
 * @param next
 */
void getNext(seqString p, int next[]) {
    next[0] = -1;
    int i = 0;
    int j = -1;
    while (i < p.length) {
        if (j == -1 || p.str[i] == p.str[j]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

/**
 * 模式匹配kmp算法
 */
int kmp(seqString t, seqString p, int next[]) {
    int i = 0;
    int j = 0;
    while (i < t.length && j < p.length) {
        if (j==-1||t.str[i]==p.str[j]){
            i++;
            j++;
        } else{
            j=next[j];
        }
    }
    if (j==p.length) return (i-p.length);
    else return (-1);
}

//int main() {
//    seqString t, p;
//    t.length = 0;
//    p.length = 0;
//    char a[] = "abbaabbaabaa";
//    char b[] = "abbaaba";
//    for (int i = 0; i < strlen(a); ++i) {
//        t.str[i] = a[i];
//        t.length++;
//    }
//    for (int i = 0; i < strlen(b); ++i) {
//        p.str[i] = b[i];
//        p.length++;
//    }
//    t.str[t.length] = '\0';
//    p.str[p.length] = '\0';
//    int next[MAXSIZE];
//    getNext(p, next);
//    printf("%d", kmp(t, p, next));
//}