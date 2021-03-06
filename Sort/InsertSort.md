* 直接插入排序
```java
#include<stdio.h>
#include<Windows.h>
#define maxsize 100
typedef int keytype;
typedef struct {
	keytype key;
	int other;
}recordtype;
typedef struct {
	recordtype r[maxsize];
	int length;
}table;
void insertsort(table *tab) {//  **直接插入**
	int i, j;
	for (j = 2; j <= tab->length; j++) {
		j = j - 1;
		tab->r[0] = tab->r[j];
		while (tab->r[0].key < tab->r[j].key) {
			tab->r[j + 1] = tab->r[j];//记录后移
			j--;
		}
		tab->r[j+1]= tab->r[0];
	}
}
```
* 二分法插入排序
```java
#include<stdio.h>
#include<Windows.h>
#define maxsize 100
typedef int keytype;
typedef struct {
	keytype key;
	int other;
}recordtype;
typedef struct {
	recordtype r[maxsize];
	int length;
}table;
void binarysort(table *tab) {//  **二分法插入排序
	int i, j, left, right, mid;
	for (i = 2; i <= tab->length; i++) {
		tab->r[0] = tab->r[i];
		left = 1;
		right = i - 1;
		while (left <= right) {
			mid = (right + left) / 2;
			if (tab->r[i].key < tab->r[mid].key) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		for (j = i - 1; j >= left; j--) {
			tab->r[j + 1] = tab->r[j];
		}
		tab->r[left] = tab->r[0];
	}
}
```
* 表插入排序
```java
#include<stdio.h>
#include<Windows.h>o
#define maxsize 100
typedef int keytype;
typedef struct {
	keytype key;
	int link;
	int other;
}recordtype;
typedef struct {
	recordtype r[maxsize];
	int length;
}table;
void tableinsertsort(table *tab) {
	int i, p, q;
	tab->r[0].link = 1;
	tab->r[1].link = 0;
	for (i = 2; i <= tab->length; i++) {
		q = 0;
		p = tab->r[1].link;
		while (p != 0 && tab->r[i].key >= tab->r[p].key) {
			q = p;
			p = tab->r[p].link;
		}
		tab->r[i].link = p;
		tab->r[q].link = i;
	}
}
```
* 希尔排序
```java
#include<stdio.h>
#include<Windows.h>
#define maxsize 100
typedef int keytype;
typedef struct {
	keytype key;
	int link;
	int other;
}recordtype;
typedef struct {
	recordtype r[maxsize];
	int length;
}table;
void shellinsertsort(table *tab) {
	int i, j, d;
	d = tab->length / 2;
	while (d >= 1) {
		for (i = d + 1; i <= tab->length; i++) {
			tab->r[0] = tab->r[i];
			j = i - d;
			while (j > 0 && tab->r[0].key < tab->r[j].key) {
				tab->r[j + d] = tab->r[j];
				j = j - d;
			}
			tab->r[j + d] = tab->r[0];
		}
		d = d / 2;
	}
}
```
