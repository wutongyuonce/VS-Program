#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char E;


//PreOrder
/*
struct TreeNode {
	E element;    //���Ԫ��
	struct TreeNode* left;   //ָ����������ָ��
	struct TreeNode* right;   //ָ����������ָ��
};

typedef struct TreeNode* Node;

void preOrder(Node root) {
	if (root == NULL) return;   //����ߵ�NULL�ˣ��Ǿͱ�ʾ�Ѿ���ͷ�ˣ�ֱ�ӷ���
	printf("%c", root->element);
	preOrder(root->left);   //�����ӽ��ݹ齻����һ��
	preOrder(root->right);  //�������һϵ������ݹ����������ͬ���ķ�ʽȥ���ұ�
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
    fprintf(stderr, "�ڴ����ʧ��\n");
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

//--------------- ���� ----------------
typedef Node T;   //���ǽ�Node��ΪԪ��

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
    struct Queue queue;   //�ȸ�һ������
    initQueue(&queue);
    offerQueue(&queue, root);  //�ȰѸ��ڵ����
    while (!isEmpty(&queue)) {   //�����ظ���ֱ�����п�Ϊֹ
        Node node = pollQueue(&queue);   //����һ��Ԫ�أ���ӡֵ
        printf("%c", node->element);
        if (node->left)    //����������Һ��ӵĻ�
            offerQueue(&queue, node->left);  //�ǵý����Һ�����ӣ�ע��˳���������
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
		fprintf(stderr, "�ڴ����ʧ��\n");
	}
	//preOrder(a);
    levelOrder(a);
}
*/