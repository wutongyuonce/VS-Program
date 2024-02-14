/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct Queue {
	E* array;
	int capacity;		//��������
	int rear, front;	//��β������ָ��
};
typedef struct Queue* ArrayQueue;

bool initQueue(ArrayQueue queue) {
	queue->array = (E*)(malloc(sizeof(E) * 10));
	if (queue->array == NULL) return 0;
	queue->capacity = 10;
	queue->front = queue->rear = 0;		//Ĭ������¶��׺Ͷ�β��ָ��0��λ��
	return 1;
}

bool isEmpty(ArrayQueue queue) {	//�ڳ���֮ǰ��Ҫ���������Ƿ��㹻
	return queue->rear == queue->front;
}

E pollQueue(ArrayQueue queue) {
	queue->front = queue->front + 1 % queue->capacity;	//�Ƚ�����ָ�����
	return queue->array[queue->front];	//���ӣ�����
}


void printQueue(ArrayQueue queue) {
	printf("<<< ");
	int i = queue->front;	//����������Ҫ�Ӷ��׿�ʼ
	do {
		i = (i + 1) % queue->capacity;	//�����ѭ���ƶ�
		printf("%d ", queue->array[i]);	//Ȼ���ӡ��ǰλ���ϵ�Ԫ��
	} while (i != queue->rear);		//�������βʱ����
	printf("<<<\n");
}

bool offerQueue(ArrayQueue queue, E element) {
	if ((queue->rear + 1) % queue->capacity == queue->front)	  //���ж϶����Ƿ������������β��һ�����Ƕ��ף���ô˵������
		return 0;
	queue->rear = (queue->rear + 1) % queue->capacity;		//��β����ǰ�ƶ�һλ��ע��ȡ��������ʵ��ѭ��
	queue->array[queue->rear] = element;	//���µ�λ�ò���Ԫ��
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