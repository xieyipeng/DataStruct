# DataStructure
数据结构（c语言）

顺序表：顺序存储
```java
#define MAXSIZE 100
typedef int datatype;
typedef struct{
  datatype a[MAXSIZE];
  int size;
}sequence_list;
```
栈：
```java
#define MAXSIZE 100
typedef struct{
  datatype a[MAXSIZE];
  int top;
}sequence_stack
```
队列：
```java
#define MAXSIZE 100
typedef struct{
  datatype a[MAXSIZE];
  int front;
  int rear;
}sequence_queue
```
单链表：
```java
typedef int datatype
typedef struct link_node{
  datatype info;
  struct link_node *next;
}node
 ```
 双链表：
 ```java
 typedef int datatype
typedef struct dlink_node{
  datatype info;
  struct dlink_node *llink,*rlink;
 }dnode
 ```
链式队列：
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
