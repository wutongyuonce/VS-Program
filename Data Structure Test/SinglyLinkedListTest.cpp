/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct ListNode {
	E element; //���浱ǰԪ��
	struct ListNode* next; //ָ����һ���ڵ��ָ��
};

typedef ListNode* Node; //��������ֱ��Ϊ���ָ�������������ֱ����Ϊ��ʵ��

void initList(Node head) {
	head->next = NULL; //ͷ���Ĭ����һ��ΪNULL
}

bool insertList(Node head, E element, int index) {
	if (index < 1) return 0; //��������λ��С��1���ǿ϶��ǷǷ���
	else {
		while (--index) { //ͨ��--index�ķ�ʽ�������Ѱ��ǰ�����
			head = head->next; //��������¼��������
			if (head == NULL) return 0;
			//�����Ѱ�ҵĹ����з����Ѿ�û�к�������ˣ���ô˵��index�����ɲ���ķ�Χ�ˣ�Ҳ�ǷǷ��ģ�ֱ����
		}
		Node node = (Node)(malloc(sizeof(struct ListNode)));
		if (node == NULL) return 0; //����һ���µĽ�㣬����ڴ�ռ�����ʧ�ܷ���0
		node->element = element; //��Ԫ�ر��浽�´����Ľ����
		node->next = head->next; //�����²���Ľڵ�ָ��ԭ��λ���ϵ�������
		head->next = node; //���Ž�ǰ�����ָ���µ�������
		return 1;
	}
}

bool deleteList(Node head, int index) {
	if (index < 1) return 0;
	else {
		while (--index) {
			head = head->next;
			if (head == NULL) return 0;
		}
		if (head->next == NULL) return 0;
		Node tmp = head->next;	//���õ���ɾ�����
		head->next = head->next->next;	//ֱ����ǰ���ڵ�ָ����һ��������һ���ڵ�
		free(tmp);		//���ʹ��free�����ͷŵ���ɾ�������ڴ�
		return 1;
	}
}

E getList(Node head, int index) {
	if (index < 1) return NULL;   //���С��0�ǿ϶����Ϸ�������NULL
	do {
		head = head->next;  //��Ϊ����ͷ��㣬����ʹ��do-while���
		if (head == NULL) return NULL;  //����Ѿ����������ǿ϶�Ҳ����
	} while (--index);  //����index�ͽ���
	return head->element;
}

int findList(Node head, E element) {
	head = head->next;    //���ߵ���һ�����
	int i = 1;   //������
	while (head) {
		if (head->element == element) return i;   //����ҵ�����ô�ͷ���i
		head = head->next;   //û�ҵ��ͼ������
		i++;   //i��סҪ����
	}
	return -1;   //���Ѿ��ߵ�����β���ˣ���ô��ȷʵû�ҵ��ˣ�����-1
}

int sizeList(Node head) {
	int i = 0;  //��0��ʼ
	while (head->next) {   //�����һ��ΪNULL�Ǿ�ֹͣ
		head = head->next;
		i++;   //ÿ�����һ����+1
	}
	return i;
}

void printList(Node head) {
	Node current = head->next; //��Ϊͷ��㲻������ݣ��ӵ�һ��ʵ�ʽڵ㿪ʼ��ӡ
	while (current != NULL) {
		printf("%d ", current->element);
		current = current->next;
	}
	printf("\n");
}

int main() {
	struct ListNode head; //���ﴴ��һ���µ�ͷ��㣬ͷ��㲻����κ�Ԫ�أ�ֻ�����ӣ�������������
	initList(&head); //�Ƚ��г�ʼ��
	for (int i = 0; i < 3; ++i) {
		insertList(&head, i * 100, i + 1); //���β���3��Ԫ��
	}
	printList(&head); //��ӡһ�¿���
	deleteList(&head, 1);//����ɾ����һ��Ԫ��
	printList(&head);
	printf("%d\n",getList(&head, 1));
	printf("%d\n", findList(&head, 200));
	printf("%d\n", findList(&head, 300));
	printf("%d\n", sizeList(&head));
}
*/