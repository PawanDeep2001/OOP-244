/* Citation and Sources...
Final Project Milestone 51
Module: Menu
Filename: Menu.h
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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {
	class Menu
	{
		char* Text=nullptr;
		unsigned int numOptions=16;
	public:
		Menu(const char* text=nullptr, const unsigned int num=0);
		~Menu();
		unsigned int run();
		operator const char* () const;
		operator int () const;
	};
}
#endif