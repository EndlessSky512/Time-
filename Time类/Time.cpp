#include "Time.h"
#include <ctime>

/*************************************************
Function:  calculate(long long seconds) 
Description: 根据距离1970-01-01 00：00：00流逝的秒数计算时间 
Input: seconds流逝的秒数 
Output: NULL
Return: NULL
Others: 私有函数，只用于内部函数功能实现调用 
*************************************************/
void Time::calculate(long long seconds)
{
	long long total = seconds; 
	second = total % 60;
	minute = (total % 3600) / 60;
	hour = (total % (3600*24)) / 3600 + 8;
	year = 1970;
	month = date = 1;
	while(total >= 365 * 24 * 60 * 60)
	{
		bool leap = (year % 4 == 0 && year % 100 !=0) || (year % 400 == 0);
		total -= leap ? 366 * 24 * 60 * 60 : 365 * 24 * 60 * 60 ;
		year += 1;
	}
	while(total >= 86400)
	{
		bool leap = (year % 4 == 0 && year % 100 !=0) || (year % 400 == 0);
		total -= 86400;
		date ++;
		if(leap && (month == 2) && (date == 29))
			{
				month++;
				date = 0;
			}
		else if((month == 2) && (date == 28))
			{
				month++;
				date = 0;	
			}
		else if((month == 4 || (month == 6) || (month == 9) || (month == 11)) && date == 30)
			{
				month++;
				date = 0;
			}
		else if(date == 31)
			{
				month++;
				date = 0;
			 } 
	}
}
/*************************************************
Function:  Time() 
Description: 为当前时间创建时间对象的无参数构造函数
Input: NULL
Output: NULL
Return: NULL
Others: NULL
*************************************************/
Time::Time()
{
	calculate(time(0));
}
/*************************************************
Function:  Time(int gap) 
Description: 用指定的时间间隔(从1970年1月1日午夜开始)以秒为单位构造时间对象
Input: gap用于指定时间间隔，取值范围-2^31~2^31-1 
Output: NULL
Return: NULL
Others: NULL
*************************************************/
Time::Time(int gap)
{
	calculate(gap);
}
/*************************************************
Function:  Time(int newHour, int newMinute, int newSecond)
Description: 用指定的小时、分钟和秒构造时间对象
Input: hour,minute,second分别用于指定时分秒，取值范围24 >= hour >= 0, 60 >= minute >= 0, 60 >= second >= 0
Output: NULL
Return: NULL
Others: NULL
*************************************************/
Time::Time(int newHour, int newMinute, int newSecond)
{
	hour = (newHour >= 0 && newHour <= 24) ? newHour : 0; 
	minute = (newMinute >= 0 && newMinute <= 60) ? newMinute : 0; 
	second = (newSecond >= 0 && newSecond <= 60) ? newSecond : 0; 
}
/*************************************************
Function:  getHour()
Description: 获取储存的小时 
Input: NULL
Output: NULL
Return: 返回储存的小时 
Others: NULL
*************************************************/
int Time::getHour()
{
	return hour; 
}
/*************************************************
Function:  getMinute()
Description: 获取储存的分钟 
Input: NULL
Output: NULL
Return: 返回储存的分钟 
Others: NULL
*************************************************/
int Time::getMinute()
{
	return minute;
}
/*************************************************
Function:  getSecond()
Description: 获取储存的秒 
Input: NULL
Output: NULL
Return: 返回储存的秒 
Others: NULL
*************************************************/
int Time::getSecond()
{
	return second; 
}
/*************************************************
Function:  setTime(int elapseTime)
Description: 使用运行时间为对象设置一个新的时间
Input: elapseTime运行时间后流逝的时间 
Output: NULL
Return: 返回一个Time类的新时间 
Others: NULL
*************************************************/
void Time::setTime(int elapseTime)
{
	calculate(elapseTime + time(0));
}
/*************************************************
Function:  toString()
Description: 将当前储存的时间按照yyyy-mm-dd hh:mm:ss的形式返回
Input: NULL
Output: NULL
Return: 返回yyyy-mm-dd hh:mm:ss形式的string字符串 
Others: NULL
*************************************************/
std::string Time::toString()
{
	std::string time;
	time = std::to_string(year) + "-" + (month >= 10 ? "" : "0") + std::to_string(month)+ "-" + (date >= 10 ?  "" : "0") + std::to_string(date) 
	+ " " + (hour >= 10 ? "" : "0") + std::to_string(hour) + ":" + (minute >= 10 ? "" : "0") + std::to_string(minute) + ":" + (second >= 10 ? "" : "0") + std::to_string(second);
	return time;
}
/*************************************************
Function:  getWeek()
Description: 将当前储存的时间的星期返回
Input: NULL
Output: NULL
Return: 返回星期的string字符串 
Others: NULL
*************************************************/
std::string Time::getWeek()
{
	std::string days[] = {"Sunday","Monday","Tuesday","Wendsday","Thursday","Friday","Saturday"};
	int m = (month >= 3) ? month : month + 12; //蔡勒公式中1月2月看作上一年13月14月 
	int w = ((year / 100) / 4) - 2 * (year / 100) + (year % 100) + (year % 100) / 4 + (13 * (m + 1) / 5) + date - 1;//蔡勒（Zeller）公式 计算日期 
	w %= 7;
	return days[w]; 
}
