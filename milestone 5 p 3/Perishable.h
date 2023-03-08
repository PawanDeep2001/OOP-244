/* Citation and Sources...
Final Project Milestone 53
Module: Perishable
Filename: Perishable.h
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
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include <iostream>
#include "iProduct.h"
#include "Item.h"
#include "Date.h"
using namespace std;
namespace sdds {
	class Perishable : public Item
	{
		int sku=0;
		Date expiryDate;
		char* instructions=nullptr;
	public:
		Perishable();
		Perishable(Perishable& p);
		Perishable& operator=(Perishable& p);
		~Perishable();
		const Date& expiry() const;
		int readSku(istream& istr);
		ofstream& save(std::ofstream& ofstr);
		ifstream& load(std::ifstream& ifstr);
		ostream& display(std::ostream& ostr);
		istream& read(std::istream& istr);
		operator bool() const;
	};
}
#endif