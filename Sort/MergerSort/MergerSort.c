#include <stdio.h>
#include <windows.h>

int help[] = {};

void mergerSort(int *array, int left, int right);

void merger(int *array, int left, int center, int right);

void mergerSort(int *array, int left, int right) {
    if (right == left) {
        return;
    }
    int center = (right + left) >> 1;
    mergerSort(array, left, center);
    mergerSort(array, center + 1, right);
    merger(array, left, center, right);
}

void merger(int *array, int left, int center, int right) {
    int i = left;
    int a = left;
    int b = center + 1;
    while (a <= center && b <= right) {
        if (array[a] <= array[b]) {
            help[i++] = array[a++];
        } else {
            help[i++] = array[b++];
        }
        // help[i++] = array[a] <= array[b] ? array[a++] : array[b++];
    }
    // 左侧指针、右侧指针, 必有一个越界、另一个不越界,将不越界的数组的剩余内容直接填充到help数组中
    while (a <= center) {
        help[i++] = array[a++];
    }
    while (b <= right) {
        help[i++] = array[b++];
    }
    for (i = left; i <= right; i++) {
        array[i] = help[i];
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
    int array[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    int size = sizeof(array) / sizeof(array[0]);
    printf("归并排序的原数组\n");
    printfArray(array, size);
    mergerSort(array, 0, size - 1);
    printfArray(array, size);
    return 0;
}