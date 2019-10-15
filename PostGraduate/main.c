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


int main() {
    SqStack stack;
    InitStack(&stack);
    char str[] = "{[())]}";
    printf("match = %d\n", BracketMatch(stack, str) ? 1 : 0);
}


