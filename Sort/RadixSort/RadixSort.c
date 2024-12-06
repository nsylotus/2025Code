#include <stdio.h>
#include <windows.h>

void printfArray(int *array, int array_size);

void printfArray(int *array, int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
}

int main(int argc, char const *argv[]) {
    SetConsoleOutputCP(65001);
    int array[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    int array_size = sizeof(array) / sizeof(array[0]);
    printfArray(array, array_size);
    return 0;
}