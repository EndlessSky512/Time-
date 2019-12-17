#include "Time.h"
#include <ctime>

/*************************************************
Function:  calculate(long long seconds) 
Description: ���ݾ���1970-01-01 00��00��00���ŵ���������ʱ�� 
Input: seconds���ŵ����� 
Output: NULL
Return: NULL
Others: ˽�к�����ֻ�����ڲ���������ʵ�ֵ��� 
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
Description: Ϊ��ǰʱ�䴴��ʱ�������޲������캯��
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
Description: ��ָ����ʱ����(��1970��1��1����ҹ��ʼ)����Ϊ��λ����ʱ�����
Input: gap����ָ��ʱ������ȡֵ��Χ-2^31~2^31-1 
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
Description: ��ָ����Сʱ�����Ӻ��빹��ʱ�����
Input: hour,minute,second�ֱ�����ָ��ʱ���룬ȡֵ��Χ24 >= hour >= 0, 60 >= minute >= 0, 60 >= second >= 0
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
Description: ��ȡ�����Сʱ 
Input: NULL
Output: NULL
Return: ���ش����Сʱ 
Others: NULL
*************************************************/
int Time::getHour()
{
	return hour; 
}
/*************************************************
Function:  getMinute()
Description: ��ȡ����ķ��� 
Input: NULL
Output: NULL
Return: ���ش���ķ��� 
Others: NULL
*************************************************/
int Time::getMinute()
{
	return minute;
}
/*************************************************
Function:  getSecond()
Description: ��ȡ������� 
Input: NULL
Output: NULL
Return: ���ش������ 
Others: NULL
*************************************************/
int Time::getSecond()
{
	return second; 
}
/*************************************************
Function:  setTime(int elapseTime)
Description: ʹ������ʱ��Ϊ��������һ���µ�ʱ��
Input: elapseTime����ʱ������ŵ�ʱ�� 
Output: NULL
Return: ����һ��Time�����ʱ�� 
Others: NULL
*************************************************/
void Time::setTime(int elapseTime)
{
	calculate(elapseTime + time(0));
}
/*************************************************
Function:  toString()
Description: ����ǰ�����ʱ�䰴��yyyy-mm-dd hh:mm:ss����ʽ����
Input: NULL
Output: NULL
Return: ����yyyy-mm-dd hh:mm:ss��ʽ��string�ַ��� 
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
Description: ����ǰ�����ʱ������ڷ���
Input: NULL
Output: NULL
Return: �������ڵ�string�ַ��� 
Others: NULL
*************************************************/
std::string Time::getWeek()
{
	std::string days[] = {"Sunday","Monday","Tuesday","Wendsday","Thursday","Friday","Saturday"};
	int m = (month >= 3) ? month : month + 12; //���չ�ʽ��1��2�¿�����һ��13��14�� 
	int w = ((year / 100) / 4) - 2 * (year / 100) + (year % 100) + (year % 100) / 4 + (13 * (m + 1) / 5) + date - 1;//���գ�Zeller����ʽ �������� 
	w %= 7;
	return days[w]; 
}
