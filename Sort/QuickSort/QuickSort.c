#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// 返回值
// 左边界
int first;
// 右边界
int last;

void printfArray(int *array, int array_size);

void swap(int *array, int num1, int num2);

void partition(int *array, int low, int high, int random);

// 荷兰国旗问题的优化版本
void quick_Sort(int *array, int l, int r);

void printfArray(int *array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *array, int num1, int num2) {
    int temp = array[num1];
    array[num1] = array[num2];
    array[num2] = temp;
}

void partition(int *array, int low, int high, int random) {
    int i = low;
    first = low;
    last = high;
    while (i <= last) {
        if (array[i] == random) {
            i++;
        } else if (array[i] < random) {
            swap(array, first++, i++);
        } else {
            swap(array, i, last--);
        }
    }
}

void quick_Sort(int *array, int l, int r) {
    if (l >= r) {
        return;
    }
    int random = array[l + rand() % (r - l + 1)];
    partition(array, l, r, random);
    // 为了防止底层的递归过程覆盖全局变量
    // 这里使用临时变量记录first、last
    int left = first;
    int right = last;
    quick_Sort(array, l, left - 1);
    quick_Sort(array, right + 1, r);
}

int main(int argc, char const *argv[]) {
    SetConsoleOutputCP(65001);
    srand((unsigned int) time(NULL));
    int array[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    int size = sizeof(array) / sizeof(array[0]);
    printf("荷兰国旗问题的快速排序前的数组");
    printfArray(array, size);
    quick_Sort(array, 0, size - 1);
    printf("荷兰国旗问题的快速排序后的数组");
    printfArray(array, size);
    return 0;
}