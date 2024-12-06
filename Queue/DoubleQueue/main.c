#include "DoubleQueue.h"
#include <windows.h>

void DoubleQueueTest01() {
    Queue *queue = InitDoubleQueue();
    printf("%d", isQueueEmpty(queue));
    printf("%d\n", isFull(queue));
    for (int i = 0; i < MAXSIZE; i++) {
        rearEnQueue(queue, i);
    }
    PrintfDoubleQueue(queue);
    frontDeQueue(queue);
    frontDeQueue(queue);
    PrintfDoubleQueue(queue);
    rearEnQueue(queue, 666);
    rearEnQueue(queue, 888);
    PrintfDoubleQueue(queue);
    frontDeQueue(queue);
    printf("尾部的数据是%d\n",Rear(queue));
    printf("头部的数据是%d\n", Front(queue));
    rearDeQueue(queue);
    PrintfDoubleQueue(queue);
}

void DoubleQueueTest02(){
    Queue *queue = InitDoubleQueue();
    for (int i = 0; i < MAXSIZE; i++) {
        rearEnQueue(queue, i);
    }
    PrintfDoubleQueue(queue);
    rearDeQueue(queue);
    rearDeQueue(queue);
    frontDeQueue(queue);
    frontDeQueue(queue);
    PrintfDoubleQueue(queue);
    printf("尾部的数据是%d\n",Rear(queue));
    printf("头部的数据是%d\n", Front(queue));
    frontEnQueue(queue,520);
    rearEnQueue(queue,666);
    PrintfDoubleQueue(queue);
}

int main(int argc, char const *argv[]) {
    SetConsoleOutputCP(65001);
    //DoubleQueueTest01();
    DoubleQueueTest02();
    return 0;
}
