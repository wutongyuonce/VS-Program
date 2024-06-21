/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct ListNode {
	E element;		//���浱ǰԪ��
	struct ListNode* next;	//ָ����һ������ָ��
	struct ListNode* prev;	//ָ����һ������ָ��
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
		Node node = (Node)(malloc(sizeof(struct ListNode)));	//�����µĽ��
		if (node == NULL) return 0;
		else {
			node->element = element;
			if (head->next) {	//���ȴ����̽�㣬���������������һ���Ǻ�̽�㲻���ڵ����������һ���Ǻ�̽����ڵ����
				head->next->prev = node;	//����������޸Ķ�Ӧ������ָ��
				node->next = head->next;
			}
			else {
				node->next=NULL;	//������ֱ�ӽ��½��ĺ��ָ����ΪNULL
			}
			head->next = node;		//������ǰ����㣬ֱ�Ӳ���
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
		Node tmp = head->next;	//���õ���ɾ�����
		if (head->next->next) {//���������������ɾ�������ں�̽����ǲ�����
			head->next->next->prev = head;
			head->next = head->next->next;
		}
		else {
			head->next = NULL;	//�൱��ɾ����
		}
		free(tmp);		//����ͷ���ɾ�������ڴ�
		return 1;
	}
}

int main() {
	struct ListNode head;
	initNode(&head);
	for (int i = 0;i < 5;++i) insertList(&head, i * 100, i+1);	//����5��Ԫ��

	Node node = &head;	//�����������һ��
	do {
		node = node->next;
		printf("%d -> ", node->element);
	} while (node->next != NULL);
	printf("\n");		//�����������һ��
	do {
		printf("%d -> ", node->element);
		node = node->prev;
	} while (node->prev != NULL);
}
*/