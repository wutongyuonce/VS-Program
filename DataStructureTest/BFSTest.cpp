/*
#include <stdio.h>
#include <stdlib.h>

typedef int T;   //���ｫ�����±���ΪԪ��

struct QueueNode {
    T element;
    struct QueueNode* next;
};

typedef struct QueueNode* QNode;

struct Queue {
    QNode front, rear;
};

typedef struct Queue* LinkedQueue;

bool initQueue(LinkedQueue queue) {
    QNode node = (QNode)(malloc(sizeof(struct QueueNode)));
    if (node == NULL) return 0;
    queue->front = queue->rear = node;
    return 1;
}

bool offerQueue(LinkedQueue queue, T element) {
    QNode node = (QNode)(malloc(sizeof(struct QueueNode)));
    if (node == NULL) return 0;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return 1;
}

bool isEmpty(LinkedQueue queue) {
    return queue->front == queue->rear;
}

T pollQueue(LinkedQueue queue) {
    T e = queue->front->next->element;
    QNode node = queue->front->next;
    queue->front->next = queue->front->next->next;
    if (queue->rear == node) queue->rear = queue->front;
    free(node);
    return e;
}


#define MaxVertex 10

typedef char E;

typedef struct Node {   //����ͷ���ֿ����壬��ͨ����¼�ڽӶ�����Ϣ
    int nextVertex;
    struct Node* next;
} *NormNode;

struct HeadNode {   //ͷ����¼Ԫ��
    E element;
    struct Node* next;
};

typedef struct AdjacencyGraph {
    int vertexCount;   //������
    int edgeCount;     //����
    struct HeadNode vertex[MaxVertex];
} *Graph;

Graph create() {   //����ʱ�����ǿ���ָ��ͼ�г�ʼ�ж��ٸ����
    Graph graph = (Graph)(malloc(sizeof(struct AdjacencyGraph)));
    graph->vertexCount = graph->edgeCount = 0;
    return graph;   //ͷ�������һ��ʼ���Բ��ù�
}

void addVertex(Graph graph, E element) {
    if (graph->vertexCount >= MaxVertex) return;   //��֮ǰһ��
    graph->vertex[graph->vertexCount].element = element;   //����½��ʱ�������޸�Ҳ��
    graph->vertex[graph->vertexCount].next = NULL;
    graph->vertexCount++;
}

void addEdge1(Graph graph, int a, int b) {
    NormNode node = graph->vertex[a].next;
    NormNode newNode = (NormNode)(malloc(sizeof(struct Node)));
    newNode->next = NULL;
    newNode->nextVertex = b;
    if (!node) {    //���ͷ�����һ����û�У���ôֱ������ȥ
        graph->vertex[a].next = newNode;
    }
    else {   //����˵����ǰ�����Ѿ�����������һ�����������ˣ��п��ܻ�����Ѿ����ӹ������������˵Ҫ�ر���һ��
        do {
            if (node->nextVertex == b) return;   //����Ѿ������˶�Ӧ�Ķ��㣬��ôֱ�ӷ���
            if (node->next) node = node->next;   //�������������
            else break;   //���û����һ���ˣ��Ǿ��ҵ����һ������ˣ�ֱ�ӽ���
        } while (1);
        node->next = newNode;
    }
    graph->edgeCount++;   //��������+1
}

void addEdge2(Graph graph, int a, int b) {
    NormNode node = graph->vertex[b].next;
    NormNode newNode = (NormNode)(malloc(sizeof(struct Node)));
    newNode->next = NULL;
    newNode->nextVertex = a;
    if (!node) {    //���ͷ�����һ����û�У���ôֱ������ȥ
        graph->vertex[b].next = newNode;
    }
    else {   //����˵����ǰ�����Ѿ�����������һ�����������ˣ��п��ܻ�����Ѿ����ӹ������������˵Ҫ�ر���һ��
        do {
            if (node->nextVertex == b) return;   //����Ѿ������˶�Ӧ�Ķ��㣬��ôֱ�ӷ���
            if (node->next) node = node->next;   //�������������
            else break;   //���û����һ���ˣ��Ǿ��ҵ����һ������ˣ�ֱ�ӽ���
        } while (1);
        node->next = newNode;
    }
    graph->edgeCount++;   //��������+1
}

void printGraph(Graph graph) {
    for (int i = 0; i < graph->vertexCount; ++i) {
        printf("%d | %c", i, graph->vertex[i].element);
        NormNode node = graph->vertex[i].next;
        while (node) {
            printf(" -> %d", node->nextVertex);
            node = node->next;
        }
        putchar('\n');
    }
    putchar('\n');
}
*/

/**
 * ������ȱ���
 * @param graph ͼ
 * @param startVertex ��㶥���±�
 * @param targetVertex Ŀ�궥���±�
 * @param visited �ѵ�����Ķ�������
 * @param queue ��������
 */

/*
bool bfs(Graph graph, int startVertex, int targetVertex, int* visited, LinkedQueue queue) {
    offerQueue(queue, startVertex);
    visited[startVertex] = 1;
    while (!isEmpty(queue)) {
        int next = pollQueue(queue);
        printf("%c -> ", graph->vertex[next].element);
        if (next == targetVertex) return 1; // �ҵ�Ŀ�궥�㣬ֱ�ӷ���1
        NormNode node = graph->vertex[next].next;
        while (node) {
            if (!visited[node->nextVertex]) {
                offerQueue(queue, node->nextVertex);
                visited[node->nextVertex] = 1;
            }
            node = node->next;
        }
    }
    return 0;   //�����˻�û�У��Ǿͷ���0
}

int main() {
    Graph graph = create();
    for (int c = 'A'; c <= 'F'; ++c)
        addVertex(graph, (char)c);
    addEdge1(graph, 0, 1);   //A -> B
    addEdge1(graph, 1, 2);   //B -> C
    addEdge1(graph, 1, 3);   //B -> D
    addEdge1(graph, 1, 4);   //B -> E
    addEdge1(graph, 4, 5);   //E -> F
    printGraph(graph);

    int arr[MaxVertex];
    struct Queue queue;
    initQueue(&queue);
    for (int i = 0; i < graph->vertexCount; ++i) arr[i] = 0;
    printf("\n%d",bfs(graph, 0, 3, arr, &queue));
}
*/