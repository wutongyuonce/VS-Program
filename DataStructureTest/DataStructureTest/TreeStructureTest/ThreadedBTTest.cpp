#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char E;

/*
typedef struct TreeNode {
    E element;
    struct TreeNode* left;
    struct TreeNode* right;
    int leftTag, rightTag;   //��־λ��leftTagΪ0ʱָ��ý������ӣ�Ϊ1ʱָ��ý���ǰ����rightTagΪ0ʱָ��ý����Һ��ӣ�Ϊ1ʱָ��ý��ĺ��
} *Node;
*/
typedef struct TreeNode {
    E element;
    struct TreeNode* left;
    struct TreeNode* right;
    struct TreeNode* parent;   //ָ��˫�ף��������
    int leftTag, rightTag;
} *Node;

Node createNode(E element) {   //����д�˸��������������
    Node node = (Node)(malloc(sizeof(struct TreeNode)));
    node->left = node->right = NULL;
    node->rightTag = node->leftTag = 0;
    node->element = element;
    return node;
}

Node pre = NULL;  //����������Ҫһ��pre�������������ָ��
/*
void preOrderThreaded(Node root) {   //ǰ���������������
    if (root == NULL) return;

    //------  ������ -------
    if (root->left == NULL) {   //�����жϵ�ǰ�������Ƿ�ΪNULL������ǣ���ôָ����һ�����
        root->left = pre;
        root->leftTag = 1;  //�ǵ��޸ı��
    }
    if (pre && pre->right == NULL) {  //Ȼ�����ж���һ�������ұ��Ƿ�ΪNULL���������ô������������ָ��ǰ���
        pre->right = root;
        pre->rightTag = 1;  //�ǵ��޸ı��
    }

    pre = root;   //ÿ������һ������Ҫ����һ��pre����ʾ��һ�������Ľ��
    //--------------------

    if (root->leftTag == 0)   //ע��ֻ�б�־λ��0�ſ��Լ������£��������������
        preOrderThreaded(root->left);
    if (root->rightTag == 0)
        preOrderThreaded(root->right);
}
*/

/*
void inOrderThreaded(Node root) {   //ǰ���������������
    if (root == NULL) return;
    if (root->leftTag == 0)
        inOrderThreaded(root->left);

    //------  ������ -------  ���ڷŵ��м�ȥ�������Ļ���һ����
    if (root->left == NULL) {
        root->left = pre;	//���ڳ�ʼ��preΪNULL��������������ĵ�һ���ڵ��root->leftָ�����NULL����root->leftTag��Ϊ1
        root->leftTag = 1;
    }
    if (pre && pre->right == NULL) {
        pre->right = root;
        pre->rightTag = 1;
    }
    pre = root;
    //--------------------

    if (root->rightTag == 0)
        inOrderThreaded(root->right);
}
*/

void postOrderThreaded(Node root) {   //ǰ���������������
    if (root == NULL) return;
    if (root->leftTag == 0) {
        postOrderThreaded(root->left);
        if (root->left) root->left->parent = root;  //�������֮�������Ϊ�գ���ô���趨���ӹ�ϵ
    }
    if (root->rightTag == 0) {
        postOrderThreaded(root->right);
        if (root->right) root->right->parent = root;   //�ұ�����֮�������Ϊ�գ���ô���趨���ӹ�ϵ
    }
    //------  ������ -------
    if (root->left == NULL) {
        root->left = pre;
        root->leftTag = 1;
    }
    if (pre && pre->right == NULL) {
        pre->right = root;
        pre->rightTag = 1;
    }
    pre = root;
    //--------------------
}

/*
void preOrder(Node root) {  //ǰ�����һ���������������ǳ���
    while (root) {   //��ͷΪֹ
        printf("%c", root->element);   //��Ϊ��ǰ�����������ֱ�Ӱ�˳���ӡ������
        if (root->leftTag == 0)
            root = root->left;   //��������ӣ���ô�������
        else
            root = root->right;   //������ָ��Ĳ��Ǻ��ӣ�������������ô��ֱ�����ұߣ���Ϊ�ұ��������������Ǻ��ӣ���Ҫ���������
    }
}
*/

/*
void inOrder(Node root) {
    while (root) {   //��Ϊ���������Ҫ�������ߣ�����˵Ҫ���ߵ�����߲���
        while (root && root->leftTag == 0)    //������һֱ��������������ô��һֱ�����ң�ֱ���ҵ�һ�������������Ϊֹ����ʾ��ͷ��
            root = root->left;

        printf("%c", root->element);   //����������ٴ�ӡ������ʼ

        while (root && root->rightTag == 1) {   //��ӡ��͸��ұ��ˣ��ұ������������֮��Ľ������ʾ����һ����㣬��ô��һ·��ǰ��ֱ������Ϊֹ
            root = root->right;
            printf("%c", root->element);   //ע�ⰴ���������¾�������Ľ��������˵��;��Ҫ��ӡ
        }
        root = root->right;  //���������ҽ�㿪ʼ���ظ���������
    }
}
*/

void postOrder(Node root) {
    Node last = NULL, node = root;  //������Ҫ�����ݴ�ָ�룬һ����¼��һ�α����Ľ�㣬����һ����root��ʼ
    while (node) {
        while (node->left != last && node->leftTag == 0)    //��Ȼ�Ǵ�����������߽�㿪ʼ����ǰ��һ����ֻ������������˷�����ѭ�����ƣ����������֪����
            node = node->left;
        while (node && node->rightTag == 1) {   //������˻����ұߣ�����ұ�����������ôֱ��һ·��ǰ��Ҳ�Ǹ�ǰ��һ����
            printf("%c", node->element);   //��;��ӡ
            last = node;
            node = node->right;
        }
        if (node == root && node->right == last) {
            //����Ĳ������֮����ô��ǰ������Ҿͽ����ˣ���ʱ��ҪȥѰ�����ֵܽ���ˣ����ǿ���
            //ֱ��ͨ��parent�õ��ֵܽ�㣬���������ǰ����Ǹ���㣬��Ҫ���⴦����Ϊ�����û�и������
            printf("%c", node->element);
            return;   //���ڵ�һ�������һ��������˵ֱ�ӷ��ؾ�����
        }
        while (node && node->right == last) {    //�����ǰ�����Һ��Ӿ�����һ�������Ľ�㣬��ôһֱ��ǰ����
            printf("%c", node->element);   //ֱ�Ӵ�ӡ��ǰ���
            last = node;
            node = node->parent;
        }
        //������ֻ��һ������ˣ��Ǵ������������ģ���ô��ǰ�����ұ�Ҫô������Ҫô��������������ֱ�����Ҿ�����
        if (node && node->rightTag == 0) {  //��������������Ǿ������ұߣ�����ǣ��ȵ���һ����˵
            node = node->right;
        }
    }
}

int main() {
    Node a = createNode('A');
    Node b = createNode('B');
    Node c = createNode('C');
    Node d = createNode('D');
    Node e = createNode('E');

    a->left = b;
    b->left = d;
    a->right = c;
    b->right = e;
    //preOrderThreaded(a);
    //preOrder(a);
    //inOrderThreaded(a);
    //inOrder(a);
    postOrderThreaded(a);
    postOrder(a);
}