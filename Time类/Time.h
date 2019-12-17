#ifndef TIME_H
#define TIME_H
#include <string>
/*Time类,用于设置、储存时间以及获取储存时间的星期*/ 

class Time
{
	public:
		Time();
		Time(int);
		Time(int, int, int);
		int getHour();
		int getMinute();
		int getSecond();
		void setTime(int);
		std::string toString();
		std::string getWeek();
	private:
		int year; /*年*/
		int month; /*月*/
		int date; /*日*/
		int hour; /*时*/
		int minute; /*分*/
		int second; /*秒*/ 
		void calculate(long long);		
};

#endif
