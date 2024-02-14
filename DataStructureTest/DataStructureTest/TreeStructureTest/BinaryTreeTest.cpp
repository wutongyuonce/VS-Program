/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char E;

struct TreeNode {
    E element;    //存放元素
    struct TreeNode* left;   //指向左子树的指针
    struct TreeNode* right;   //指向右子树的指针
};

typedef struct TreeNode* Node;

int main() {
    Node a = (Node)(malloc(sizeof(struct TreeNode)));   //依次创建好这五个结点
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
        a->left = b;   //A的左孩子是B
        a->right = c;   //A的右孩子是C
        b->left = d;   //B的左孩子是D
        b->right = e;   //B的右孩子是E
        //别忘了把其他的结点改为NULL
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