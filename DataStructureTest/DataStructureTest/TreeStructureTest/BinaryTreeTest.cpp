/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char E;

struct TreeNode {
    E element;    //���Ԫ��
    struct TreeNode* left;   //ָ����������ָ��
    struct TreeNode* right;   //ָ����������ָ��
};

typedef struct TreeNode* Node;

int main() {
    Node a = (Node)(malloc(sizeof(struct TreeNode)));   //���δ�������������
    Node b = (Node)(malloc(sizeof(struct TreeNode)));
    Node c = (Node)(malloc(sizeof(struct TreeNode)));
    Node d = (Node)(malloc(sizeof(struct TreeNode)));
    Node e = (Node)(malloc(sizeof(struct TreeNode)));
    if (a && b && c && d && e) {
        a->element = 'A';
        b->element = 'B';
        c->element = 'C';
        d->element = 'D';
        e->element = 'E';
        a->left = b;   //A��������B
        a->right = c;   //A���Һ�����C
        b->left = d;   //B��������D
        b->right = e;   //B���Һ�����E
        //�����˰������Ľ���ΪNULL
        c->left = NULL;
        c->right = NULL;
        d->left = NULL;
        d->right = NULL;
        e->left = NULL;
        e->right = NULL;
    }
    printf("%c", a->left->left->element);
}
*/