/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct ListNode {
	E element;		//保存当前元素
	struct ListNode* next;	//指向下一个结点的指针
	struct ListNode* prev;	//指向上一个结点的指针
};

typedef struct ListNode* Node;

void initNode(Node head) {
	head->next = head->prev = NULL;
}

bool insertList(Node head, E element, int index) {
	if (index < 1) return 0;
	else {
		while (--index) {
			head = head->next;
			if (head == NULL) return 0;
		}
		Node node = (Node)(malloc(sizeof(struct ListNode)));	//创建新的结点
		if (node == NULL) return 0;
		else {
			node->element = element;
			if (head->next) {	//首先处理后继结点，现在有两种情况，一种是后继结点不存在的情况，还有一种是后继结点存在的情况
				head->next->prev = node;	//如果存在则修改对应的两个指针
				node->next = head->next;
			}
			else {
				node->next=NULL;	//不存在直接将新结点的后继指针置为NULL
			}
			head->next = node;		//接着是前驱结点，直接操作
			node->prev = head;
			return 1;
		}
	}
}
                           
bool deleteList(Node head, int index) {
	if (index < 1) return 0;
	else {
		while(--index) {
			head = head->next;
			if (head->next = NULL) return 0;
		}
		if (head->next == NULL) return 0;
		Node tmp = head->next;	//先拿到待删除结点
		if (head->next->next) {//这里有两种情况待删除结点存在后继结点或是不存在
			head->next->next->prev = head;
			head->next = head->next->next;
		}
		else {
			head->next = NULL;	//相当于删的是
		}
		free(tmp);		//最后释放已删除结点的内存
		return 1;
	}
}

int main() {
	struct ListNode head;
	initNode(&head);
	for (int i = 0;i < 5;++i) insertList(&head, i * 100, i+1);	//插入5个元素

	Node node = &head;	//先来正向遍历一次
	do {
		node = node->next;
		printf("%d -> ", node->element);
	} while (node->next != NULL);
	printf("\n");		//再来反向遍历一次
	do {
		printf("%d -> ", node->element);
		node = node->prev;
	} while (node->prev != NULL);
}
*/