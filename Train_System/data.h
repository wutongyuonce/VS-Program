#pragma once
typedef char String[50];


//ʱ����
typedef struct TimeNode
{
	int hour;          //ʱ
	int minute;        //��
}Time;

//����Ϣ
typedef struct TrainTicket
{
	String startcity;        //���
	String reachcity;        //�յ�
	String trainNum;         //����
	String ticketrank;		 //��λ�ȼ�	
	double price;            //Ʊ��	
	Time starttime;      //��ʼʱ��
	Time reachtime;      //����ʱ��
}DATA;