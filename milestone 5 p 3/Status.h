/* Citation and Sources...
Final Project Milestone 53
Module: Status
Filename: Status.h
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
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>
using namespace std;
namespace sdds {
	class Status {
		char* description=nullptr;
		int code=0;
	public:
		Status& clear();
		Status();
		Status(const char* descr);
		~Status();
		Status(const Status& status);
		Status& operator=(const Status& status);
		Status& operator=(const int c);
		Status& operator=(const char* d);
		operator int() const;
		operator const char*() const;
		operator bool() const;
		ostream& print(ostream& ostr) const;
	};
	ostream& operator<<(ostream& ostr, const Status& status);
}
#endif