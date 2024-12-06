#include <stdio.h>
#include <windows.h>

void printfArray(int *array, int array_size);

void shellSort_Swap(int *array, int size);

void shellSort_Shift(int *array, int size);

void shellSort_Swap(int *array, int size) {
    int count = 0;
    for (int gap = size >> 1; gap > 0; gap >>= 1) {
        for (int i = gap; i < size; i++) {
            for (int j = i - gap; j >= 0; j -= gap) {
                if (array[j] > array[j + gap]) {
                    int temp = array[j + gap];
                    array[j + gap] = array[j];
                    array[j] = temp;
                }
            }
            printf("第%d趟Shell排序的序列是", ++count);
            printfArray(array, size);
        }

    }
}

void shellSort_Shift(int *array, int size) {
    int count = 0;
    for (int gap = size >> 1; gap > 0; gap >>= 1) {
        for (int i = gap; i < size; i++) {
            int j = i;
            int temp = array[j];
            while (j - gap >= 0 && temp < array[j - gap]) {
                // 移动
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }
        printf("第%d趟交换式Shell的排序序列是", ++count);
        printfArray(array, size);
    }
}

void printfArray(int *array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    SetConsoleOutputCP(65001);
    int array_swap[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    int size = sizeof(array_swap) / sizeof(array_swap[0]);
    printf("交换式Shell排序");
    printfArray(array_swap, size);
    shellSort_Swap(array_swap, size);
    int array_shift[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    printf("移动式Shell排序");
    printfArray(array_shift, size);
    shellSort_Shift(array_shift, size);
    printfArray(array_shift, size);
    return 0;
}