/*
#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct TreeNode {
    E element;
    struct TreeNode* left;
    struct TreeNode* right;
} *Node;

Node createNode(E element) {
    Node node = (Node)(malloc(sizeof(struct TreeNode)));
    node->left = node->right = NULL;
    node->element = element;
    return node;
}

Node insert(Node root, E element) {
    if (root) {
        if (root->element > element)    //���������ֵС�ڵ�ǰ��㣬��ô˵��Ӧ�÷ŵ����ȥ
            root->left = insert(root->left, element);
        else if (root->element < element)    //���������ֵ���ڵ�ǰ��㣬��ô˵��Ӧ�÷ŵ��ұ�ȥ
            root->right = insert(root->right, element);
    }
    else {   //�����Ϊ��ʱ��˵���Ѿ��ҵ������λ���ˣ�������Ӧ���
        root = createNode(element);
    }
    return root;   //���ص�ǰ���
}

Node find(Node root, E target) {
    while (root) {
        if (root->element > target)    //���Ҫ�ҵ�ֵ�ȵ�ǰ���С��˵���϶������
            root = root->left;
        else if (root->element < target)   //���Ҫ�ҵ�ֵ�ȵ�ǰ����˵���϶����ұ�
            root = root->right;
        else
            return root;   //���ڵĻ���˵���ҵ��ˣ���ֱ�ӷ���
    }
    return NULL;   //���ҵ����˻�û�У��Ǿ�����û����
}

Node findMax(Node root) {   //�������ֵ�͸����ˣ����ұߵ�һ��������
    while (root && root->right)
        root = root->right;
    return root;
}

Node deleteNode(Node root, E target) {
    if (root == NULL) return NULL;   //���ߵ����˻���û���ҵ�Ҫɾ���Ľ�㣬˵��û�У�ֱ�ӷ��ؿ�
    if (root->element > target)   //������жϸ�֮ǰ������һ���ģ����������Ҿ����£�ֱ���ҵ�Ϊֹ
        root->left = deleteNode(root->left, target);
    else if (root->element < target)
        root->right = deleteNode(root->right, target);
    else {   //������������ҵ���
        if (root->left && root->right) {   //�ȴ������鷳�����Һ��Ӷ��е����
            Node max = findMax(root->left);  //Ѱ��������������Ԫ��
            root->element = max->element;  //�ҵ���ֵ�滻
            root->left = deleteNode(root->left, root->element);  //�滻�ú���ͬ���ķ�ʽȥɾ���Ǹ��滻�����Ľ��
        }
        else {   //���������������һ����ֻ��Ҫɾ����������У�Ȼ��rootָ��Ϊ����һ�����ӣ���󷵻ؾ�����
            Node tmp = root;
            if (root->right) {   //������߾����ұ�
                root = root->right;
            }
            else {
                root = root->left;
            }
            free(tmp);   //��ɾ
        }
    }
    return root;   //�������յĽ��
}

void inOrder(Node root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->element);
    inOrder(root->right);
}

int main() {
    Node root = insert(NULL, 18);   //����󣬵õ������
    insert(root, 10);
    insert(root, 20);
    insert(root, 7);
    insert(root, 15);
    insert(root, 22);
    insert(root, 9);

    inOrder(root);
    printf("\n");
    printf("%p\n", find(root, 17));
    printf("%p\n", find(root, 9));
    deleteNode(root, 20);
    inOrder(root);
}
*/