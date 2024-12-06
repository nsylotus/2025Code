#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define BUCKET_SIZE 10; // 作桶的个数

void printfArray(int *array, int array_size);

void initBuckets(int *buckets, int size);

void insertSort(int *array, int length);

void swap(int *array, int index1, int index2);

void printfArray(int *array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void initBuckets(int *buckets, int size) {
    for (int i = 0; i < size; i++) {
        buckets[i] = 0;
    }
}

void insertSort(int *array, int length) {
    for (int i = 1; i < length; i++) {
        for (int j = i - 1; j >= 0 && array[j] > array[j + 1]; j--) {
            swap(array, j, j + 1);
        }
    }
}

void swap(int *array, int index1, int index2) {
    int temp = array[index2];
    array[index2] = array[index1];
    array[index1] = temp;
}

int main(int argc, char const *argv[]) {
    SetConsoleOutputCP(65001);

    int array[] = {87, 99, 13, 76, 2, 3, 55, 4, 6, 0};
    int array_size = sizeof(array) / sizeof(array[0]);

    // 准备桶
    int buckets[array_size];
    initBuckets(buckets, sizeof(buckets) / sizeof(buckets[0]));

    printf("桶排序原来的数组\n");
    printfArray(array, array_size);



    printf("桶排序之后的数组");
    printfArray(array, array_size);
    return 0;
}