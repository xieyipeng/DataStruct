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
