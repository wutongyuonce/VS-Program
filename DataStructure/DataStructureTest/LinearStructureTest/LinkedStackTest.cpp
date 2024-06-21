/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct ListNode {
    E element;
    struct ListNode* next;
};

typedef struct ListNode* Node;

void initStack(Node head) {
    head->next = NULL;
}

bool pushStack(Node head, E element) {
    Node node = (Node)(malloc(sizeof(struct ListNode)));   //�����µĽ��
    if (node == NULL) return 0;   //ʧ�ܾͷ���0
    node->next = head->next;   //����ǰ������һ���趨Ϊͷ������һ��
    node->element = element;   //����Ԫ��
    head->next = node;   //��ͷ������һ���趨Ϊ��ǰ���
    return 1;
}

bool isEmpty(Node head) {
    return head->next == NULL;   //�ж�ջ�Ƿ�Ϊ��ֻ��Ҫ��ͷ�����һ���Ƿ�ΪNULL����
}

E popStack(Node head) {
    Node top = head->next;
    head->next = head->next->next;
    E e = top->element;
    free(top);  //�������ͷŽ����ڴ�
    return e;   //���س�ջԪ��
}

void printStack(Node head) {
    printf("| ");
    head = head->next;
    while (head) {
        printf("%d ", head->element);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct ListNode head;
    initStack(&head);
    for (int i = 0; i < 3; ++i) {
        pushStack(&head, i * 100);
    }
    printStack(&head);
    while (!isEmpty(&head)) {
        printf("%d ", popStack(&head));   //��ջ������Ԫ�����γ�ջ
    }
}
*/