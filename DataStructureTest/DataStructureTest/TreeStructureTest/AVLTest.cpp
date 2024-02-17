/*
#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct TreeNode {
    E element;
    struct TreeNode* left;
    struct TreeNode* right;
    int height;   //ÿ�������Ҫ��¼��ǰ�����ĸ߶ȣ����ڼ���ƽ������
} *Node;

Node createNode(E element) {
    Node node = (Node)(malloc(sizeof(struct TreeNode)));
    node->left = node->right = NULL;
    node->element = element;
    node->height = 1;   //��ʼ��ʱ���߶�дΪ1�Ϳ�����
    return node;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int getHeight(Node root) {
    if (root == NULL) return 0;
    return root->height;
}

Node leftRotation(Node root) {  //����������ʵ���Ͼ��ǰ��ұ߽��������
    Node newRoot = root->right;   //�ȵõ��ұ߽��
    root->right = newRoot->left;   //���ұ߽�������������ԭ���������ұ�ȥ
    newRoot->left = root;   //�����µĸ������߾���ԭ���ĸ������

    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    newRoot->height = max(getHeight(newRoot->right), getHeight(newRoot->left)) + 1;
    return newRoot;
}

Node rightRotation(Node root) {
    Node newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    newRoot->height = max(getHeight(newRoot->right), getHeight(newRoot->left)) + 1;
    return newRoot;
}

Node leftRightRotation(Node root) {
    root->left = leftRotation(root->left);
    return rightRotation(root);
}

Node rightLeftRightRotation(Node root) {
    root->right = rightRotation(root->right);
    return leftRotation(root);
}

Node insert(Node root, E element) {
    if (root == NULL) {    //������ΪNULL��˵���ҵ��˲���λ�ã�ֱ�Ӵ����µľ�����
        root = createNode(element);
    }
    else if (root->element > element) {   //�Ͷ���������һ�����жϴ�С�������ı����ıߣ�ֱ���ҵ���Ӧ����λ��
        root->left = insert(root->left, element);
        if (getHeight(root->left) - getHeight(root->right) > 1) {   //�������֮����Ҫ����ƽ�����ӣ������Ƿ�ʧ��
            if (root->left->element > element) //������Ҫ�ж�һ���ǲ���������������߻����ұߣ����������Ǳ�˵����LL��������ұ���˵����LR
                root = rightRotation(root);   //LL�͵õ�����֮��Ľ�����õ��µĸ����
            else
                root = leftRightRotation(root);    //LR�͵õ�������������֮��Ľ�����õ��µĸ����
        }
    }
    else if (root->element < element) {
        root->right = insert(root->right, element);
        if (getHeight(root->left) - getHeight(root->right) < -1) {
            if (root->right->element < element)
                root = leftRotation(root);
            else
                root = rightLeftRightRotation(root);
        }
    }
    //ǰ��Ĳ������֮��ǵø���һ�����߶�
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;  //��󷵻�root����һ��
}

void inOrder(Node root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->element);
    inOrder(root->right);
}

int main() {
    Node root=createNode(3);
    root=insert(root, 5);   //��Ϊinsert������������newRoot��������Ҫ��ǰ���root=���н�
    root=insert(root, 6);
    inOrder(root);
    printf("\n");
    root=insert(root, 15);
    root=insert(root, 25);
    inOrder(root);
}
*/