/* Citation and Sources...
Final Project Milestone 54
Module: Item
Filename: Item.cpp
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
#include <iomanip>
#include "Item.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	bool Item::linear() {
		return flag;
	}
	Item::Item() :state {}{
		price = 0;
		quantity_hand = 0;
		quantity_needed = 0;
		description = nullptr;
		flag = false;
		SKU = 0;
	}
	Item::Item(Item& i) {
		*this = i;
	}
	Item::~Item() {
		delete[] description;
		description = nullptr;
	}
	Item& Item::operator=(Item& i) {
		if (description!=nullptr)
		{
			delete[] description;
			description = nullptr;
		}
		if (i.description != nullptr)
		{
			price = i.price;
			quantity_hand = i.quantity_hand;
			quantity_needed = i.quantity_needed;
			ut.alocpy(description, i.description);
			flag = i.flag;
			state = i.state;
			SKU = i.SKU;
			
		}
		return *this;
	}
	int Item::qtyNeeded()const {
		return quantity_needed;
	}
	int Item::qty()const {
		return quantity_hand;
	}
	Item::operator double()const {
		return price;
	}
	Item::operator bool()const {
		return state.operator bool();
	}
	int Item::operator-=(int qty) {
		int minus = 0;
		if (quantity_hand>qty)
		{
			quantity_hand -= qty;
			minus = qty;
		}
		else
		{
			quantity_hand = 0;
			minus = quantity_hand;
		}
		return minus;
	}
	int Item::operator+=(int qty) {
		int add = 0;
		if (quantity_hand+qty<quantity_needed)
		{
			quantity_hand += qty;
			add = qty;
		}
		else
		{
			quantity_hand = quantity_needed;
			add = quantity_needed - quantity_hand;
		}
		return add;
	}
	void Item::linear(bool isLinear) {
		flag = isLinear;
	}
	void Item::clear() {
		state.clear();
	}
	bool Item::operator==(int sku)const {
		bool ans = false;
		if (SKU==sku)
		{
			ans = true;
		}
		return ans;
	}
	bool Item::operator==(const char* descr)const {
		bool ans = true;
		if (strstr(description,descr)==0)
		{
			ans = false;
		}
		return ans;
	}
	ofstream& Item::save(std::ofstream& ofstr) {
		if (*this)
		{
			ofstr <<SKU << '\t';
			ofstr << left<< description << '\t' << quantity_hand << '\t' << quantity_needed << '\t';
			ofstr << fixed << setprecision(2) << price;
		}
		return ofstr;
	}
	ifstream& Item::load(std::ifstream& ifstr) {
		if (description!=nullptr)
		{
			delete[] description;
			description = nullptr;
		}
		char temp[500];
		ifstr >> SKU;
		ifstr.ignore(1000, '\t');
		ifstr.getline(temp, 500, '\t');
		ifstr >> quantity_hand;
		ifstr.ignore(1000, '\t');
		ifstr >> quantity_needed;
		ifstr.ignore(1000, '\t');
		ifstr >> price;
		description = new char[strlen(temp) + 1];
		strcpy(description, temp);
		ifstr.ignore();
		if (ifstr.fail())
		{
			state= "Input file stream read failed!";
		}
		return ifstr;
	}
	ostream& Item::display(std::ostream& ostr) {
		if (!(*this))
		{
			ostr << state.operator const char *();
		}
		else
		{
			if (flag==true)
			{
			ostr << SKU << " | ";
			if (description!=nullptr)
			{
				if (strlen(description) > 35)
				{
					for (int i = 0; i < 35; i++)
					{
						ostr << description[i];
					}
				}
				else
				{
					ostr << setw(35) << left << description;
				}
			}
				
				
				ostr << " | " << setw(4)<< right<<quantity_hand << " | " << setw(4) << right << quantity_needed << " | " << setw(7) << right << fixed << setprecision(2) << price << " |";
			}
			else
			{

				ostr << "AMA Item:" << endl;
				ostr << SKU <<": " << description<< endl;
				ostr << "Quantity Needed: " << quantity_needed<< endl;
				ostr << "Quantity Available: " << quantity_hand<< endl;
				ostr << "Unit Price: $" <<fixed << setprecision(2)<< price << endl;
				ostr << "Needed Purchase Fund: $" << fixed << setprecision(2) << price * (quantity_needed-quantity_hand) << endl;
			}
		}
		return ostr;
	}
	istream& Item::read(std::istream& istr) {
		delete[] description;
		description = nullptr;
		char temp[500];
		int num=-1;
		double num2=-1;
		state.clear();
		cout << "AMA Item:"<< endl;
		cout << "SKU: " << SKU << endl;
		cout << "Description: ";
		istr.get(temp,1000);
		description = new char[strlen(temp) + 1];
		strcpy(description, temp);
		cout << "Quantity Needed: ";
		do
		{
			num = 0;
			istr >> num;
			if (istr.peek() == '\n')
			{
				if (num >= 1 && num <= 9999)
				{
					quantity_needed = num;
				}
				else
				{
					cout << "Value out of range [1<=val<=9999]: ";
				}
			}
			else
			{
				cout << "Invalid Integer, retry: ";
				num = -1;
			}
			istr.clear();
			istr.ignore(1000, '\n');
		} while (num < 0 || num>9999);

		cout << "Quantity On Hand: ";
		do
		{
			num = 0;
			istr >> num;
			if (istr.peek() == '\n')
			{
				if (num >= 0 && num <= quantity_needed)
				{
					quantity_hand = num;
				}
				else
				{
					cout << "Value out of range [0<=val<="<< quantity_needed <<"]: ";
				}
			}
			else
			{
				cout << "Invalid Integer, retry: ";
				num = -1;
			}
			istr.clear();
			istr.ignore(1000, '\n');
			
		} while (num < 0 || num>quantity_needed);
		cout << "Unit Price: $";
		do
		{
			num2 = 0;
			istr >> num2;
			if (istr.peek() == '\n')
			{
				if (num2 >= 0 && num2 <= 9999)
				{
					price = num2;
				}
				else
				{
					cout << "Value out of range [0.00<=val<=9999.00]: ";
				}
			}
			else
			{
				cout << "Invalid number, retry: ";
				num2 = -1;
			}
			istr.clear();
			istr.ignore(1000, '\n');
		} while (num2 < 0 || num2>99999);
		if (istr.fail()) {
			state = "Console entry failed!";
		}
		return istr;
	}
	int Item::readSku(std::istream& istr) {
		int num = 0;
		cout << "SKU: ";
		do
		{
			istr >> num;
			if (istr.peek()=='\n')
			{
				if ((num >= 40000 && num <= 99999))
				{
					SKU = num;
				}
				else
				{
					cout << "Value out of range [40000<=val<=99999]: ";
				}
			}
			else
			{
				
				cout << "Invalid Integer, retry: ";
			}
			istr.clear();
			istr.ignore(1000, '\n');
		} while (num<40000 || num>99999);
		return num;
	}
}