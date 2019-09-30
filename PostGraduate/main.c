//#include "LinearList/SequenceList.h"
#include "LinearList/LinkList.h"

int main() {
    LinkList linkList = NULL;
    linkList = ListTailInsert(linkList);
    while (linkList->next != NULL) {
        linkList=linkList->next;
        printf("%d ", linkList->data);
    }
    return 0;
}


