/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct LNode {
    E element;
    struct LNode* next;
};

typedef struct LNode* Node;

struct Queue {
    Node front, rear;
};

typedef struct Queue* LinkedQueue;   //��ΪҪ�洢��λ����ָ�룬���������װһ���µĽṹ��

bool initQueue(LinkedQueue queue) {
    Node node = (Node)(malloc(sizeof(struct LNode)));
    if (node == NULL) return 0;
    node->next = NULL;
    queue->front = queue->rear = node;  //һ��ʼ����ָ�붼��ָ��ͷ���ģ���ʾ����Ϊ��
    return 1;
}

bool offerQueue(LinkedQueue queue, E element) {
    Node node = (Node)(malloc(sizeof(struct LNode)));
    if (node == NULL) return 0;
    else {//���ݶ��еĵ�ǰ״̬������front��rearָ���nextָ���ֵ��
        node->next = NULL;
        node->element = element;
        if (isEmpty(queue)) {//������Ϊ��ʱ��������Ҫ��front��rearָ���nextָ���һ������Ľڵ㣻
            queue->front->next = node;
            queue->rear->next = node;
        }
        else {//�����в�Ϊ��ʱ������ֻ��Ҫ����rearָ���nextָ���µĽڵ㼴�ɡ�
            queue->rear->next = node;   //����β������һ��ָ���µĽ��
            queue->rear = node;   //Ȼ���ö�βָ��ָ���µ�β���
        }
        return 1;
    }
}

bool isEmpty(LinkedQueue queue) {	//�ڳ���֮ǰ��Ҫ���������Ƿ��㹻
    return queue->rear == queue->front;
}

E pollQueue(LinkedQueue queue) {
    E e = queue->front->next->element;
    Node node = queue->front->next;
    queue->front->next = queue->front->next->next;  //ֱ����ͷ���ָ�����¸����
    if (queue->rear == node) 
        queue->rear = queue->front;   //�����β���Ǵ����ӵĽ�㣬��ô��β�ص�����λ����
    free(node);   //�ͷ��ڴ�
    return e;
}

void printQueue(LinkedQueue queue) {
    printf("<<< ");
    Node node = queue->front->next;
    while (1) {    //ע�ⲻ��ֱ���пգ���Ϊǰ������û���ǣ�Ҳ��û���½��next�趨ΪNULL
        printf("%d ", node->element);
        if (node == queue->rear) break;    //���Ѿ���ӡ���һ��Ԫ�غ��ٽ���
        else node = node->next;
    }
    printf("<<<\n");
}

int main() {
    struct Queue queue;
    initQueue(&queue);
    for (int i = 0;i < 5;++i) {
        offerQueue(&queue, i * 100);
    }
    printQueue(&queue);
    while (!isEmpty(&queue)) {
        printf("%d ", pollQueue(&queue));
    }
}
*/