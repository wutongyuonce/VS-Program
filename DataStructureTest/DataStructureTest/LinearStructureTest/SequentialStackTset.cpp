/*
//FILO��first in,last out
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct Stack {
	E* array;
	int capacity;
	int top;	//����ʹ��top����ʾ��ǰ��ջ��λ�ã������ջ��Ԫ�ص��±�
};

typedef struct Stack* SeqStack;

bool initStack(ArrayStack stack) {
	stack->array = (E*)(malloc(sizeof(E) * 10));
	if (stack->array == NULL) return 0;
	stack->capacity = 10;	//��������10
	stack->top = -1;		//����ջ��û��Ԫ�أ���ôջ��Ĭ�Ͼ�Ϊ-1
	return 1;
}

bool pushStack(SeqStack stack, E element) {
	if (stack->top + 1 == stack->capacity) {
		//ջ����1������������Ļ�����ô˵���Ѿ�������
		int newCapacity = stack->capacity + (stack->capacity >> 1);		//���������˳���һ��
		E* newArray = (E*)(realloc(stack->array, newCapacity * sizeof(E)));
		if (newArray == NULL) return 0;
		stack->array = newArray;
		stack->capacity = newCapacity;
	}
	stack->array[stack->top + 1] = element;	//ֱ���趨ջ��Ԫ��
	stack->top++;	//ջ��top�����ǵ�����
	return 1;
}

bool isEmpty(SeqStack stack) {
	//��ջ֮ǰ�����ǻ���Ҫʹ��isEmpty�ж�һ��ջ�Ƿ�Ϊ�գ���ջԪ�ض�û�о������ջ
	return stack->top == -1;
}

E popStack(SeqStack stack) {
	return stack->array[stack->top--];	//ֱ�ӷ���ջ��Ԫ�أ�ע����һ���Լ�����
}

void printStack(SeqStack stack) {
	printf("| ");
	for (int i = 0;i < stack->top + 1;i++) {
		printf("%d, ", stack->array[i]);
	}
	printf("\n");
}

int main() {
	struct Stack stack;
	initStack(&stack);
	for (int i = 0;i < 3;++i) {
		pushStack(&stack, i * 100);
	}
	printStack(&stack);
	while (!isEmpty(&stack)) {
		printf("%d ", popStack(&stack));	//������Ԫ�����γ�ջ
	}
}
*/