#include <stdio.h>

void Swap(int *array, int index1, int index2) {
    int temp = array[index2];
    array[index2] = array[index1];
    array[index1] = temp;
}

void printfSelectSort(int *array, int length) {
    printf("SelectSort:");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void SelectSort(int *array, int length) {
    for (int i = 0; i < length - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (array[minIndex] > array[j]) {
                minIndex = j;
            }
        }
        Swap(array, i, minIndex);
    }
}

int main(int argc, char const *argv[]) {
    int array[5] = {5, 3, 1, 2, 4};
    int count = sizeof(array) / sizeof(array[0]);
    SelectSort(array, count);
    printfSelectSort(array, count);
    return 0;
}