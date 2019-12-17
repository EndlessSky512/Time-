/**************************************************
@Copyright: Infor Secur Lab
@Author: Wayne 
@Date: 2019-12-16
@Description: Time类的使用例 
***************************************************/
#include<iostream>
#include "Time.h"
using namespace std;
int main()
{
/*构造当前时间实例并输出 */ 
	Time time1; 
	cout << "Now at: " << endl;
	cout << time1.toString() << " " << time1.getWeek() << endl << endl; //输出日期时间及星期 
	
/*输入指定间隔（从1970-01-01 00：00：00开始）构造指定间隔实例并输出 */ 
	cout << "Input a gap(seconds) from 1970-01-01 00:00:00: ";
	int gap;
	cin >> gap; //输入指定间隔时间 
	Time time2(gap); 
	cout << gap << " seconds after 1970-01-01 00:00:00 is :" << endl;
	cout << time2.toString() << " " << time1.getWeek() << endl << endl;
	
/*输入指定的时分秒，构造时间实例（不含日分秒）并输出*/ 
	cout << "Input a hour, minute and second: ";
	int hour,minute,second;
	cin >> hour >> minute >> second;
	Time time3(hour, minute, second);
	cout << "The time is: " << endl;
	cout << (hour >= 10 ? "" : "0") << time3.getHour() << ":" << (minute >= 10 ? "" : "0") << time3.getMinute() << ":" 
	<< (second >= 10 ? "" : "0")<< time3.getSecond() << endl << endl;
/*使用运行时间为对象,根据输入的秒数设置一个新的时间*/ 
	cout << "Set a time elapse from now(seconds): ";
	int elapseTime;
	cin >> elapseTime;
	Time time4;
	time4.setTime(elapseTime);
	cout << elapseTime << " seconds from noe is:" << endl;
	cout << time4.toString() << " " << time1.getWeek() << endl << endl;
}
