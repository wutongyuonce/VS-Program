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

typedef struct Queue* LinkedQueue;   //因为要存储首位两个指针，所以这里封装一个新的结构体

bool initQueue(LinkedQueue queue) {
    Node node = (Node)(malloc(sizeof(struct LNode)));
    if (node == NULL) return 0;
    node->next = NULL;
    queue->front = queue->rear = node;  //一开始两个指针都是指向头结点的，表示队列为空
    return 1;
}

bool offerQueue(LinkedQueue queue, E element) {
    Node node = (Node)(malloc(sizeof(struct LNode)));
    if (node == NULL) return 0;
    else {//根据队列的当前状态来更新front和rear指针的next指向的值。
        node->next = NULL;
        node->element = element;
        if (isEmpty(queue)) {//当队列为空时，我们需要将front和rear指针的next指向第一个插入的节点；
            queue->front->next = node;
            queue->rear->next = node;
        }
        else {//当队列不为空时，我们只需要更新rear指针的next指向新的节点即可。
            queue->rear->next = node;   //先让尾结点的下一个指向新的结点
            queue->rear = node;   //然后让队尾指针指向新的尾结点
        }
        return 1;
    }
}

bool isEmpty(LinkedQueue queue) {	//在出队之前先要看看容量是否足够
    return queue->rear == queue->front;
}

E pollQueue(LinkedQueue queue) {
    E e = queue->front->next->element;
    Node node = queue->front->next;
    queue->front->next = queue->front->next->next;  //直接让头结点指向下下个结点
    if (queue->rear == node) 
        queue->rear = queue->front;   //如果队尾就是待出队的结点，那么队尾回到队首位置上
    free(node);   //释放内存
    return e;
}

void printQueue(LinkedQueue queue) {
    printf("<<< ");
    Node node = queue->front->next;
    while (1) {    //注意不能直接判空，因为前面我们没考虑，也就没将新结点next设定为NULL
        printf("%d ", node->element);
        if (node == queue->rear) break;    //当已经打印最后一个元素后，再结束
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