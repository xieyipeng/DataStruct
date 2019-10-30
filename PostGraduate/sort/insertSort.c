//
// Created by xieyipeng on 2019/10/30.
//

#include "insertSort.h"

/**
 * 直接插入排序
 * @param a
 * @param n
 */
void insertSort(ElemType a[], int n) {
    int sentry = 0;
    for (int i = 1; i < n; ++i) {
        int j = i - 1;
        sentry = a[i];
        while (sentry < a[j]) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = sentry;
    }
}

/**
 * 折半查找
 * @param a
 * @param n
 */
void binary(ElemType a[], int n) {
    int sentry = 0;
    int low = 0, high = 0;
    for (int i = 1; i < n; ++i) {
        sentry = a[i];
        low = 0;
        high = i;
        //查找
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sentry < a[mid]) high = mid - 1;
            else low = mid + 1;
        }
        //移动
        for (int j = i - 1; j >= high + 1; --j) {
            a[j + 1] = a[j];
        }
        a[low] = sentry;
    }
}

/**
 * 希尔排序
 * @param a
 * @param n
 */
void shellSort(ElemType a[], int n) {
    int d = n / 2;
    int sentry;
    while (d >= 1) {
        for (int i = d; i < n; ++i) {
            sentry = a[i];
            int j = i - d;
            while (j >= 0 && sentry < a[j]) {
                a[j + d] = a[j];
                j = j - d;
            }
            a[j + d] = sentry;
        }
        print_sort(a,n);
        d = d / 2;
    }
}

/**
 * 输出排序结果
 * @param a
 */
void print_sort(ElemType a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}