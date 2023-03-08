/* Citation and Sources...
Final Project Milestone 2
Module: AidMan
Filename: AidMan.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "AidMan.h"
#include "Date.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	unsigned int AidMan::menu() {
		int num = 0;
		cout << "Aid Management System Version 0.1" << endl;
		cout << "Date: " << Date() << endl;
		if (file==nullptr)
		{
			cout << "Data file: "  <<"No file" << endl;
		}
		else
		{
			cout << "Data file:  " << file << endl;
		}

		cout << "---------------------------------" << endl;
		num=mainmenu.run();
		return num;
	}
	AidMan::AidMan() {
		file = nullptr;
	}
	AidMan::~AidMan() {
	
		delete[] file;
		file = nullptr;
		
	}
	void AidMan::run() {
		int num;
		do
		{
			num = menu();
			switch (num)
			{
			case 1:
				cout << endl << "****List Items****" << endl << endl;
				break;
			case 2:
				cout << endl << "****Add Item****" << endl << endl;
				break;
			case 3:
				cout << endl << "****Remove Item****" << endl << endl;
				break;
			case 4:
				cout << endl << "****Update Quantity****" << endl << endl;
				break;
			case 5:
				cout << endl << "****Sort****" << endl << endl;
				break;
			case 6:
				cout << endl << "****Ship Items****" << endl << endl;
				break;
			case 7:
				cout << endl << "****New/Open Aid Database****"<< endl << endl;
				break;
			default:
				cout << "Exiting Program!" << endl;
				break;
			}
			
		} while (num!=0);
	}
}