#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void QueryTrainNum(DATA data[],String Num);
void QueryTrainRcity(DATA data[], String Rcity);
void ShowAll(DATA data[],int TicketNumber);
void SortbyTime(DATA data[],int TicketNumber);
void SortbyPrice(DATA data[],int TicketNumber);
void Count(DATA data[],int TicketNumber);
void AddTicket(DATA data[],int TicketNumber);
void DeleteTicket(DATA data[],int TicketNumber);