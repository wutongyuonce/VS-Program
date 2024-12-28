#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "menu.h"
#include "func.h"

//从文件中读取车票信息
void ReadfromFile(DATA data[]) 
{
	FILE* fp;
	int i=0;
	if ((fopen_s(&fp, "DATA.txt", "r")) != 0)
	{
		printf("Failure to open DATA.txt!\n");
		exit(0);
	}
	while (fscanf(fp, "%s %s %s %s %lf %d %d %d %d",
		data[i].startcity, data[i].reachcity, data[i].trainNum, data[i].ticketrank,
		&data[i].price, &data[i].starttime.hour, &data[i].starttime.minute,
		&data[i].reachtime.hour, &data[i].reachtime.minute) == 9)
	{
		if (data[i++].startcity[0] == '\0') {
			break; // 如果起始城市为空，退出循环
		}
	}
	fclose(fp); // 关闭文件
}

//按车次查询车票
void QueryTrainNum(DATA data[], String Num)
{
	int i;
	for (i = 0;i < 50;i++)
	{
		if (strcmp(data[i].trainNum, Num) == 0)
		{
			printf("起点:%s,终点:%s,车次:%s,等级:%s,票价:%.2f,开始时间:%02d时%02d分，到达时间:%02d时%02d分", 
				data[i].startcity, data[i].reachcity, data[i].trainNum, data[i].ticketrank, 
				data[i].price, data[i].starttime.hour, data[i].starttime.minute, data[i].reachtime.hour, data[i].reachtime.minute);
			return 0;
		}
	}
	printf("无该车次车票！");
}

//按到达城市查询车票
void QueryTrainRcity(DATA data[], String Rcity)
{
	int i;
	for (i = 0;i < 50;i++)
	{
		if (strcmp(data[i].reachcity, Rcity) == 0)
		{
			printf("起点:%s,终点:%s,车次:%s,等级:%s,票价:%.2f,开始时间:%02d时%02d分，到达时间:%02d时%02d分\n", 
				data[i].startcity, data[i].reachcity, data[i].trainNum, data[i].ticketrank, 
				data[i].price, data[i].starttime.hour, data[i].starttime.minute, data[i].reachtime.hour, data[i].reachtime.minute);
			return 0;
		}
	}
	printf("无该到达城市车票！");
}

//输出读取后的信息
void ShowAll(DATA data[],int TicketNumber)
{
	int i;
	for (i = 0; i < TicketNumber ; i++) {
		printf("起点:%s\t,终点:%s\t,车次:%s\t,等级:%s\t,票价:%.2f\t,发车时间:%02d时%02d分\t，到达时间:%02d时%02d分\t\n", 
			data[i].startcity, data[i].reachcity, data[i].trainNum, data[i].ticketrank, 
			data[i].price, data[i].starttime.hour, data[i].starttime.minute, data[i].reachtime.hour, data[i].reachtime.minute);
	}
}

//按发车时间由先到后排序
void SortbyTime(DATA data[],int TicketNumber)
{
	int i, j, k;
	DATA temp1;
	for (i = 0;i < TicketNumber-1;i++)
	{
		k = i;
		for (j = i + 1;j < TicketNumber;j++)
		{
			if (data[j].starttime.hour < data[k].starttime.hour ||
				(data[j].starttime.hour == data[k].starttime.hour && data[j].starttime.minute <= data[k].starttime.minute))
			{
				k = j;
			}	
		}
		if (k != i)
			{
				temp1 = data[k];
				data[k] = data[i];
				data[i] = temp1;
			}					
	}
	ShowAll(data,TicketNumber);
}

//按车票价格由低到高排序
void SortbyPrice(DATA data[],int TicketNumber)
{
	int i, j, k;
	DATA temp1;
	for (i = 0;i < TicketNumber - 1;i++)
	{
		k = i;
		for (j = i + 1;j < TicketNumber;j++)
		{
			if (data[j].price < data[k].price)
			{
				k = j;
			}
		}
		if (k != i)
		{
			temp1 = data[k];
			data[k] = data[i];
			data[i] = temp1;
		}
	}
	ShowAll(data,TicketNumber);
}

//按到达城市统计
void Count(DATA data[],int TicketNumber)
{
	//先统计一共有几个到达城市，分别是哪里
    int num=0;
    DATA data2[50];
    for (int i = 0; i < TicketNumber; i++) 
    {
        int duplicate = 0;
        for (int j = 0; j < num; j++)
        {
            if (strcmp(data[i].reachcity, data2[j].reachcity) == 0) {
                duplicate = 1;
                break;
            }
        }
        if (duplicate == 0) {
            strcpy(data2[num].reachcity, data[i].reachcity);
            num++;
        }        
    }
	//再按城市统计车票数量，占车票总数的比例
    for (int p = 0; p < num; p++) 
    {
        int COUNT = 0;
        float PERCENT = 0.0;
        printf("到达城市为%s的车票\n", data2[p].reachcity);
        for (int q = 0; q < TicketNumber; q++)
        {
            if (strcmp(data[q].reachcity, data2[p].reachcity) == 0) {
                COUNT += 1;
                // Output ticket information
                printf("起点:%s\t,终点:%s\t,车次:%s\t,等级:%s\t,票价:%.2f\t,发车时间:%02d时%02d分，到达时间:%02d时%02d分\n",
                    data[q].startcity, data[q].reachcity, data[q].trainNum, data[q].ticketrank,
                    data[q].price, data[q].starttime.hour, data[q].starttime.minute, data[q].reachtime.hour, data[q].reachtime.minute);
            }   
        }
        PERCENT = ((float)COUNT / (float)TicketNumber) * 100;
        printf("车票共有%d张,占总数比例为%.2f%%\n", COUNT, PERCENT);
    }
}

void AddTicket(DATA data[],int TicketNumber)
{
	if (TicketNumber >= 50) {
		printf("车票数量已经达到上限，无法添加更多车票");
		return;
	}
	printf("请输入新车票的起点城市：");
	scanf_s("%s", data[TicketNumber].startcity,100);
	printf("请输入新车票的到达城市：");
	scanf_s("%s", data[TicketNumber].reachcity,100);
	printf("请输入新车票的车次：");
	scanf_s("%s", data[TicketNumber].trainNum,100);
	printf("请输入新车票的等级（例如‘FirstClass’）：");
	scanf_s("%s", data[TicketNumber].ticketrank,100);
	printf("请输入新车票的票价：");
	scanf_s("%lf", &data[TicketNumber].price);
	printf("请输入新车票的发车时间（时 分）：");
	scanf_s("%d %d", &data[TicketNumber].starttime.hour, &data[TicketNumber].starttime.minute);
	printf("请输入新车票的到达时间（时 分）：");
	scanf_s("%d %d", &data[TicketNumber].reachtime.hour, &data[TicketNumber].reachtime.minute);
	TicketNumber++;  // 增加车票数量
	printf("车票添加成功！");
	FILE* fp;
	if ((fopen_s(&fp, "C:\\temp\\VS\\Program\\Train_System\\data.txt", "a")) != 0) {
		printf("失败：无法打开data.txt文件进行写入！\n");
		return;
	}
	fprintf(fp, "%s %s %s %s %.2f %d %d %d %d\n",
		data[TicketNumber - 1].startcity, data[TicketNumber - 1].reachcity, data[TicketNumber - 1].trainNum,
		data[TicketNumber - 1].ticketrank, data[TicketNumber - 1].price,
		data[TicketNumber - 1].starttime.hour, data[TicketNumber - 1].starttime.minute,
		data[TicketNumber- 1].reachtime.hour, data[TicketNumber - 1].reachtime.minute);
	fclose(fp);
}

void DeleteTicket(DATA data[],int TicketNumber)
{
	int i;
	char trainNum[10];
	printf("请输入要删除的车票的车次：");
	scanf_s("%9s", trainNum,sizeof(trainNum));

	FILE* fp;
	if ((fopen_s(&fp, "C:\\temp\\VS\\Program\\Train_System\\data.txt", "w")) != 0) {
		printf("失败：无法打开data.txt文件进行写入！\n");
		return;
	}
	for (i = 0; i < TicketNumber; i++) {
		if (strcmp(data[i].trainNum, trainNum) == 0) {
			// 将最后一个车票覆盖到要删除的位置
			data[i] = data[TicketNumber - 1];
			printf("车票删除成功！");
		}
	}	
	for (int i = 0; i < TicketNumber-1; i++) {
		fprintf(fp, "%s %s %s %s %.2f %d %d %d %d\n",
			data[i].startcity, data[i].reachcity, data[i].trainNum, data[i].ticketrank,
			data[i].price, data[i].starttime.hour, data[i].starttime.minute,
			data[i].reachtime.hour, data[i].reachtime.minute);
	}
	fclose(fp);
}