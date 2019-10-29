//
// Created by xieyipeng on 2019/10/29.
//

#ifndef POSTGRADUATE_KMP_H
#define POSTGRADUATE_KMP_H

#endif //POSTGRADUATE_KMP_H\


#include "stdio.h"
#include "string.h"


#define MAXSIZE 100
typedef struct {
    char str[MAXSIZE];
    int length;
}seqString;

void getNext(seqString p, int next[]);

int kmp(seqString t,seqString p, int next[]);

