#ifndef Dates
#define Dates
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;
	
public:
//constractors
	Date();//empty constractor
	Date(int day, int month, int year);//constractor with 3 arguments
	Date(const Date& other);//copy constractor
	
//operators
	bool operator ==(const Date &o)const;//operator == ,return true if the Date and the other Date are the same Date
	bool operator <(const Date &o)const;//operator < ,return true if the date is older than the other date
	friend istream& operator >>(istream& is, Date& d)throw(char*);
	const Date& operator=(const Date& other);//opertor = 
    friend ostream& operator<<(ostream& out, const Date& D);
//metods
	void setDate(int d, int m, int y = 2020)throw(char*);	//init date
	int getday()const { return day; }
	int getmonth() const { return month; }
    int getyear() const { return year; }
	~Date();////not realy need it
	
};

#endif //dates
//look at this
