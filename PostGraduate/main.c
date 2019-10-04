//#include "LinearList/SequenceList.h"
//#include "LinearList/LinkList.h"
#include "LinearList/Stack.h"

int main() {
    SqStack sqStack;
    InitStack(&sqStack);
    Push(&sqStack, 10);
    Push(&sqStack, 10);
    Push(&sqStack, 10);
    Push(&sqStack, 11);
    ElemType e;
    Pop(&sqStack, &e);
    printf("%d\n",e);

    GetTop(sqStack,&e);
    printf("%d\n",e);


    return 0;
}


