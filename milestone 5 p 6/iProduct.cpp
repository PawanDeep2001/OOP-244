/* Citation and Sources...
Final Project Milestone 56
Module: iProduct
Filename: iProduct.cpp
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
#include "iProduct.h"
#include "Utils.h"
using namespace std;
namespace sdds {
	istream& operator>>(istream& istr, iProduct& p) {
		return p.read(istr);
	}
	ostream& operator<<(ostream& ostr, iProduct& p) {
		return p.display(ostr);
	}
}