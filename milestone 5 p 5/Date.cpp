/* Citation and Sources...
Final Project Milestone 55
Module: Date
Filename: Date.cpp
Version 1.0
Author	Name   :Pawan Deep
		ID     :111144218
		Email  :pdeep1@myseneca.ca
		Date   :04/05/2022
Revision History
-----------------------------------------------------------
Date      Reason
04/05/2022  Preliminary release
04/05/2022  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Date.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	bool Date::validate() {
		int minyear;
		ut.getSystemDate(&minyear);
		if (year<minyear || year> maxYear)
		{
			stateofd = "Invalid year in date";
			stateofd = 1;
		}
		else if (month<1||month>12)
		{
			stateofd = "Invalid month in date";
			stateofd = 2;
		}
		else if (day<1||day>ut.daysOfMon(month, year))
		{
			stateofd = "Invalid day in date";
			stateofd = 3;
		}
		else
		{
			stateofd.clear();
			return true;
		}
		return false;
	}
	int Date::unique() {
		return year * 372 + month * 31 + day;
	}
	Date::Date() {
		ut.getSystemDate(&year, &month, &day);
	}
	Date::Date(const int y, const int m, const int d) {
		if (y && m && d)
		{
			year = y;
			month = m;
			day = d;
			validate();
		}
	}
	bool Date::operator==(Date& d) {
		if (this->unique()==d.unique())
		{
			return true;
		}
		return false;
	}
	bool Date::operator!=(Date& d) {
		if (this->unique() != d.unique())
		{
			return true;
		}
		return false;
	}
	bool Date::operator<(Date& d) {
		if (this->unique() < d.unique())
		{
			return true;
		}
		return false;
	}
	bool Date::operator>(Date& d) {
		if (this->unique() > d.unique())
		{
			return true;
		}
		return false;
	}
	bool Date::operator<=(Date& d) {
		if (this->unique() <= d.unique())
		{
			return true;
		}
		return false;
	}
	bool Date::operator>=(Date& d) {
		if (this->unique() >= d.unique())
		{
			return true;
		}
		return false;
	}
	const Status& Date::state() {
		return stateofd;
	}
	Date& Date::formatted(bool ans) {
		this->format = ans;
		return *this;
	}
	Date::operator bool() const {

		return stateofd.operator bool();
	
	}
	ostream& Date::write(ostream& ostr)const {
		if (format==true)
		{
			ostr << year << "/";
			if (month<10)
			{
				ostr << "0" << month << "/";
			}
			else
			{
				ostr << month << "/";
			}
			if (day<10)
			{
				ostr << "0" << day;
			}
			else
			{
				ostr << day;
			}
		}
		else
		{
			ostr << year - 2000;
			if (month < 10)
			{
				ostr << "0" << month ;
			}
			else
			{
				ostr << month;
			}
			if (day < 10)
			{
				ostr << "0" << day;
			}
			else
			{
				ostr << day;
			}
		}
		return ostr;
	}
	istream& Date::read(istream& istr) {
		int date = 0;
		istr >> date;
		this->stateofd.clear();

		if (date-2000<0 )
		{
			day = date % 100;
			month = (date-day) / 100;
			year = 2022;
		}
		else if(date-2000>0)
		{
			day = date % 100;
			month = (date - day) % 10000/100;
			year = ((date - day) - month * 100) / 10000+2000;
		}
		if (istr.fail())
		{
			istr.setstate(ios::badbit);
		}
		else
		{
			this->validate();
			if (this->validate() == false)
			{
				istr.clear();
				istr.setstate(ios::badbit);
			}
		}
		
		return istr;
	}
	ostream& operator<<(ostream& ostr, const Date& dates) {
		return dates.write(ostr);
	}
	istream& operator>>(istream& istr, Date& dates) {
		return dates.read(istr);
	}

}