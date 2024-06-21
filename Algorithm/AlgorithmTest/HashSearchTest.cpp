#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

typedef struct Element {   //������һ��Element��ֵ��װһ��
    int key;    //����Ԫ���趨Ϊint
} *E;

typedef struct HTable {   //����������װΪһ����ϣ��
    E* table;
} *HashTable;

int hash(int key) {   //��ϣ����
    return key % SIZE;
}

void init(HashTable hashTable) {   //��ʼ������
    hashTable->table = (E*)(malloc(sizeof(struct Element) * SIZE));
    for (int i = 0; i < SIZE; ++i)
        hashTable->table[i] = NULL;
}

void insert(HashTable hashTable, E element) {   //���������Ϊ�˷���Ͳ�����װ���������
    int hashCode = hash(element->key);   //���ȼ���Ԫ�صĹ�ϣֵ
    hashTable->table[hashCode] = element;   //�Ժ�����
}

bool find(HashTable hashTable, int key) {
    int hashCode = hash(key);   //���ȼ���Ԫ�صĹ�ϣֵ
    if (!hashTable->table[hashCode]) return 0;   //���ΪNULL�Ǿ�˵��û��
    return hashTable->table[hashCode]->key == key;  //����У�ֱ�ӿ��ǲ��Ǿ�����
}

E create(int key) {    //����һ���µ�Ԫ��
    E e = (E)(malloc(sizeof(struct Element)));
    e->key = key;
    return e;
}

int main() {
    struct HTable hashTable;
    init(&hashTable);
    insert(&hashTable, create(10));
    insert(&hashTable, create(7));
    insert(&hashTable, create(13));
    insert(&hashTable, create(29));

    printf("%d\n", find(&hashTable, 1));
    printf("%d\n", find(&hashTable, 13));
}