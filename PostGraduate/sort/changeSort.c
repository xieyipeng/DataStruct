//
// Created by xieyipeng on 2019/10/30.
//

#include "changeSort.h"


/**
 * 冒泡排序
 * @param a
 * @param n
 */
void bubbling(ElemType a[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

/**
 * 快速排序
 * @param a
 * @param low
 * @param high
 */
void quick(ElemType a[], int low, int high) {
    if (low < high) {
        int i = low;
        int j = high;
        int sentry = a[low];
        while (i != j) {
            while (sentry < a[j] && i < j) j--;
            if (i < j) {
                a[i] = a[j];
                i++;
            }
            while (sentry > a[i] && i < j) i++;
            if (i < j) {
                a[j] = a[i];
                j--;
            }
        }
        a[i] = sentry;
        quick(a, low, i - 1);
        quick(a, i + 1, high);
    }
}

/**
 * 选择排序
 * @param a
 * @param i
 */
void select(ElemType a[], int n) {
    for (int j = 0; j < n - 1; ++j) {
        int min = j;
        for (int i = j+1; i < n; ++i) {
            if (a[i]<a[min]) min=i;
        }
        if (min!=j){
            ElemType temp=a[j];
            a[j]=a[min];
            a[min]=temp;
        }
    }
}


///**
// * 输出排序结果
// * @param a
// */
//void print_sort(ElemType a[], int n) {
//    for (int i = 0; i < n; ++i) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//}