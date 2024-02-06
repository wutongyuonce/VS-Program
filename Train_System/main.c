#include "data.h"
#include "menu.h"
#include "func.h"

int main()
{
	int ch, sch1,sch2,out=0,TicketNumber;
	String Num="", Rcity ="";
	DATA data[50];
	ReadfromFile(data);
	system("color F5");
	printf("请输入现有车票数量：");
	scanf_s("%d", &TicketNumber);
	while (1)
	{
		ch = MainMenu();
		switch (ch)
		{
			case 1:
			{
				sch1 = SubMenu1();
				if (sch1 == 1)
				{
					printf("请输入查询车票的车次：");
					scanf_s("%s", Num,10);
					QueryTrainNum(data, Num);
					system("pause");
					system("cls");
				}
				if (sch1 == 2)
				{
					printf("请输入查询车票的到达城市：");
					scanf_s("%s", Rcity,20);
					QueryTrainRcity(data, Rcity);
					system("pause");
					system("cls");
				}
				if (sch1 == 3)
				{
					ShowAll(data,TicketNumber);
					system("pause");
					system("cls");
				}
			}break;
			case 2:
			{
				sch2 = SubMenu2();
				if (sch2 == 1)
				{
					SortbyTime(data,TicketNumber);
					system("pause");
					system("cls");
				}
				if (sch2 == 2)
				{
					SortbyPrice(data,TicketNumber);
					system("pause");
					system("cls");
				}
			}break;
			case 3:
			{
				Count(data,TicketNumber);
				system("pause");
				system("cls");
			}break;
			case 4:
			{
				AddTicket(data,TicketNumber);
				TicketNumber++;
				system("pause");
				system("cls");
			}break;
			case 5:
			{
				DeleteTicket(data,TicketNumber);
				TicketNumber--;
				system("pause");
				system("cls");
			}break;
			case 0:
				out = 1;break;
			default:
			{
				printf("输入错误,请重新输入!\n");
				system("pause");
				system("cls");
			}break;
		}
		if (out) break;
	}
}