#include <iostream>
using namespace std;

// 定义链表结点结构
struct Node {
    int data;     // 数据域（假设为int类型）
    Node* next;   // 指针域
    Node(int val) : data(val), next(nullptr) {}
};

// 创建带头结点的单链表
Node* createLinkedList() {
    Node* head = new Node(-1);  // 头结点（哨兵结点）
    Node* tail = head;          // 尾指针

    cout << "请输入链表元素个数：";
    int n;
    cin >> n;

    cout << "请输入" << n << "个元素：" << endl;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        tail->next = new Node(val);  // 尾部插入新结点
        tail = tail->next;           // 更新尾指针
    }
    return head;
}

// 查找并输出指定值的结点
void searchAndPrint(Node* head, int target) {
    Node* current = head->next;  // 从第一个有效结点开始
    int position = 1;            // 结点位置计数器
    bool found = false;

    while (current != nullptr) {
        if (current->data == target) {
            cout << "找到目标值 " << target
                << "，位于第" << position << "个结点"
                << "，内存地址：0x" << current << endl;
            found = true;
        }
        current = current->next;
        ++position;
    }

    if (!found) {
        cout << "未找到值为 " << target << " 的结点" << endl;
    }
}

// 释放链表内存
void freeLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    // 创建带头结点的链表
    Node* list = createLinkedList();

    // 获取查找目标值
    cout << "\n请输入要查找的整数值：";
    int target;
    cin >> target;

    // 执行查找并输出结果
    searchAndPrint(list, target);

    // 释放内存
    freeLinkedList(list);

    return 0;
}
