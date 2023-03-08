/* Citation and Sources...
Final Project Milestone 1
Module: Status
Filename: Status.cpp
Version 1.0
Author	Name   :Pawan Deep
		ID     :111144218
		Email  :pdeep1@myseneca.ca
		Date   :03/10/2022
Revision History
-----------------------------------------------------------
Date      Reason
03/10/2022  Preliminary release
03/10/2022  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Status.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	Status::Status() {
		description=nullptr;
		code = 0;
	}
	Status::Status(const char* descr) {
		code = 0;
		if (descr!=nullptr)
		{
			ut.alocpy(description, descr);
		}
	}
	Status::~Status() {
		delete[] description;
		description = nullptr;
	}
	Status::Status(const Status& status) {
		*this = status;
	}
	Status& Status::operator=(const Status& status) {
		if (status.description!=nullptr)
		{
			code = status.code;
			ut.alocpy(description, status.description);
		}
		else
		{
			code = 0;
			description = nullptr;
		}
		return *this;
	}
	Status& Status::operator=(const int c){
		code = c;
		return *this;
	}
	Status& Status::operator=(const char* d) {
		if (d!=nullptr)
		{
			ut.alocpy(description, d);
		}

		return *this;
	}
	Status::operator int() const {
		return code;
	}
	Status::operator const char* () const {
		return description;
	}
	Status::operator bool() const {
		bool ans = true;
		if (description!=nullptr)
		{
			ans = false;
		}
		return ans;
	}
	Status& Status::clear() {
		delete[] description;
		description = nullptr;
		code = 0;
		return *this;
	}
	ostream& Status::print(ostream& ostr) const {
		if (code!=0)
		{
			ostr << "ERR#" << code << ": ";
		}
		ostr << description;
		return ostr;
	}
	ostream& operator<<(ostream& ostr, const Status& status) {
		if (status.operator bool()==false)
		{
			status.print(ostr);
		}
		return ostr;
	}
}