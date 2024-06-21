//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX_VERTEX_NUM 20
//
//// �ڽӱ��б��Ӧ������Ķ���
//typedef struct ArcNode {
//    int adjvex; // �û���ָ��Ķ����λ��
//    struct ArcNode* nextarc; // ָ����һ������ָ��
//} ArcNode;
//
//// �ڽӱ�Ķ���
//typedef struct VNode {
//    char data; // ������Ϣ
//    ArcNode* firstarc; // ָ���һ�������ö���Ļ���ָ��
//} VNode, AdjList[MAX_VERTEX_NUM];
//
//// �ڽӱ�
//typedef struct {
//    AdjList vertices;
//    int vexnum, arcnum; // ͼ�ĵ�ǰ�������ͻ���
//} ALGraph;
//
//// ����ͼ�еı�
//void AddEdge(ALGraph* G, int from, int to) {
//    ArcNode* e = (ArcNode*)malloc(sizeof(ArcNode));
//    e->adjvex = to;
//    e->nextarc = G->vertices[from].firstarc;
//    G->vertices[from].firstarc = e;
//}
//
//// ����ͼ
//void CreateGraph(ALGraph* G) {
//    G->vexnum = 5; // ����ͼ����5������
//    G->arcnum = 4; // ����ͼ����4����
//
//    // ���趥�����ַ���ʾ
//    for (int i = 0; i < G->vexnum; i++) {
//        G->vertices[i].data = 'A' + i;
//        G->vertices[i].firstarc = NULL;
//    }
//
//    // ��ӱߣ��������µ�ͼ�ṹ:
//    // A -> B
//    // A -> C
//    // B -> D
//    // C -> E
//    AddEdge(G, 0, 1); // A -> B
//    AddEdge(G, 0, 2); // A -> C
//    AddEdge(G, 1, 3); // B -> D
//    AddEdge(G, 2, 4); // C -> E
//}
//
//// ���нڵ�
//typedef struct QNode {
//    int data;
//    struct QNode* next;
//} QNode, * QueuePtr;
//
//// ����
//typedef struct {
//    QueuePtr front; // ��ͷ
//    QueuePtr rear; // ��β
//} LinkQueue;
//
//void InitQueue(LinkQueue* Q) {
//    // ��ʼ������
//    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
//    if (!Q->front) exit(0);
//    Q->front->next = NULL;
//}
//
//void EnQueue(LinkQueue* Q, int e) {
//    // ���
//    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
//    if (!p) exit(0);
//    p->data = e;
//    p->next = NULL;
//    Q->rear->next = p;
//    Q->rear = p;
//}
//
//int DeQueue(LinkQueue* Q, int* e) {
//    // ����
//    if (Q->front == Q->rear) return 0;
//    QueuePtr p = Q->front->next;
//    *e = p->data;
//    Q->front->next = p->next;
//    if (Q->rear == p) Q->rear = Q->front;
//    free(p);
//    return 1;
//}
//
//int IsEmptyQueue(LinkQueue Q) {
//    // �ж϶����Ƿ�Ϊ��
//    return Q.front == Q.rear;
//}
//
//void TopologicalSort(ALGraph G) {
//    int indegree[MAX_VERTEX_NUM] = { 0 }; // ��ʼ�����ж�������Ϊ0
//    for (int i = 0; i < G.vexnum; i++) {
//        ArcNode* p = G.vertices[i].firstarc;
//        while (p) {
//            indegree[p->adjvex]++;
//            p = p->nextarc;
//        }
//    }
//
//    // ��ʼ������
//    LinkQueue Q;
//    InitQueue(&Q);
//
//    // ���������Ϊ0�Ķ������
//    for (int i = 0; i < G.vexnum; i++) {
//        if (indegree[i] == 0) EnQueue(&Q, i);
//    }
//
//    int count = 0; // ��������¼��ǰ�Ѵ���Ķ�����
//    while (!IsEmptyQueue(Q)) {
//        int i;
//        DeQueue(&Q, &i);
//        printf("%c ", G.vertices[i].data); // ��ӡ����
//        count++;
//
//        for (ArcNode* p = G.vertices[i].firstarc; p; p = p->nextarc) {
//            int k = p->adjvex;
//            if (!(--indegree[k])) EnQueue(&Q, k);
//        }
//    }
//
//    if (count < G.vexnum) printf("Graph has a cycle\n"); // ���countС�ڶ�������˵��ͼ�д��ڻ�
//}
//
//int main() {
//    ALGraph G;
//    CreateGraph(&G);
//    printf("Topological Sorting of the given graph:\n");
//    TopologicalSort(G);
//    return 0;
//}