//
// Created by xieyipeng on 2019/10/25.
//

#include "bint_node.h"


/**
 * 以先序遍历序列创建二叉树
 * 输入示例：abd#e##fg###c##
 * @return
 */
bin_tree createBinTree() {
    bin_tree tree;
    char ch;
    if ((ch = getchar()) == '#') {
        tree = NULL;
    } else {
        tree = (bin_tree) malloc(sizeof(bin_tree));
        tree->data = ch;
        tree->left = createBinTree();
        tree->right = createBinTree();
    }
    return tree;
}

/**
 * 先序遍历
 * 递归
 * @param tree
 */
void preOrder(bin_tree tree) {
    if (tree) {
        printf("%c ", tree->data);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

/**
 * 先序遍历
 * 非递归
 * @param tree
 */
void preOrder1(bin_tree tree) {
    binStack stack;
    stack.top = -1;
    while (tree || stack.top != -1) {
        if (tree) {
            printf("%c-", tree->data);
            binPush(&stack, tree);
            tree = tree->left;
        } else {
            tree = binPop(&stack);
            tree = tree->right;
        }
    }
}

/**
 * 中序遍历
 * 递归
 * @param tree
 */
void inOrder(bin_tree tree) {
    if (tree) {
        inOrder(tree->left);
        printf("%c ", tree->data);
        inOrder(tree->right);
    }
}

/**
 * 中序遍历
 * 非递归
 * @param tree
 */
void inOrder1(bin_tree tree) {
    binStack stack;
    stack.top = -1;
    while (tree || stack.top != -1) {
        if (tree) {
            binPush(&stack, tree);
            tree = tree->left;
        } else {
            tree = binPop(&stack);
            printf("%c-", tree->data);
            tree = tree->right;
        }
    }
}

/**
 * 后序遍历
 * 递归
 * @param tree
 */
void postOrder(bin_tree tree) {
    if (tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        printf("%c ", tree->data);
    }
}

/**
 * 后序遍历
 * 非递归
 * @param tree
 */
void postOrder1(bin_tree tree) {
    binStack stack;
    stack.top = 0;
    while (tree || stack.top != -1) {
        if (tree) {
            stack.data[stack.top] = tree;
            stack.tag[stack.top] = 0;
            stack.top++;
            tree = tree->left;
        } else {
            if (stack.tag[stack.top - 1] == 1) {
                stack.top--;
                tree = stack.data[stack.top];
                printf("%c-", tree->data);
                tree = NULL;
            } else {
                tree = stack.data[stack.top - 1];
                stack.tag[stack.top - 1] = 1;
                tree = tree->right;
            }
        }
    }
}

/**
 * 层次遍历
 * @param tree
 */
void levelOrder(bin_tree tree) {
    binQueue queue;
    init_binQueue(&queue);
    EnBinQueue(&queue, tree);
    bin_tree temp;
    while (queue.front != queue.rear) {
        DeBinQueue(&queue, &temp);
        printf("%c-", temp->data);
        if (temp->left != NULL) {
            EnBinQueue(&queue, temp->left);
        }
        if (temp->right != NULL) {
            EnBinQueue(&queue, temp->right);
        }
    }
}

/**
 * 返回二叉树的节点数目
 * @param tree
 */
int numOfNode(bin_tree tree) {
    if (tree == NULL) return 0;
    else return numOfNode(tree->left) + numOfNode(tree->right) + 1;
}

/**
 * 判断两颗二叉树是否等价
 * @param tree1
 * @param tree2
 * @return
 */
int isEqual(bin_tree tree1, bin_tree tree2) {
    int t = 0;
    if (tree1 == NULL && tree2 == NULL) t = 1;
    else if (tree1 != NULL && tree2 != NULL)
        if (tree1->data == tree2->data)
            if (isEqual(tree1->left, tree2->left))
                t = isEqual(tree1->right, tree2->right);
    return (t);
}

/**
 * 返回树的深度
 * @param tree
 * @return
 */
int depth(bin_tree tree) {
    int h, lh, rh;
    if (tree == NULL) h = 0;
    else {
        lh = depth(tree->left);
        rh = depth(tree->right);
        if (lh >= rh) h = lh + 1;
        else h = rh + 1;
    }
    return h;
}


//  >>>>>>>>>>>>>>>>>>>>>>>> queue

void init_binQueue(binQueue *queue) {
    queue->front = queue->rear = 0;
}

void EnBinQueue(binQueue *queue, ElemType elemType) {
    queue->data[queue->rear] = elemType;
    queue->rear = (queue->rear + 1) % MAXSIZE;
}

void DeBinQueue(binQueue *queue, ElemType *elemType) {
    if (queue->rear == queue->front)return;
    *elemType = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAXSIZE;
}




//  >>>>>>>>>>>>>>>>>>>>>>>> stack

/**
 * 栈满：sqStack->top == MAXSIZE-1
 * @param sqStack
 * @param e
 * @return
 */
bool binPush(binStack *binStack, ElemType e) {
    if (binStack->top == MAXSIZE - 1) return false;
    binStack->data[++binStack->top] = e;
    return true;
}

/**
 *
 * @param sqStack
 * @param e 保存并返回，以便 free
 * @return
 */
ElemType binPop(binStack *binStack) {
    if (binStack->top == -1) return NULL;
    else {
        binStack->top--;
        return binStack->data[binStack->top + 1];
    }
    binStack->top--;
}




