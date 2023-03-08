/* Citation and Sources...
Final Project Milestone 56
Module: Item
Filename: Item.h
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
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include <iostream>
#include "iProduct.h"
#include "Status.h"
using namespace std;
namespace sdds {
	class Item: public iProduct
	{
		double price = 0;
		int quantity_hand = 0;
		int quantity_needed = 0;
		char* description = nullptr;
		bool flag=false;
	protected:
		bool linear();
		Status state = {};
		int SKU = 0;
		
	public:
		Item();
		Item(Item& i);
		~Item();
		Item& operator=(Item& i);
		int qtyNeeded()const;
		int qty()const;
		operator double()const;
		operator bool()const;
		int operator-=(int qty);
		int operator+=(int qty);
		void linear(bool isLinear);
		void clear();
		bool operator==(int sku)const;
		bool operator==(const char* descr)const;
		ofstream& save(ofstream& ofstr);
		ifstream& load(ifstream& ifstr);
		ostream& display(ostream& ostr);
		istream& read(istream& istr);
		int readSku(istream& istr);
	};
}
#endif
