#include <iostream>
using namespace std;

// ����������ṹ
struct Node {
    int data;     // �����򣨼���Ϊint���ͣ�
    Node* next;   // ָ����
    Node(int val) : data(val), next(nullptr) {}
};

// ������ͷ���ĵ�����
Node* createLinkedList() {
    Node* head = new Node(-1);  // ͷ��㣨�ڱ���㣩
    Node* tail = head;          // βָ��

    cout << "����������Ԫ�ظ�����";
    int n;
    cin >> n;

    cout << "������" << n << "��Ԫ�أ�" << endl;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        tail->next = new Node(val);  // β�������½��
        tail = tail->next;           // ����βָ��
    }
    return head;
}

// ���Ҳ����ָ��ֵ�Ľ��
void searchAndPrint(Node* head, int target) {
    Node* current = head->next;  // �ӵ�һ����Ч��㿪ʼ
    int position = 1;            // ���λ�ü�����
    bool found = false;

    while (current != nullptr) {
        if (current->data == target) {
            cout << "�ҵ�Ŀ��ֵ " << target
                << "��λ�ڵ�" << position << "�����"
                << "���ڴ��ַ��0x" << current << endl;
            found = true;
        }
        current = current->next;
        ++position;
    }

    if (!found) {
        cout << "δ�ҵ�ֵΪ " << target << " �Ľ��" << endl;
    }
}

// �ͷ������ڴ�
void freeLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    // ������ͷ��������
    Node* list = createLinkedList();

    // ��ȡ����Ŀ��ֵ
    cout << "\n������Ҫ���ҵ�����ֵ��";
    int target;
    cin >> target;

    // ִ�в��Ҳ�������
    searchAndPrint(list, target);

    // �ͷ��ڴ�
    freeLinkedList(list);

    return 0;
}
