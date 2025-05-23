/*
#include <stdio.h>
#include <stdlib.h>

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
 * 深度优先搜索
 * @param graph 图
 * @param startVertex 起点顶点下标
 * @param targetVertex 目标顶点下标
 * @param visited 已到达过的顶点数组
 * @return 搜索结果，如果找到返回1，没找到返回0
 */

/*
bool dfs(Graph graph, int startVertex, int targetVertex, int* visited) {
    visited[startVertex] = 1;
    printf("%c -> ", graph->vertex[startVertex].element);
    if (startVertex == targetVertex) return 1;   //如果当前顶点就是要找的顶点，直接返回
    NormNode node = graph->vertex[startVertex].next;
    while (node) {
        if (!visited[node->nextVertex])
            if (dfs(graph, node->nextVertex, targetVertex, visited))  //如果查找成功，直接返回1，不用再看其他分支了
                return 1;
        node = node->next;
    }
    return 0;   //while结束那肯定是没找到了，直接返回0
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
    for (int i = 0; i < graph->vertexCount; ++i) arr[i] = 0;
    printf("\n%d", dfs(graph, 0, 5, arr));
}
*/