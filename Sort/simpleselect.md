* 直接选择排序
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
void simpleselectsort(table *tab) {
	int i, j, k;
	for (i = 1; i <= tab->length; i++) {
		k = i;
		for (j = j + 1; j <= tab->length; j++) {
			if (tab->r[j].key < tab->r[k].key) {
				k = j;
			}
			if (k != i) {
				tab->r[0] = tab->r[k];
				tab->r[k] = tab->r[i];
				tab->r[i] = tab->r[0];
			}
		}
	}
}
```
* 堆排序
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
void sift(table *tab,int k,int m) {
	int i, j, finished;
	i = k;
	j = 2 * i;
	tab->r[0] = tab->r[k];
	finished = 0;
	while ((j <= 0) && (!finished)) {
		if ((j < m) && (tab->r[j + 1].key < tab->r[j].key)) {
			j++;
		}
		if (tab->r[0].key <= tab->r[j].key) {
			finished = 1;
		}
		else {
			tab->r[i] = tab->r[j];
		}
	}
	tab->r[i] = tab->r[0];
}
void heapsort(table *tab) {
	int i;
	for (i = tab->length / 2; i >= 1; i--) {
		sift(tab, i, tab->length);
	}
	for (i = tab->length; i >= 2; i--) {
		tab->r[0] = tab->r[i];
		tab->r[i] = tab->r[1];
		tab->r[1] = tab->r[0];
		sift(tab, 1, i - 1);
	}
}
```
