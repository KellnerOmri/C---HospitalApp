#include "Date.h"

Date::Date()
{
	setDate(1, 1, 2020);
	
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(const Date& other) //copy constractor
{
	*this = other;
}

void Date::setDate(int d, int m, int y)throw( char*) //init date
{
	if (d <= 0 || d > 31 || m <= 0 || m > 12|| y > 2020 || y < 1900)
	{ 	
	this->day = 1;
	this->month = 1;
	this->year = 2020;
	throw "Invalid date,defult date 1/1/2020";
    }
	this->day = d;
	this->month = m;
	this->year = y;
}

Date::~Date()//not realy need it
{
}

const Date& Date::operator=(const Date& other)//opertor =
{
	if (this != &other)
	{
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}

	return *this;
}

bool Date::operator ==(const Date &o)const//operator == ,return true if the Date and the other Date are the same Date
{

	if ((this->day == o.day) && (this->month == o.month) && (this->year == o.year))
		return 1;
	return 0;

}

bool Date::operator<(const Date & o) const //operator < ,return true if the date is older than the other date
{
	if (this->year < o.year)
		return false;
	else if (this->year > o.year)
		return true;
	else//the year is equal!
	{
		if (this->month < o.month)
			return false;
		else if (this->month > o.month)
			return true;
		else//the month is equal!
		{
			if (this->day < o.day)
				return false;
			else if (this->day > o.day)
				return true;
			else//the day is equal!
				return false;
		}
	}
}



ostream& operator<<(ostream& out, const Date& D)
{
	out << D.day << '/' << D.month << '/' << D.year;
	return out;
}

istream& operator >>(istream& is, Date& d)throw(char*)
{
	
	int day, month, year;
	char ch1, ch2;
	string test;
	is >> skipws >> day >> ch1 >> month >> ch2 >> year;//cheak the input dd/mm/yyyy
	if (!is) {
		is.clear(ios_base::failbit);
		return is;
	}
	d.setDate(day, month, year);
	return is;
}