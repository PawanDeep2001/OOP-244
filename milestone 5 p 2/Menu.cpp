/* Citation and Sources...
Final Project Milestone 52
Module: Menu
Filename: Menu.cpp
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
#include "Menu.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	Menu::Menu(const char* text, const unsigned int num) {
		if (text!=nullptr && num < 15)
		{
			Text = nullptr;
			Text = new char[strlen(text)+1];
			strcpy(Text, text);
			numOptions = num;
		}
	}
	Menu::~Menu() {
		delete[] Text;
		Text = nullptr;
	}

	unsigned int Menu::run() {
		unsigned int num = 0;
		cout << Text << "0- Exit"<< endl;
		cout << "> ";
		do
		{
			num = 0;
			cin >> num;

			if (cin.peek()!='\n')
			{
				cout << "Invalid Integer, retry: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else
			{
				if (num > numOptions || num < 0)
				{
					cout << "Value out of range [0<=val<=" << numOptions << "]: ";
				}
			}
			
		} while (num<0 || num>numOptions || cin.peek()!='\n');
		return num;
	}
	Menu::operator const char* () const {
		return Text;
	}
	Menu::operator int() const {
		return numOptions;
	}
}