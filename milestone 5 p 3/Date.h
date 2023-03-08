/* Citation and Sources...
Final Project Milestone 53
Module: Date
Filename: Date.h
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
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Status.h"
using namespace std;
namespace sdds {
	const int maxYear = 2030;
	class Date
	{
		int year;
		int month;
		int day;
		Status stateofd;
		bool format=true;
		bool validate();
		int unique();
	public:
		Date();
		Date(const int y, const int m, const int d);
		bool operator==(Date& d);
		bool operator!=(Date& d);
		bool operator<(Date& d);
		bool operator>(Date& d);
		bool operator<=(Date& d);
		bool operator>=(Date& d);
		const Status& state();
		Date& formatted(bool ans);
		operator bool() const;
		ostream& write(ostream& ostr = cout)const;
		istream& read(istream& istr);
	};
	istream& operator>>(istream& istr, Date& dates);
	ostream& operator<<(ostream& ostr, const Date& dates);
}
#endif
