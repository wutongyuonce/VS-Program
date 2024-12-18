/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct Queue {
	E* array;
	int capacity;		//数组容量
	int rear, front;	//队尾、队首指针
};
typedef struct Queue* SeqQueue;

bool initQueue(SeqQueue queue) {
	queue->array = (E*)(malloc(sizeof(E) * 10));
	if (queue->array == NULL) return 0;
	queue->capacity = 10;
	queue->front = queue->rear = 0;		//默认情况下队首和队尾都指向0的位置
	return 1;
}

bool isEmpty(SeqQueue queue) {	//在出队之前先要看看容量是否足够
	return queue->rear == queue->front;
}

E pollQueue(SeqQueue queue) {
	queue->front = queue->front + 1 % queue->capacity;	//先将队首指针后移
	return queue->array[queue->front];	//出队，完事
}

void printQueue(SeqQueue queue) {
	printf("<<< ");
	int i = queue->front;	//遍历队列需要从队首开始
	do {
		i = (i + 1) % queue->capacity;	//先向后循环移动
		printf("%d ", queue->array[i]);	//然后打印当前位置上的元素
	} while (i != queue->rear);		//当到达队尾时结束
	printf("<<<\n");
}

bool offerQueue(SeqQueue queue, E element) {
	if ((queue->rear + 1) % queue->capacity == queue->front)	  //先判断队列是否已满，如果队尾下一个就是队首，那么说明已满
		return 0;
	queue->rear = (queue->rear + 1) % queue->capacity;		//队尾先向前移动一位，注意取余计算才能实现循环
	queue->array[queue->rear] = element;	//在新的位置插入元素
	return 1;	
}

int main() {
	struct Queue queue;
	initQueue(&queue);
	for (int i = 0;i < 5;++i) {
		offerQueue(&queue, i * 100);
	}
	printQueue(&queue);
	while(!isEmpty(&queue)) {
		printf("%d ", pollQueue(&queue));
	}
}
*/