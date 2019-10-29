欢迎查询[markdown语法](http://blog.csdn.net/witnessai1/article/details/52551362)

考研数据结构博客地址https://blog.csdn.net/xieyipeng1998/article/details/101317748

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
### **字符串**
* 顺序存储
```java
#include<stdio.h>
#include<Windows.h>
#define maxsize 100
typedef char datatype;
typedef struct {
	char str[maxsize];
	int length;
}seqstring;
```
* 链式存储
```java
#include<stdio.h>
#include<Windows.h>
typedef char datatype;
typedef struct node{
	char data;
	struct node *next;
}linknode;
typedef linknode *linkstring;
```
### **数组**
```java
#include<stdio.h>
#include<Windows.h>
#define maxsize 3
typedef int datatype;
typedef struct {
	datatype *base;
	int index[maxsize];
	int c[maxsize];
}array;
```
### **矩阵**
* 顺序存储
```java
#include<stdio.h>
#include<Windows.h>
//稀疏矩阵
typedef struct {
	int data[100][100];
	int m, n;
}matrix;
typedef int spmatrix[100][3];//三元组
```
* **链式存储**
```java
#include<stdio.h>
#include<Windows.h>
//稀疏矩阵
typedef struct matrixnode{
	int row, col;
	struct matrixnode *right, *down;
	union {
		int val;
		struct matrixnode *next;
	}tag;
}matrixnode;
typedef matrixnode *spmatrix;
typedef spmatrix headspmatrix[100];
/*
union 维护足够的空间来置放多个数据成员中
的“一种”，而不是为每一个数据成员配置空
间，在union 中所有的数据成员共用一个空间
，同一时间只能储存其中一个数据成员，所有
的数据成员具有相同的起始地址。例子如下：
union StateMachine{
	char character;
	int number;
	char *str;
	double exp;
};
一个union 只配置一个足够大的空间以来容纳
最大长度的数据成员，以上例而言，最大长度
是double 型态，所以StateMachine 的空间大
小就是double 数据类型的大小。
在C++里，union 的成员默认属性页为public。
union 主要用来压缩空间。如果一些数据不可
能在同一时间同时被用到，则可以使用union。
*/
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
* 邻接表
```java
#include<stdio.h>
#include<Windows.h>
//邻接表
#define M 20
typedef char Datatype;
typedef struct node {//边表节点
	int adjvex;
	struct node *next;
}EdgeNode;
typedef struct vnode {//头节点类型
	Datatype vertex;
	EdgeNode *FistEdge;//邻接链表头指针
}VertexNode;
typedef struct {//邻接表的类型
	VertexNode adjlist[M];//存放头节点的顺序表
	int n, e;
};
```
