/* Citation and Sources...
Final Project Milestone 56
Module: Perishable
Filename: Perishable.cpp
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
#include <fstream>
#include <string>
#include <iomanip>
#include "Perishable.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	Perishable::Perishable()  {
		sku = 0;
		instructions = nullptr;
	}
	Perishable::Perishable(Perishable& p) {
		*this = p;
	}
	Perishable& Perishable::operator=(Perishable& p) {
		Item::operator=(p);
		sku = p.sku;
		expiryDate = p.expiryDate;
		ut.alocpy(instructions, p.instructions);
		return *this;
	}
	Perishable::~Perishable() {
		delete[] instructions;
		instructions = nullptr;
	}
	const Date& Perishable::expiry() const {
		return expiryDate;
	}
	int Perishable::readSku(istream& istr) {
		int num = 0;
		cout << "SKU: ";
		do
		{
			istr >> num;
			if (istr.peek() == '\n')
			{
				if ((num >= 10000 && num <= 39999))
				{
					SKU = num;
				}
				else
				{
					cout << "Value out of range [10000<=val<=39999]: ";
				}
			}
			else
			{

				cout << "Invalid Integer, retry: ";
			}
			istr.clear();
			istr.ignore(1000, '\n');
		} while (num < 10000 || num>39999);
		return num;
	}
	ofstream& Perishable::save(std::ofstream& ofstr) {
		if (*this)
		{
			Item::save(ofstr);
			ofstr << '\t';
			if (instructions!=nullptr && strcmp(instructions,"")!=0)
			{
				ofstr << instructions ;
			}
			ofstr<< '\t';
			expiryDate.formatted(false);
			ofstr << expiryDate;
		}
		return ofstr;
	}
	ifstream& Perishable::load(std::ifstream& ifstr) {
		Item::load(ifstr);
		string temp;
		delete[] instructions;
		instructions = nullptr;
		if (ifstr.peek()!='2')
		{
			getline(ifstr, temp, '\t');
			ut.alocpy(instructions, temp.c_str());
		}
		ifstr >> expiryDate;
		ifstr.ignore(1000, '\n');
		if (ifstr.fail())
		{
			state = "Input file stream read (perishable) failed!";
		}
		return ifstr;
	}
	ostream& Perishable::display(std::ostream& ostr) {
		if (!(*this))
		{
			ostr << state.operator const char* ();
		}
		else
		{
			if (linear())
			{
				Item::display(ostr);
				if (instructions!=nullptr&& strlen(instructions)>0)
				{
					ostr << "*";
				}
				else
				{
					ostr << " ";
				}
				ostr << expiryDate;
				
			}
			else
			{
				ostr << "Perishable ";
				Item::display(ostr);
				expiryDate.formatted(true);
				ostr << "Expiry date: " << expiryDate << endl;
				if (instructions != nullptr && strcmp(instructions, "") != 0)
				{
					ostr << "Handling Instructions: " << instructions<< endl;
				}
			}
		}
		return ostr;
	}
	istream& Perishable::read(std::istream& istr) {
		Item::read(istr);
		delete[] instructions;
		instructions = nullptr;
		char temp[500];
		cout << "Expiry date (YYMMDD): ";
		istr >> expiryDate;
		istr.ignore(1000, '\n');
		cout << "Handling Instructions, ENTER to skip: ";
		if (istr.peek()!='\n')
		{
			istr.get(temp,1000);
			ut.alocpy(instructions, temp);
		}
		if (istr.fail()) {
			state = "Console entry failed!";
		}
		return istr;
	}
	Perishable::operator bool() const {
		bool ans = false;
		if (this->SKU!=0)
		{
			ans = true;
		}
		return ans;
	}
}