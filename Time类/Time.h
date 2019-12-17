#ifndef TIME_H
#define TIME_H
#include <string>
/*Time��,�������á�����ʱ���Լ���ȡ����ʱ�������*/ 

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
		int year; /*��*/
		int month; /*��*/
		int date; /*��*/
		int hour; /*ʱ*/
		int minute; /*��*/
		int second; /*��*/ 
		void calculate(long long);		
};

#endif
