/* Citation and Sources...
Final Project Milestone 2
Module: AidMan
Filename: AidMan.h
Version 1.0
Author	Name   :Pawan Deep
		ID     :111144218
		Email  :pdeep1@myseneca.ca
		Date   :03/14/2022
Revision History
-----------------------------------------------------------
Date      Reason
03/14/2022  Preliminary release
03/14/2022  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include <iostream>
#include "Menu.h"
using namespace std;
namespace sdds {
	class AidMan
	{
		char* file;
		Menu mainmenu{ "1- List Items\n""2- Add Item\n""3- Remove Item\n""4- Update Quantity\n""5- Sort\n""6- Ship Items\n""7- New/Open Aid Database\n""---------------------------------\n",7 };
		unsigned int menu();

	public:
		AidMan();
		~AidMan();
		void run();

	};
}
#endif
