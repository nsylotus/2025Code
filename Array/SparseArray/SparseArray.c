#include <stdio.h>
#include <windows.h>

#define ARRAY_INDEX 5

int k = 1;
int help[][3] = {0};

int printArray(int array[][ARRAY_INDEX], int row, int col);

void sparseArray(int array[][ARRAY_INDEX], int count, int row, int col);

void printHelp();

int printArray(int array[][ARRAY_INDEX], int row, int col) {
    int count = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", array[i][j]);
            if (array[i][j] != 0) {
                count++;
            }
        }
        printf("\n");
    }
    printf("\n");
    return count;
}

void printHelp() {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", help[i][j]);
        }
        printf("\n");
    }
}

void sparseArray(int array[][ARRAY_INDEX], int count, int row, int col) {
    help[0][0] = (row * col) / ARRAY_INDEX;
    help[0][1] = ARRAY_INDEX;
    help[0][2] = count;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (array[i][j] != 0) {
                help[k][0] = i;
                help[k][1] = j;
                help[k][2] = array[i][j];
                k++;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    SetConsoleOutputCP(65001);
    int array[][ARRAY_INDEX] = {
            {0, 0, 1, 2, 0},
            {0, 2, 0, 0, 5},
            {0, 0, 3, 0, 0}};
    int array_size_row = sizeof(array) / sizeof(array[0]);
    int array_size_col = sizeof(array[0]) / sizeof(array[0][0]);
    printf("压缩之前的数组\n");
    int count = printArray(array, array_size_row, array_size_col);
    sparseArray(array, count, array_size_row, array_size_col);
    printf("压缩之后的数组\n");
    printHelp();
    printf("将数组恢复\n");
    int newArray[help[0][0]][help[0][1]];
    for (int i = 0; i < help[0][0]; i++) {
        for (int j = 0; j < help[0][1]; j++) {
            newArray[i][j] = 0;
        }
    }
    for (int i = 1; i < k; i++) {
        newArray[help[i][0]][help[i][1]] = help[i][2];
    }
    printArray(newArray, help[0][0], help[0][1]);
    return 0;
}
