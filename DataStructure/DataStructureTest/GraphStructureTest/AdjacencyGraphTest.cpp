/*
#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 5

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
}

int main() {
    Graph graph = create();
    Graph invert_graph = create();
    for (int c = 'A'; c <= 'D'; ++c) {
        addVertex(graph, (char)c);
        addVertex(invert_graph, (char)c);
    }
    addEdge1(graph, 0, 1);   //A -> B
    addEdge1(graph, 1, 2);   //B -> C
    addEdge1(graph, 2, 3);   //C -> D
    addEdge1(graph, 3, 0);   //D -> A
    addEdge1(graph, 2, 0);   //C -> A
    printGraph(graph);
    printf("\n");
    addEdge2(invert_graph, 0, 1);   //A -> B
    addEdge2(invert_graph, 1, 2);   //B -> C
    addEdge2(invert_graph, 2, 3);   //C -> D
    addEdge2(invert_graph, 3, 0);   //D -> A
    addEdge2(invert_graph, 2, 0);   //C -> A
    printGraph(invert_graph);
}
*/