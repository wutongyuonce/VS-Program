#include "data.h"
#include "menu.h"
#include "func.h"

//主菜单
int MainMenu()
{
	printf("\t\t\t *******************************\n");
	printf("\t\t\t *      车站汽车票查询系统     *\n");
	printf("\t\t\t *******************************\n");
	printf("\t\t\t *作者：张桐瑀 学号：2322040216*\n");
	printf("\t\t\t *******************************\n");
	printf("\t\t\t *            主菜单           *\n");
	printf("\t\t\t *******************************\n");
	printf("\t\t\t *            1.查询           *\n");
	printf("\t\t\t *                             *\n");
	printf("\t\t\t *            2.排列           *\n");
	printf("\t\t\t *                             *\n");
	printf("\t\t\t *            3.统计           *\n");
	printf("\t\t\t *                             *\n");
	printf("\t\t\t *            4.增加           *\n");
	printf("\t\t\t *                             *\n");
	printf("\t\t\t *            5.删除           *\n");
	printf("\t\t\t *                             *\n");
	printf("\t\t\t *            0.退出           *\n");
	printf("\t\t\t *                             *\n");
	printf("\t\t\t *******************************\n");
	int sel=0;	
	printf("--------请选择0~5:\n");
	scanf_s("%d", &sel);
	return sel;
}

//子菜单1
int SubMenu1()
{
	printf("\t\t\t *         1.按车次查询        *\n");
	printf("\t\t\t *         2.按到达站查询      *\n");
	printf("\t\t\t *         3.显示所有车票      *\n");
	int sel=0;
	printf("--------请选择1~3:\n");
	scanf_s("%d", &sel);
	return sel;
}

//子菜单2
int SubMenu2()
{
	printf("\t\t\t *         1.按发车时间排序    *\n");
	printf("\t\t\t *         2.按车票价格排序    *\n");
	int sel=0;
	printf("--------请选择1~2:\n");
	scanf_s("%d", &sel);
	return sel;
}