#pragma once
typedef char String[50];


//时间结点
typedef struct TimeNode
{
	int hour;          //时
	int minute;        //分
}Time;

//火车信息
typedef struct TrainTicket
{
	String startcity;        //起点
	String reachcity;        //终点
	String trainNum;         //车次
	String ticketrank;		 //座位等级	
	double price;            //票价	
	Time starttime;      //开始时间
	Time reachtime;      //到达时间
}DATA;