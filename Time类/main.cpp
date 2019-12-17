/**************************************************
@Copyright: Infor Secur Lab
@Author: Wayne 
@Date: 2019-12-16
@Description: Time���ʹ���� 
***************************************************/
#include<iostream>
#include "Time.h"
using namespace std;
int main()
{
/*���쵱ǰʱ��ʵ������� */ 
	Time time1; 
	cout << "Now at: " << endl;
	cout << time1.toString() << " " << time1.getWeek() << endl << endl; //�������ʱ�估���� 
	
/*����ָ���������1970-01-01 00��00��00��ʼ������ָ�����ʵ������� */ 
	cout << "Input a gap(seconds) from 1970-01-01 00:00:00: ";
	int gap;
	cin >> gap; //����ָ�����ʱ�� 
	Time time2(gap); 
	cout << gap << " seconds after 1970-01-01 00:00:00 is :" << endl;
	cout << time2.toString() << " " << time1.getWeek() << endl << endl;
	
/*����ָ����ʱ���룬����ʱ��ʵ���������շ��룩�����*/ 
	cout << "Input a hour, minute and second: ";
	int hour,minute,second;
	cin >> hour >> minute >> second;
	Time time3(hour, minute, second);
	cout << "The time is: " << endl;
	cout << (hour >= 10 ? "" : "0") << time3.getHour() << ":" << (minute >= 10 ? "" : "0") << time3.getMinute() << ":" 
	<< (second >= 10 ? "" : "0")<< time3.getSecond() << endl << endl;
/*ʹ������ʱ��Ϊ����,�����������������һ���µ�ʱ��*/ 
	cout << "Set a time elapse from now(seconds): ";
	int elapseTime;
	cin >> elapseTime;
	Time time4;
	time4.setTime(elapseTime);
	cout << elapseTime << " seconds from noe is:" << endl;
	cout << time4.toString() << " " << time1.getWeek() << endl << endl;
}
