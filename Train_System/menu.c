#include "data.h"
#include "menu.h"
#include "func.h"

//���˵�
int MainMenu()
{
	printf("\t\t\t *******************************\n");
	printf("\t\t\t *      ��վ����Ʊ��ѯϵͳ     *\n");
	printf("\t\t\t *******************************\n");
	printf("\t\t\t *���ߣ���ͩ�r ѧ�ţ�2322040216*\n");
	printf("\t\t\t *******************************\n");
	printf("\t\t\t *            ���˵�           *\n");
	printf("\t\t\t *******************************\n");
	printf("\t\t\t *            1.��ѯ           *\n");
	printf("\t\t\t *                             *\n");
	printf("\t\t\t *            2.����           *\n");
	printf("\t\t\t *                             *\n");
	printf("\t\t\t *            3.ͳ��           *\n");
	printf("\t\t\t *                             *\n");
	printf("\t\t\t *            4.����           *\n");
	printf("\t\t\t *                             *\n");
	printf("\t\t\t *            5.ɾ��           *\n");
	printf("\t\t\t *                             *\n");
	printf("\t\t\t *            0.�˳�           *\n");
	printf("\t\t\t *                             *\n");
	printf("\t\t\t *******************************\n");
	int sel=0;	
	printf("--------��ѡ��0~5:\n");
	scanf_s("%d", &sel);
	return sel;
}

//�Ӳ˵�1
int SubMenu1()
{
	printf("\t\t\t *         1.�����β�ѯ        *\n");
	printf("\t\t\t *         2.������վ��ѯ      *\n");
	printf("\t\t\t *         3.��ʾ���г�Ʊ      *\n");
	int sel=0;
	printf("--------��ѡ��1~3:\n");
	scanf_s("%d", &sel);
	return sel;
}

//�Ӳ˵�2
int SubMenu2()
{
	printf("\t\t\t *         1.������ʱ������    *\n");
	printf("\t\t\t *         2.����Ʊ�۸�����    *\n");
	int sel=0;
	printf("--------��ѡ��1~2:\n");
	scanf_s("%d", &sel);
	return sel;
}