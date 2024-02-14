/*
#include <stdio.h>
#include <stdbool.h>

#define  MaxSize 10	//���干��ջ��Ԫ�ص�������
#define ElemType int

typedef struct {
	ElemType data[MaxSize];		//��̬������ջ��Ԫ��
	int top1;		//1��ջջ��ָ��
	int top2;		//2��ջջ��ָ��
}ShStack;

void InitShStack(ShStack& S) {
	S.top1 = -1;		//��ʼ��1��ջջ��ָ��
	S.top2 = MaxSize;	//��ʼ��2��ջջ��ָ��
}

bool isStack1Empty(ShStack S) { 
	return (S.top1 == -1); 
}

bool isStack2Empty(ShStack S) {
	return (S.top2 == MaxSize);
}

bool Push1(ShStack& S, ElemType x) {
	if (S.top1 + 1 == S.top2)		//ջ��������
		return false;
	S.data[++S.top1] = x;
	return true;
}

bool Push2(ShStack& S, ElemType x) {
	if (S.top1 + 1 == S.top2)		//ջ��������
		return false;
	S.data[--S.top2] = x;
	return true;
}

ElemType Pop1(ShStack& S) {
	if (S.top1 == -1)	//1��ջջ�գ�����
		return NULL;
	ElemType x = S.data[S.top1--];
	return x;
}

ElemType Pop2(ShStack& S) {
	if (S.top2 == MaxSize)	//2��ջջ�գ�����
		return NULL;
	ElemType x = S.data[S.top2++];
	return x;
}

ElemType GetTop1(ShStack S) {
	if (S.top1 == -1)	//1��ջջ�գ�����
		return NULL;
	ElemType x = S.data[S.top1];
	return x;
}

ElemType GetTop2(ShStack S) {
	if (S.top2 == MaxSize)	//2��ջջ�գ�����
		return NULL;
	ElemType x = S.data[S.top2];
	return x;
}

int main() {
	ShStack S;		//����һ������ջ(�����ڴ�ռ�)
	//1����ʼ������ջ
	InitShStack(S);
	//2��1��ջ-�п�
	if (isStack1Empty(S))
		printf("��ǰ1��ջ�գ�\n");
	else
		printf("��ǰ1��ջ�ǿգ�\n");
	//3��1��ջ-��ջ����
	ElemType e1,e2,e3;
	printf("������1��ջ��ջԪ�ص�ֵ��");
	scanf_s("%d", &e1);
	printf("������2��ջ��ջԪ�ص�ֵ��");
	scanf_s("%d", &e2);
	printf("������3��ջ��ջԪ�ص�ֵ��");
	scanf_s("%d", &e3);
	if (Push1(S, e1)&&Push1(S,e2)&&Push1(S,e3))
		printf("1��ջ��Ԫ����ջ�ɹ���\n");
	else
		printf("����ջ����,1��ջ��Ԫ����ջʧ�ܣ�\n");
	//4��1��ջ-��ȡջ��Ԫ��
	if (GetTop1(S)!=NULL)
		printf("1��ջ��ȡջ��Ԫ�سɹ�����ǰջ��Ԫ��ֵΪ��%d\n", GetTop1(S));
	else
		printf("1��ջ�ѿգ���ȡջ��Ԫ��ʧ�ܣ�\n");
	//5��1��ջ-��ջ����
	if (Pop1(S)!=NULL)
		printf("1��ջջ��Ԫ�س�ջ�ɹ�����ջԪ��ֵΪ��%d\n", e3);
	else
		printf("1��ջ�ѿգ�ջ��Ԫ�س�ջʧ�ܣ�\n");
	//6��1��ջ-��ȡջ��Ԫ��
	if (GetTop1(S) != NULL)
		printf("1��ջ��ȡջ��Ԫ�سɹ�����ǰջ��Ԫ��ֵΪ��%d\n", GetTop1(S));
	else
		printf("1��ջ�ѿգ���ȡջ��Ԫ��ʧ�ܣ�\n");
	//7��2��ջ-�п�
	if (isStack2Empty(S))
		printf("��ǰ2��ջ�գ�\n");
	else
		printf("��ǰ2��ջ�ǿգ�\n");
	//8��2��ջ-��ջ����
	ElemType e21,e22,e23;
	printf("������2��ջ��ջԪ��1��ֵ��");
	scanf_s("%d", &e21);
	printf("������2��ջ��ջԪ��2��ֵ��");
	scanf_s("%d", &e22);
	printf("������2��ջ��ջԪ��3��ֵ��");
	scanf_s("%d", &e23);
	if (Push2(S, e21)&& Push2(S, e22)&& Push2(S, e23))
		printf("2��ջ��Ԫ����ջ�ɹ���\n");
	else
		printf("����ջ����,2��ջ��Ԫ����ջʧ�ܣ�\n");
	//9��2��ջ-��ȡջ��Ԫ��
	if (GetTop2(S)!=NULL)
		printf("2��ջ��ȡջ��Ԫ�سɹ�����ǰջ��Ԫ��ֵΪ��%d\n", GetTop2(S));
	else
		printf("2��ջ�ѿգ���ȡջ��Ԫ��ʧ�ܣ�\n");
	//10��2��ջ-��ջ����
	if (Pop2(S)!=NULL)
		printf("2��ջջ��Ԫ�س�ջ�ɹ�����ջԪ��ֵΪ��%d\n", Pop2(S));
	else
		printf("2��ջ�ѿգ�ջ��Ԫ�س�ջʧ�ܣ�\n");
	//11��2��ջ-��ȡջ��Ԫ��
	if (GetTop2(S)!=NULL)
		printf("2��ջ��ȡջ��Ԫ�سɹ�����ǰջ��Ԫ��ֵΪ��%d\n", GetTop2(S));
	else
		printf("2��ջ�ѿգ���ȡջ��Ԫ��ʧ�ܣ�\n");
	return 0;
}
*/
