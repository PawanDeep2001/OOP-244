/* Citation and Sources...
Final Project Milestone 56
Module: AidMan
Filename: AidMan.h
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
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include <iostream>
#include "Menu.h"
#include "iProduct.h"
using namespace std;
namespace sdds {
	const int sdds_max_num_items = 100;
	class AidMan: public Menu
	{
		char* file;
		Menu mainmenu;
		unsigned int menu();
		iProduct* arr[sdds_max_num_items];
		int counter = 0;
		void save();
		void deallocate();
		bool load();
		int list(const char* sub_desc = nullptr);
		int search(int sku) const;
		void remove(int index);
	public:
		AidMan();
		~AidMan();
		void run();

	};
}
#endif
