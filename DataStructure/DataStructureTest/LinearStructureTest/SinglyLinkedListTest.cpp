/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct ListNode {
	E element; //保存当前元素
	struct ListNode* next; //指向下一个节点的指针
};

typedef ListNode* Node; //这里我们直接为结点指针起别名，可以直接作为表实现

void initList(Node head) {
	head->next = NULL; //头结点默认下一个为NULL
}

bool insertList(Node head, E element, int index) {
	if (index < 1) return 0; //如果插入的位置小于1，那肯定是非法的
	else {
		while (--index) { //通过--index的方式不断向后寻找前驱结点
			head = head->next; //正常情况下继续向后找
			if (head == NULL) return 0;
			//如果在寻找的过程中发型已经没有后续结点了，那么说明index超出可插入的范围了，也是非法的，直接润
		}
		Node node = (Node)(malloc(sizeof(struct ListNode)));
		if (node == NULL) return 0; //创建一个新的结点，如果内存空间申请失败返回0
		node->element = element; //将元素保存到新创建的结点中
		node->next = head->next; //先让新插入的节点指向原本位置上的这个结点
		head->next = node; //接着将前驱结点指向新的这个结点
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
		Node tmp = head->next;	//先拿到待删除结点
		head->next = head->next->next;	//直接让前驱节点指向下一个结点的下一个节点
		free(tmp);		//最后使用free函数释放掉待删除结点的内存
		return 1;
	}
}

E getList(Node head, int index) {
	if (index < 1) return NULL;   //如果小于0那肯定不合法，返回NULL
	do {
		head = head->next;  //因为不算头结点，所以使用do-while语句
		if (head == NULL) return NULL;  //如果已经超出长度那肯定也不行
	} while (--index);  //到达index就结束
	return head->element;
}

int findList(Node head, E element) {
	head = head->next;    //先走到第一个结点
	int i = 1;   //计数器
	while (head) {
		if (head->element == element) return i;   //如果找到，那么就返回i
		head = head->next;   //没找到就继续向后看
		i++;   //i记住要自增
	}
	return -1;   //都已经走到链表尾部了，那么就确实没找到了，返回-1
}

int sizeList(Node head) {
	int i = 0;  //从0开始
	while (head->next) {   //如果下一个为NULL那就停止
		head = head->next;
		i++;   //每向后找一个就+1
	}
	return i;
}

void printList(Node head) {
	Node current = head->next; //因为头结点不存放数据，从第一个实际节点开始打印
	while (current != NULL) {
		printf("%d ", current->element);
		current = current->next;
	}
	printf("\n");
}

int main() {
	struct ListNode head; //这里创建一个新的头结点，头结点不存放任何元素，只做连接，连接整个链表
	initList(&head); //先进行初始化
	for (int i = 0; i < 3; ++i) {
		insertList(&head, i * 100, i + 1); //依次插入3个元素
	}
	printList(&head); //打印一下看看
	deleteList(&head, 1);//尝试删除第一个元素
	printList(&head);
	printf("%d\n",getList(&head, 1));
	printf("%d\n", findList(&head, 200));
	printf("%d\n", findList(&head, 300));
	printf("%d\n", sizeList(&head));
}
*/