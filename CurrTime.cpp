#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<iostream>
#include<fstream> 
#include<string>
#include<time.h>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>

using namespace std;

#include"CurrTime.h"
#include "Account.h"
#include "StockNode.h"

void currtime::calculate(){

	time_t  now = time(0);
	tm *local = localtime(&now);
	cout << "\nYear" << local->tm_year;
	cout << "\nMonth" << local->tm_mon;
	cout << "\nDay" << local->tm_mday;
	cout << "\nTime: " << local->tm_hour<<":"<<local->tm_min<<":"<<local->tm_sec<<endl;



	time_t rawtime;
	struct tm timeinfo;
	char buffer[80];
time(&rawtime);
localtime_s(&timeinfo, &rawtime);
strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", &timeinfo);
std::string str(buffer);

}
