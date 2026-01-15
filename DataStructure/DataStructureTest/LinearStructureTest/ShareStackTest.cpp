/*
#include <stdio.h>
#include <stdbool.h>

#define  MaxSize 10	//定义共享栈中元素的最大个数
#define ElemType int

typedef struct {
	ElemType data[MaxSize];		//静态数组存放栈中元素
	int top1;		//1号栈栈顶指针
	int top2;		//2号栈栈顶指针
}ShStack;

void InitShStack(ShStack& S) {
	S.top1 = -1;		//初始化1号栈栈顶指针
	S.top2 = MaxSize;	//初始化2号栈栈顶指针
}

bool isStack1Empty(ShStack S) { 
	return (S.top1 == -1); 
}

bool isStack2Empty(ShStack S) {
	return (S.top2 == MaxSize);
}

bool Push1(ShStack& S, ElemType x) {
	if (S.top1 + 1 == S.top2)		//栈满，报错
		return false;
	S.data[++S.top1] = x;
	return true;
}

bool Push2(ShStack& S, ElemType x) {
	if (S.top1 + 1 == S.top2)		//栈满，报错
		return false;
	S.data[--S.top2] = x;
	return true;
}

ElemType Pop1(ShStack& S) {
	if (S.top1 == -1)	//1号栈栈空，报错
		return NULL;
	ElemType x = S.data[S.top1--];
	return x;
}

ElemType Pop2(ShStack& S) {
	if (S.top2 == MaxSize)	//2号栈栈空，报错
		return NULL;
	ElemType x = S.data[S.top2++];
	return x;
}

ElemType GetTop1(ShStack S) {
	if (S.top1 == -1)	//1号栈栈空，报错
		return NULL;
	ElemType x = S.data[S.top1];
	return x;
}

ElemType GetTop2(ShStack S) {
	if (S.top2 == MaxSize)	//2号栈栈空，报错
		return NULL;
	ElemType x = S.data[S.top2];
	return x;
}

int main() {
	ShStack S;		//声明一个共享栈(分配内存空间)
	//1、初始化共享栈
	InitShStack(S);
	//2、1号栈-判空
	if (isStack1Empty(S))
		printf("当前1号栈空！\n");
	else
		printf("当前1号栈非空！\n");
	//3、1号栈-入栈操作
	ElemType e1,e2,e3;
	printf("请输入1号栈入栈元素的值：");
	scanf_s("%d", &e1);
	printf("请输入2号栈入栈元素的值：");
	scanf_s("%d", &e2);
	printf("请输入3号栈入栈元素的值：");
	scanf_s("%d", &e3);
	if (Push1(S, e1)&&Push1(S,e2)&&Push1(S,e3))
		printf("1号栈新元素入栈成功！\n");
	else
		printf("共享栈已满,1号栈新元素入栈失败！\n");
	//4、1号栈-读取栈顶元素
	if (GetTop1(S)!=NULL)
		printf("1号栈读取栈顶元素成功，当前栈顶元素值为：%d\n", GetTop1(S));
	else
		printf("1号栈已空，读取栈顶元素失败！\n");
	//5、1号栈-出栈操作
	if (Pop1(S)!=NULL)
		printf("1号栈栈顶元素出栈成功，出栈元素值为：%d\n", e3);
	else
		printf("1号栈已空，栈顶元素出栈失败！\n");
	//6、1号栈-读取栈顶元素
	if (GetTop1(S) != NULL)
		printf("1号栈读取栈顶元素成功，当前栈顶元素值为：%d\n", GetTop1(S));
	else
		printf("1号栈已空，读取栈顶元素失败！\n");
	//7、2号栈-判空
	if (isStack2Empty(S))
		printf("当前2号栈空！\n");
	else
		printf("当前2号栈非空！\n");
	//8、2号栈-入栈操作
	ElemType e21,e22,e23;
	printf("请输入2号栈入栈元素1的值：");
	scanf_s("%d", &e21);
	printf("请输入2号栈入栈元素2的值：");
	scanf_s("%d", &e22);
	printf("请输入2号栈入栈元素3的值：");
	scanf_s("%d", &e23);
	if (Push2(S, e21)&& Push2(S, e22)&& Push2(S, e23))
		printf("2号栈新元素入栈成功！\n");
	else
		printf("共享栈已满,2号栈新元素入栈失败！\n");
	//9、2号栈-读取栈顶元素
	if (GetTop2(S)!=NULL)
		printf("2号栈读取栈顶元素成功，当前栈顶元素值为：%d\n", GetTop2(S));
	else
		printf("2号栈已空，读取栈顶元素失败！\n");
	//10、2号栈-出栈操作
	if (Pop2(S)!=NULL)
		printf("2号栈栈顶元素出栈成功，出栈元素值为：%d\n", Pop2(S));
	else
		printf("2号栈已空，栈顶元素出栈失败！\n");
	//11、2号栈-读取栈顶元素
	if (GetTop2(S)!=NULL)
		printf("2号栈读取栈顶元素成功，当前栈顶元素值为：%d\n", GetTop2(S));
	else
		printf("2号栈已空，读取栈顶元素失败！\n");
	return 0;
}
*/
