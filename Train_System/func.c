#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "menu.h"
#include "func.h"

//���ļ��ж�ȡ��Ʊ��Ϣ
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
			break; // �����ʼ����Ϊ�գ��˳�ѭ��
		}
	}
	fclose(fp); // �ر��ļ�
}

//�����β�ѯ��Ʊ
void QueryTrainNum(DATA data[], String Num)
{
	int i;
	for (i = 0;i < 50;i++)
	{
		if (strcmp(data[i].trainNum, Num) == 0)
		{
			printf("���:%s,�յ�:%s,����:%s,�ȼ�:%s,Ʊ��:%.2f,��ʼʱ��:%02dʱ%02d�֣�����ʱ��:%02dʱ%02d��", 
				data[i].startcity, data[i].reachcity, data[i].trainNum, data[i].ticketrank, 
				data[i].price, data[i].starttime.hour, data[i].starttime.minute, data[i].reachtime.hour, data[i].reachtime.minute);
			return 0;
		}
	}
	printf("�޸ó��γ�Ʊ��");
}

//��������в�ѯ��Ʊ
void QueryTrainRcity(DATA data[], String Rcity)
{
	int i;
	for (i = 0;i < 50;i++)
	{
		if (strcmp(data[i].reachcity, Rcity) == 0)
		{
			printf("���:%s,�յ�:%s,����:%s,�ȼ�:%s,Ʊ��:%.2f,��ʼʱ��:%02dʱ%02d�֣�����ʱ��:%02dʱ%02d��\n", 
				data[i].startcity, data[i].reachcity, data[i].trainNum, data[i].ticketrank, 
				data[i].price, data[i].starttime.hour, data[i].starttime.minute, data[i].reachtime.hour, data[i].reachtime.minute);
			return 0;
		}
	}
	printf("�޸õ�����г�Ʊ��");
}

//�����ȡ�����Ϣ
void ShowAll(DATA data[],int TicketNumber)
{
	int i;
	for (i = 0; i < TicketNumber ; i++) {
		printf("���:%s\t,�յ�:%s\t,����:%s\t,�ȼ�:%s\t,Ʊ��:%.2f\t,����ʱ��:%02dʱ%02d��\t������ʱ��:%02dʱ%02d��\t\n", 
			data[i].startcity, data[i].reachcity, data[i].trainNum, data[i].ticketrank, 
			data[i].price, data[i].starttime.hour, data[i].starttime.minute, data[i].reachtime.hour, data[i].reachtime.minute);
	}
}

//������ʱ�����ȵ�������
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

//����Ʊ�۸��ɵ͵�������
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

//���������ͳ��
void Count(DATA data[],int TicketNumber)
{
	//��ͳ��һ���м���������У��ֱ�������
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
	//�ٰ�����ͳ�Ƴ�Ʊ������ռ��Ʊ�����ı���
    for (int p = 0; p < num; p++) 
    {
        int COUNT = 0;
        float PERCENT = 0.0;
        printf("�������Ϊ%s�ĳ�Ʊ\n", data2[p].reachcity);
        for (int q = 0; q < TicketNumber; q++)
        {
            if (strcmp(data[q].reachcity, data2[p].reachcity) == 0) {
                COUNT += 1;
                // Output ticket information
                printf("���:%s\t,�յ�:%s\t,����:%s\t,�ȼ�:%s\t,Ʊ��:%.2f\t,����ʱ��:%02dʱ%02d�֣�����ʱ��:%02dʱ%02d��\n",
                    data[q].startcity, data[q].reachcity, data[q].trainNum, data[q].ticketrank,
                    data[q].price, data[q].starttime.hour, data[q].starttime.minute, data[q].reachtime.hour, data[q].reachtime.minute);
            }   
        }
        PERCENT = ((float)COUNT / (float)TicketNumber) * 100;
        printf("��Ʊ����%d��,ռ��������Ϊ%.2f%%\n", COUNT, PERCENT);
    }
}

void AddTicket(DATA data[],int TicketNumber)
{
	if (TicketNumber >= 50) {
		printf("��Ʊ�����Ѿ��ﵽ���ޣ��޷���Ӹ��೵Ʊ");
		return;
	}
	printf("�������³�Ʊ�������У�");
	scanf_s("%s", data[TicketNumber].startcity,100);
	printf("�������³�Ʊ�ĵ�����У�");
	scanf_s("%s", data[TicketNumber].reachcity,100);
	printf("�������³�Ʊ�ĳ��Σ�");
	scanf_s("%s", data[TicketNumber].trainNum,100);
	printf("�������³�Ʊ�ĵȼ������确FirstClass������");
	scanf_s("%s", data[TicketNumber].ticketrank,100);
	printf("�������³�Ʊ��Ʊ�ۣ�");
	scanf_s("%lf", &data[TicketNumber].price);
	printf("�������³�Ʊ�ķ���ʱ�䣨ʱ �֣���");
	scanf_s("%d %d", &data[TicketNumber].starttime.hour, &data[TicketNumber].starttime.minute);
	printf("�������³�Ʊ�ĵ���ʱ�䣨ʱ �֣���");
	scanf_s("%d %d", &data[TicketNumber].reachtime.hour, &data[TicketNumber].reachtime.minute);
	TicketNumber++;  // ���ӳ�Ʊ����
	printf("��Ʊ��ӳɹ���");
	FILE* fp;
	if ((fopen_s(&fp, "C:\\temp\\VS\\Program\\Train_System\\data.txt", "a")) != 0) {
		printf("ʧ�ܣ��޷���data.txt�ļ�����д�룡\n");
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
	printf("������Ҫɾ���ĳ�Ʊ�ĳ��Σ�");
	scanf_s("%9s", trainNum,sizeof(trainNum));

	FILE* fp;
	if ((fopen_s(&fp, "C:\\temp\\VS\\Program\\Train_System\\data.txt", "w")) != 0) {
		printf("ʧ�ܣ��޷���data.txt�ļ�����д�룡\n");
		return;
	}
	for (i = 0; i < TicketNumber; i++) {
		if (strcmp(data[i].trainNum, trainNum) == 0) {
			// �����һ����Ʊ���ǵ�Ҫɾ����λ��
			data[i] = data[TicketNumber - 1];
			printf("��Ʊɾ���ɹ���");
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