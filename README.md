欢迎查询[markdown语法](http://blog.csdn.net/witnessai1/article/details/52551362)
# **DataStructure**

## 数据结构（c语言）

### **线性表：顺序存储**
* 顺序表：
```java
#define MAXSIZE 100
typedef int datatype;
typedef struct{
  datatype a[MAXSIZE];
  int size;
}sequence_list;
```
* 栈：
```java
#define MAXSIZE 100
typedef struct{
  datatype a[MAXSIZE];
  int top;
}sequence_stack
```
* 队列：
```java
#define MAXSIZE 100
typedef struct{
  datatype a[MAXSIZE];
  int front;
  int rear;
}sequence_queue
```

### **线性表：链式存储**
* 单链表：
```java
typedef int datatype
typedef struct link_node{
  datatype info;
  struct link_node *next;
}node
 ```
* 双链表：
 ```java
 typedef int datatype
typedef struct dlink_node{
  datatype info;
  struct dlink_node *llink,*rlink;
 }dnode
 ```
* 链式队列：
```java
typedef int datatype
typedef struct dlink_node{
  datatype info;
  struct dlink_node *next;
 }node
typedef struct{
  node *front,*rear;//定义队首队尾指针
}queue
```
### **树 Tree**
* 树的双亲表示法：
```java
#define MAXSIZE 100
typedef char datatype;
typedef struct node {
	datatype data;
	int parent;//结下双亲的下标
}node;
typedef struct tree {
	node treeList[MAXSIZE];//存放节点的数组
	int length, root;//节点的个数及根节点的位置
};
```
* 树的孩子表示法：(指针方式)
```java
#define m 3
typedef char datatype;
typedef struct node {
	datatype data;
	struct node *child[m];
}node,*tree;
tree root;
```
* 树的孩子表示法：(数组方式)
```java
#define m 3
#define MAXSIZE 20
typedef char datatype;
typedef struct node {
	datatype data;
	int child[m];
}treenode;
treenode tree[MAXSIZE];
int root;
int length;
```
* 树的孩子表示法：(链表方式)
```java
#define MAXSIZE 50
typedef char datatype;
typedef struct chnode {
	int child;
	struct chnode *next;
}chnode,*chpoint;
typedef struct {
	datatype data;
	chpoint firstchild;
}node;
typedef struct {
	node treelist[MAXSIZE];
	int length, root;
}tree;
```
* 树的孩子兄弟表示法：
```java
typedef char datatype;
typedef struct node {
	datatype data;
	struct node *firstchild, *rightsibling;
}node, *pnode;
pnode root;
```

### **二叉树**
* 顺序存储(不带双亲指示)：
```java
#define MAXSIZE 20
typedef char datatype;
typedef struct {
	datatype data;
	int lchild, rchild;//存放左右子女的下标
}node;
node tree[MAXSIZE];
int n;//树中实际所含节点的个数
int root;//存放根节点的下标
```
* 顺序存储(带双亲指示)：
```java
#include<stdio.h>
#include<Windows.h>
#define MAXSIZE 20
typedef char datatype;
typedef struct {
	datatype data;
	int lchild, rchild;//存放左右子女的下标
	int parent;
}node;
node tree[MAXSIZE];
int n;//树中实际所含节点的个数
int root;//存放根节点的下标
```
* 中序穿线二叉树：
```java
#include<stdio.h>
#include<Windows.h>
typedef char datatype;
typedef struct node{
	datatype data;
	int ltag, rtag;//存放左右下标
	struct node *lchild, *rchild;
}binthrnode;
typedef binthrnode *binthrnode;
```
* 二叉排序树
```java
#include<stdio.h>
#include<Windows.h>
typedef int datatype;
typedef struct node {
	datatype key;
	struct node *lchild, *rchild;
}bsnode;
typedef bsnode *bstree;
```
### **图**
* 数组表示(邻接矩阵)
```java
#include<stdio.h>
#include<Windows.h>
#define FINITY 5000
#define M 20
typedef char vertextype;
typedef int edgetype;
typedef struct {
	vertextype vexs[M];
	edgetype edges[M][M];
	int n, e;
}Mgraph;
```
