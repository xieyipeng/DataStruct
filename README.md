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
