#include <stdio.h>

void printfInsertSort(int *array, int length);

void swap(int *array, int index1, int index2);

void insertSort(int *array, int length);

void printfInsertSort(int *array, int length) {
    printf("InsertSort:");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int *array, int index1, int index2) {
    int temp = array[index2];
    array[index2] = array[index1];
    array[index1] = temp;
}

void insertSort(int *array, int length) {
    if (array == NULL && length < 2) {
        return;
    }
    for (int i = 1; i < length; i++) {
        for (int j = i - 1; j >= 0 && array[j] > array[j + 1]; j--) {
            swap(array, j, j+1);
        }
    }
}

int main(int argc, char const *argv[]) {
    int array[] = {87, 99, 13, 76, 2, 3, 55, 4, 6, 0};
    int count = sizeof(array) / sizeof(array[0]);
    insertSort(array, count);
    printfInsertSort(array, count);
    return 0;
}