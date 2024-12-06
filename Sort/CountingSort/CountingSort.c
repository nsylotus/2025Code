#include <stdio.h>
#include <windows.h>

int getMax(int *array, int size);

int getMin(int *array, int size);

void printfArray(int *array, int size);

void printfArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int getMax(int *array, int size) {
    int indexMax = 0;
    for (int i = 0; i < size; i++) {
        if (array[indexMax] < array[i]) {
            indexMax = i;
        }
    }
    return array[indexMax];
}

int getMin(int *array, int size) {
    int indexMin = 0;
    for (int i = 0; i < size; i++) {
        if (array[indexMin] > array[i]) {
            indexMin = i;
        }
    }
    return array[indexMin];
}

int main(int argc, char const *argv[]) {
    SetConsoleOutputCP(65001);
    int array[] = {5, 3, 2, 9, 0, 2, 6, 6, -1, -2};
    int array_size = sizeof(array) / sizeof(array[0]);
    int valueMin = getMin(array, array_size);
    int valueMax = getMax(array, array_size);
    int help[valueMax - valueMin + 1];
    for (int i = 0; i < valueMax - valueMin + 1; i++) {
        help[i] = 0;
    }

    printf("原排序数组\n");
    printfArray(array, array_size);

    for (int i = 0; i < array_size; i++) {
        help[array[i] - valueMin]++;
    }

    printf("计数的数组是\n");
    printfArray(help, valueMax + 1);

    int k = 0;
    for (int i = 0; i < sizeof(help) / sizeof(help[0]); i++) {
        while (help[i] > 0) {
            array[k++] = i + valueMin;
            help[i]--;
        }
    }

    printf("基数排序后的结果\n");
    printfArray(array, array_size);
    return 0;
}