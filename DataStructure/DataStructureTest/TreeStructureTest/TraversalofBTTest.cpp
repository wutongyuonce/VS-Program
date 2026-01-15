#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char E;


//PreOrder
/*
struct TreeNode {
	E element;    //存放元素
	struct TreeNode* left;   //指向左子树的指针
	struct TreeNode* right;   //指向右子树的指针
};

typedef struct TreeNode* Node;

void preOrder(Node root) {
	if (root == NULL) return;   //如果走到NULL了，那就表示已经到头了，直接返回
	printf("%c", root->element);
	preOrder(root->left);   //将左孩子结点递归交给下一级
	preOrder(root->right);  //等上面的一系列向左递归结束后，再以同样的方式去到右边
}

int main() {
	Node a = (Node)(malloc(sizeof(struct TreeNode)));
	Node b = (Node)(malloc(sizeof(struct TreeNode)));
	Node c = (Node)(malloc(sizeof(struct TreeNode)));
	Node d = (Node)(malloc(sizeof(struct TreeNode)));
	Node e = (Node)(malloc(sizeof(struct TreeNode)));
	Node f = (Node)(malloc(sizeof(struct TreeNode)));
	if (a && b && c && d && e && f) {
		a->element = 'A';
		b->element = 'B';
		c->element = 'C';
		d->element = 'D';
		e->element = 'E';
		f->element = 'F';

		a->left = b;
		a->right = c;
		b->left = d;
		b->right = e;
		c->right = f;
		c->left = NULL;
		d->left = d->right = NULL;
		e->left = e->right = NULL;
		f->left = f->right = NULL;
	} else {
    fprintf(stderr, "内存分配失败\n");
	}
	preOrder(a);
}
*/
//InOrder
 
// PostOrder

//LevelOrder
/*
struct TreeNode {
    E element;
    struct TreeNode* left;
    struct TreeNode* right;
    int flag;
};

typedef struct TreeNode* Node;

//--------------- 队列 ----------------
typedef Node T;   //还是将Node作为元素

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
//--------------------------------

void levelOrder(Node root) {
    struct Queue queue;   //先搞一个队列
    initQueue(&queue);
    offerQueue(&queue, root);  //先把根节点入队
    while (!isEmpty(&queue)) {   //不断重复，直到队列空为止
        Node node = pollQueue(&queue);   //出队一个元素，打印值
        printf("%c", node->element);
        if (node->left)    //如果存在左右孩子的话
            offerQueue(&queue, node->left);  //记得将左右孩子入队，注意顺序，先左后右
        if (node->right)
            offerQueue(&queue, node->right);
    }
}
*/

/*
int main() {
	Node a = (Node)(malloc(sizeof(struct TreeNode)));
	Node b = (Node)(malloc(sizeof(struct TreeNode)));
	Node c = (Node)(malloc(sizeof(struct TreeNode)));
	Node d = (Node)(malloc(sizeof(struct TreeNode)));
	Node e = (Node)(malloc(sizeof(struct TreeNode)));
	Node f = (Node)(malloc(sizeof(struct TreeNode)));
	if (a && b && c && d && e && f) {
		a->element = 'A';
		b->element = 'B';
		c->element = 'C';
		d->element = 'D';
		e->element = 'E';
		f->element = 'F';

		a->left = b;
		a->right = c;
		b->left = d;
		b->right = e;
		c->right = f;
		c->left = NULL;
		d->left = d->right = NULL;
		e->left = e->right = NULL;
		f->left = f->right = NULL;
	}
	else {
		fprintf(stderr, "内存分配失败\n");
	}
	//preOrder(a);
    levelOrder(a);
}
*/