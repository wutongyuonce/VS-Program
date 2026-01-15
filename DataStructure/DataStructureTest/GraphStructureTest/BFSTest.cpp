/*
#include <stdio.h>
#include <stdlib.h>

typedef int T;   //这里将顶点下标作为元素

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

typedef struct Node {   //结点和头结点分开定义，普通结点记录邻接顶点信息
    int nextVertex;
    struct Node* next;
} *NormNode;

struct HeadNode {   //头结点记录元素
    E element;
    struct Node* next;
};

typedef struct AdjacencyGraph {
    int vertexCount;   //顶点数
    int edgeCount;     //边数
    struct HeadNode vertex[MaxVertex];
} *Graph;

Graph create() {   //创建时，我们可以指定图中初始有多少个结点
    Graph graph = (Graph)(malloc(sizeof(struct AdjacencyGraph)));
    graph->vertexCount = graph->edgeCount = 0;
    return graph;   //头结点数组一开始可以不用管
}

void addVertex(Graph graph, E element) {
    if (graph->vertexCount >= MaxVertex) return;   //跟之前一样
    graph->vertex[graph->vertexCount].element = element;   //添加新结点时，再来修改也行
    graph->vertex[graph->vertexCount].next = NULL;
    graph->vertexCount++;
}

void addEdge1(Graph graph, int a, int b) {
    NormNode node = graph->vertex[a].next;
    NormNode newNode = (NormNode)(malloc(sizeof(struct Node)));
    newNode->next = NULL;
    newNode->nextVertex = b;
    if (!node) {    //如果头结点下一个都没有，那么直接连上去
        graph->vertex[a].next = newNode;
    }
    else {   //否则说明当前顶点已经连接了至少一个其他顶点了，有可能会出现已经连接过的情况，所以说要特别处理一下
        do {
            if (node->nextVertex == b) return;   //如果已经连接了对应的顶点，那么直接返回
            if (node->next) node = node->next;   //否则继续向后遍历
            else break;   //如果没有下一个了，那就找到最后一个结点了，直接结束
        } while (1);
        node->next = newNode;
    }
    graph->edgeCount++;   //边数计数+1
}

void addEdge2(Graph graph, int a, int b) {
    NormNode node = graph->vertex[b].next;
    NormNode newNode = (NormNode)(malloc(sizeof(struct Node)));
    newNode->next = NULL;
    newNode->nextVertex = a;
    if (!node) {    //如果头结点下一个都没有，那么直接连上去
        graph->vertex[b].next = newNode;
    }
    else {   //否则说明当前顶点已经连接了至少一个其他顶点了，有可能会出现已经连接过的情况，所以说要特别处理一下
        do {
            if (node->nextVertex == b) return;   //如果已经连接了对应的顶点，那么直接返回
            if (node->next) node = node->next;   //否则继续向后遍历
            else break;   //如果没有下一个了，那就找到最后一个结点了，直接结束
        } while (1);
        node->next = newNode;
    }
    graph->edgeCount++;   //边数计数+1
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
 * 广度优先遍历
 * @param graph 图
 * @param startVertex 起点顶点下标
 * @param targetVertex 目标顶点下标
 * @param visited 已到达过的顶点数组
 * @param queue 辅助队列
 */

/*
bool bfs(Graph graph, int startVertex, int targetVertex, int* visited, LinkedQueue queue) {
    offerQueue(queue, startVertex);
    visited[startVertex] = 1;
    while (!isEmpty(queue)) {
        int next = pollQueue(queue);
        printf("%c -> ", graph->vertex[next].element);
        if (next == targetVertex) return 1; // 找到目标顶点，直接返回1
        NormNode node = graph->vertex[next].next;
        while (node) {
            if (!visited[node->nextVertex]) {
                offerQueue(queue, node->nextVertex);
                visited[node->nextVertex] = 1;
            }
            node = node->next;
        }
    }
    return 0;   //找完了还没有，那就返回0
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