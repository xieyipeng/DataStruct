cmake_minimum_required(VERSION 3.14)
project(PostGraduate C)

set(CMAKE_C_STANDARD 99)

add_executable(PostGraduate main.c LinearList/SequenceList.c LinearList/SequenceList.h LinearList/LinkList.c LinearList/LinkList.h LinearList/DLinkList.c LinearList/DLinkList.h LinearList/Stack.c LinearList/Stack.h LinearList/Queue.c LinearList/Queue.h tree/parent_tree.h tree/child_tree_list.h tree/child_tree_array.h tree/bint_node.c tree/bint_node.h graph/matrix.c graph/matrix.h str/kmp.c str/kmp.h sort/insertSort.c sort/insertSort.h sort/changeSort.c sort/changeSort.h)