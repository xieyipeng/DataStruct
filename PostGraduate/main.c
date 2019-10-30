//#include "LinearList/SequenceList.h"
//#include "LinearList/LinkList.h"
//#include "LinearList/Stack.h"
//#include "LinearList/Queue.h"
//#include "tree/bint_node.h"
//#include "graph/matrix.h"
//#include "str/kmp.h"
//#include "sort/insertSort.h"
#include "sort/changeSort.h"

int main() {
    ElemType a[] = {10, 4, 2, 6, 7, 3, 4, 6};
    select(a, (sizeof(a) / sizeof(a[0])));
    print_sort(a, (sizeof(a) / sizeof(a[0])));
}
