#include <stdio.h>

void printfBubbleSort(int *array, int length) {
    printf("BubbleSort:");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
}

void Swap(int *array, int index1, int index2) {
    int temp = array[index2];
    array[index2] = array[index1];
    array[index1] = temp;
}

void BubbleSort(int *array, int length) {
    for (int end = length - 1; end > 0; end--) {
        for (int j = 0; j < end; j++) {
            if (array[j] > array[j + 1]) {
                Swap(array, j, j + 1);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int array[5] = {5, 3, 1, 2, 4};
    int count = sizeof(array) / sizeof(array[0]);
    BubbleSort(array, count);
    printfBubbleSort(array, count);
    return 0;
}