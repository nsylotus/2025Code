#include <stdio.h>
#include <windows.h>

void heapInsert(int *array, int i);

void heapIfy(int *array, int size, int i);

void heapSort(int *array, int size);

void printfArray(int *array, int array_size);

void swap(int *array, int num1, int num2);

void heapInsert(int *array, int i) {
    while (i > 0 && array[i] > array[(i - 1) >> 1]) {
        swap(array, i, (i - 1) >> 1);
        i = (i - 1) >> 1;
    }
}

void heapIfy(int *array, int size, int i) {
    int l = i * 2 + 1;
    while (l < size) {
        int best = l + 1 < size && array[l + 1] > array[l] ? l + 1 : l;
        best = array[best] > array[i] ? best : i;
        if (best == i) {
            break;
        }
        swap(array, best, i);
        i = best;
        l = i * 2 + 1;
    }
}


void heapSort(int *array, int size) {
    /**
     *  从顶到底建立大根堆，O(n * logn)
	 *  依次弹出堆内最大值并排好序，O(n * logn)
	 *  整体时间复杂度O(n * logn)
     * for (int i = 0; i < size; i++) {
     *   heapInsert(array, i);
    }*/
    // 从底到顶建立大根堆，O(n)
    // 依次弹出堆内最大值并排好序，O(n * logn)
    // 整体时间复杂度O(n * logn)
    for (int i = size - 1; i >= 0; i--) {
        heapIfy(array, i, size);
    }
    printf("建立大根堆\n");
    printfArray(array, size);
    while (size > 1) {
        swap(array, 0, --size);
        heapIfy(array, size, 0);
    }
}

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

int main(int argc, char const *argv[]) {
    SetConsoleOutputCP(65001);
    int array[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    int size = sizeof(array) / sizeof(array[0]);
    printf("堆排序的原数组\n");
    printfArray(array, size);
    heapSort(array, size);
    printf("堆排序后的数组\n");
    printfArray(array, size);
    return 0;
}