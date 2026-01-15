//#include<stdio.h>
//#include<stdlib.h>
//
//#define MAX_VERTEX_NUM 20
//
//// 邻接表中表对应的链表的顶点
//typedef struct ArcNode {
//    int adjvex; // 该弧所指向的顶点的位置
//    struct ArcNode* nextarc; // 指向下一条弧的指针
//} ArcNode;
//
//// 邻接表的顶点
//typedef struct VNode {
//    char data; // 顶点信息
//    ArcNode* firstarc; // 指向第一条依附该顶点的弧的指针
//} VNode, AdjList[MAX_VERTEX_NUM];
//
//// 邻接表
//typedef struct {
//    AdjList vertices;
//    int vexnum, arcnum; // 图的当前顶点数和弧数
//} ALGraph;
//
//// 创建图中的边
//void AddEdge(ALGraph* G, int from, int to) {
//    ArcNode* e = (ArcNode*)malloc(sizeof(ArcNode));
//    e->adjvex = to;
//    e->nextarc = G->vertices[from].firstarc;
//    G->vertices[from].firstarc = e;
//}
//
//// 构建图
//void CreateGraph(ALGraph* G) {
//    G->vexnum = 5; // 假设图中有5个顶点
//    G->arcnum = 4; // 假设图中有4条边
//
//    // 假设顶点用字符表示
//    for (int i = 0; i < G->vexnum; i++) {
//        G->vertices[i].data = 'A' + i;
//        G->vertices[i].firstarc = NULL;
//    }
//
//    // 添加边，构建如下的图结构:
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
//// 队列节点
//typedef struct QNode {
//    int data;
//    struct QNode* next;
//} QNode, * QueuePtr;
//
//// 队列
//typedef struct {
//    QueuePtr front; // 队头
//    QueuePtr rear; // 队尾
//} LinkQueue;
//
//void InitQueue(LinkQueue* Q) {
//    // 初始化队列
//    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
//    if (!Q->front) exit(0);
//    Q->front->next = NULL;
//}
//
//void EnQueue(LinkQueue* Q, int e) {
//    // 入队
//    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
//    if (!p) exit(0);
//    p->data = e;
//    p->next = NULL;
//    Q->rear->next = p;
//    Q->rear = p;
//}
//
//int DeQueue(LinkQueue* Q, int* e) {
//    // 出队
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
//    // 判断队列是否为空
//    return Q.front == Q.rear;
//}
//
//void TopologicalSort(ALGraph G) {
//    int indegree[MAX_VERTEX_NUM] = { 0 }; // 初始化所有顶点的入度为0
//    for (int i = 0; i < G.vexnum; i++) {
//        ArcNode* p = G.vertices[i].firstarc;
//        while (p) {
//            indegree[p->adjvex]++;
//            p = p->nextarc;
//        }
//    }
//
//    // 初始化队列
//    LinkQueue Q;
//    InitQueue(&Q);
//
//    // 将所有入度为0的顶点入队
//    for (int i = 0; i < G.vexnum; i++) {
//        if (indegree[i] == 0) EnQueue(&Q, i);
//    }
//
//    int count = 0; // 计数，记录当前已处理的顶点数
//    while (!IsEmptyQueue(Q)) {
//        int i;
//        DeQueue(&Q, &i);
//        printf("%c ", G.vertices[i].data); // 打印顶点
//        count++;
//
//        for (ArcNode* p = G.vertices[i].firstarc; p; p = p->nextarc) {
//            int k = p->adjvex;
//            if (!(--indegree[k])) EnQueue(&Q, k);
//        }
//    }
//
//    if (count < G.vexnum) printf("Graph has a cycle\n"); // 如果count小于顶点数，说明图中存在环
//}
//
//int main() {
//    ALGraph G;
//    CreateGraph(&G);
//    printf("Topological Sorting of the given graph:\n");
//    TopologicalSort(G);
//    return 0;
//}