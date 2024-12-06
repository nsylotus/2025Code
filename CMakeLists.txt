cmake_minimum_required(VERSION 3.23)
project(DataStruct C)

set(CMAKE_C_STANDARD 99)

add_executable(DataStruct main.c)

# 链表
add_executable(Array_Realize Linear_List/Array/main.c
        Linear_List/Array/Array.c
        Linear_List/Array/Array.h)

add_executable(SingleLinkedList_Realize Linear_List/SingleLinkedList/main.c
        Linear_List/SingleLinkedList/SingleLinkedList.c
        Linear_List/SingleLinkedList/SingleLinkedList.h)

add_executable(DoubleLinkedList_Realize Linear_List/DoubleLinkedList/main.c
        Linear_List/DoubleLinkedList/DoubleLinkedList.c
        Linear_List/DoubleLinkedList/DoubleLinkedList.h)

add_executable(CircularDoubleLinkedList Linear_List/CircularDoubleLinkedList/main.c
        Linear_List/CircularDoubleLinkedList/CircularDoubleLinkedList.h
        Linear_List/CircularDoubleLinkedList/CircularDoubleLinkedList.c)

# 栈
add_executable(ArrayStack Stack/ArrayStack/main.c
        Stack/ArrayStack/ArrayStack.c
        Stack/ArrayStack/ArrayStack.h)

# 队列
add_executable(DoubleQueue Queue/DoubleQueue/main.c
        Queue/DoubleQueue/DoubleQueue.h
        Queue/DoubleQueue/DoubleQueue.c)

# 数组
add_executable(SparseArray Array/SparseArray/SparseArray.c)

# 树
add_executable(TreeTraverse Tree/TreeTraverse/main.c)

# 排序
add_executable(SelectSort Sort/SelectSort/SelectSort.c)
add_executable(BubbleSort Sort/BubbleSort/BubbleSort.c)
add_executable(InsertSort Sort/InsertSort/InsertSort.c)
add_executable(CountingSort Sort/CountingSort/CountingSort.c)
add_executable(ShellSort Sort/ShellSort/ShellSort.c)
add_executable(QuickSort Sort/QuickSort/QuickSort.c)
add_executable(HeapSort Sort/HeapSort/HeapSort.c)
add_executable(MergerSort Sort/MergerSort/MergerSort.c)
add_executable(BucketSort Sort/BucketSort/BucketSort.c)
add_executable(RadixSort Sort/RadixSort/RadixSort.c)

# 测试
add_executable(Test Test/main.c)

# 华北水利水电大学研究生考试
add_executable(2005_3 University/2005/FourTopic/main.c)