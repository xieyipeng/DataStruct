//#include "LinearList/SequenceList.h"
//#include "LinearList/LinkList.h"
#include "LinearList/Stack.h"
//#include "LinearList/Queue.h"

/**
 * 匹配
 * @param a 左括号
 * @param b 右括号
 * @return
 */
bool match(char a, char b) {
    if (a + 1 == b || a + 2 == b) return true;
    else return false;
}

/**
 * 括号匹配
 * @return
 */
bool BracketMatch(SqStack stack, const char str[]) {
    ElemType e;
    for (int i = 0; i < strlen(str); ++i) {
        switch (str[i]) {
            case '{':
            case '[':
            case '(':
                Push(&stack, str[i]);
                break;
            case '}':
            case ']':
            case ')':
                GetTop(stack, &e);
                if (match(e, str[i])) Pop(&stack, &e);
                else return false;
                break;
            default:
                break;
        }
    }
    if (StackEmpty(stack)) return true;
    else return false;
}

/**
 * 读取char数组中的值
 * @param str
 * @param i 从第i个位置开始
 * @return double类型
 */
double ReadNumber(char str[], int *i) {
    double res = 0.0;
    int k = 0;//标记小数位数
    //处理整数部分
    while (str[*i] <= '9' && str[*i] >= '0') {
        res = res * 10 + (str[*i] - '0');
        (*i)++;
    }
    //处理小数部分
    if (str[*i] == '.') {
        (*i)++;
        while (str[*i] <= '9' && str[*i] >= '0') {
            res = res * 10 + (str[*i] - '0');
            (*i)++;
            k++;
        }
    }
    while (k != 0) {
        res = res / 10.0;
        k--;
    }
    return res;
}

/**
 * 后缀表达式求值
 * @param str
 * @return 算下的结果
 */
double SuffixValue(char str[]) {
    SqStack stack;
    InitStack(&stack);
    int i = 0;
    ElemType x1, x2;
    while (str[i] != '#') {
        if (str[i] <= '9' && str[i] >= '0') {
            Push(&stack, ReadNumber(str, &i));
        } else if (str[i] == ' ') {
            i++;
        } else if (str[i] == '+') {
            Pop(&stack, &x2);
            Pop(&stack, &x1);
            Push(&stack, x1 + x2);
            i++;
        } else if (str[i] == '-') {
            Pop(&stack, &x2);
            Pop(&stack, &x1);
            Push(&stack, x1 - x2);
            i++;
        } else if (str[i] == '*') {
            Pop(&stack, &x2);
            Pop(&stack, &x1);
            Push(&stack, x1 * x2);
            i++;
        } else if (str[i] == '/') {
            Pop(&stack, &x2);
            Pop(&stack, &x1);
            Push(&stack, x1 / x2);
            i++;
        }
    }
    GetTop(stack, &x1);
    return x1;
}

/**
 * 判断是否为操作符号
 * @param op
 * @return
 */
bool is_operation(char op) {
    switch (op) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

/**
 * 返回操作符的优先级
 * @param op
 * @return
 */
int Priority(char op) {
    switch (op) {
        case '#':
            return -1;
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

/**
 * 转变体，输出即为后缀表达式
 * @param infix 中缀
 * @param suffix 后缀
 */
void Suffix(char infix[], char suffix[]) {
    SqStack stack;
    InitStack(&stack);
    ElemType e;
    int i = 0;
    while (infix[i] != '#') {
        if ((infix[i] <= '9' && infix[i] >= '0') || infix[i] == '.') {
            printf("%d ", infix[i] - '0');
        } else if (infix[i] == '(') {
            Push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            GetTop(stack, &e);
            while (e != '(') {

                printf("%c ", e);
                Pop(&stack, &e);
                GetTop(stack, &e);
            }
            Pop(&stack, &e);
        } else if (is_operation(infix[i])) {
            GetTop(stack, &e);
            if (StackEmpty(stack)) {
                Push(&stack, infix[i]);
            } else if (e == '(') {
                Push(&stack, infix[i]);
            } else if (Priority(e) < Priority(infix[i])) {
                Push(&stack, infix[i]);
            } else {
                GetTop(stack, &e);
                while (Priority(e) >= Priority(infix[i]) || e == '(') {

                    printf("%c ", e);
                    Pop(&stack, &e);
                    GetTop(stack, &e);
                }
                Push(&stack, infix[i]);
            }
        }
        i++;
    }
    while (!StackEmpty(stack)) {
        GetTop(stack, &e);
        printf("%c ", e);
        Pop(&stack, &e);
    }
}

int main() {
    char infix[] = "4 * ( 2 + 1 ) #";
    char suffix[] = "4 * ( 2 + 1 ) #";
    Suffix(infix, suffix);
}


