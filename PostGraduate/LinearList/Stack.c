//
// Created by xieyipeng on 2019/10/3.
//

#include "Stack.h"

/**
 * 初始化
 * @param sqStack
 */
void InitStack(SqStack *sqStack) {
    sqStack->top = -1;
}

/**
 * 判空
 * @param sqStack
 * @return
 */
bool StackEmpty(SqStack sqStack) {
    if (sqStack.top == -1) return true;
    else return false;
}

/**
 * 栈满：sqStack->top == MAXSIZE-1
 * @param sqStack
 * @param e
 * @return
 */
bool Push(SqStack *sqStack, ElemType e) {
    if (sqStack->top == MAXSIZE - 1) return false;
    sqStack->data[++sqStack->top] = e;
    return true;
}

/**
 *
 * @param sqStack
 * @param e 保存并返回，以便 free
 * @return
 */
bool Pop(SqStack *sqStack, ElemType *e) {
    if (sqStack->top == -1) return false;
    *e = sqStack->data[sqStack->top];
    sqStack->top--;
}

/**
 * 读取栈顶元素
 * @param sqStack
 * @param e 的返回值
 * @return
 */
bool GetTop(SqStack sqStack, ElemType *e) {
    if (StackEmpty(sqStack)) return false;
    *e = sqStack.data[sqStack.top];
    return true;
}

void ClearStack(SqStack *sqStack) {
    sqStack->top = -1;
}