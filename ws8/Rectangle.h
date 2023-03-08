/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/22/2022
*/
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include <iostream>
#include "LblShape.h"
using namespace std;
namespace sdds {
	class Rectangle: public LblShape
	{
		int m_width = 0;
		int m_height = 0;
	public:
		Rectangle();
		Rectangle(const char* str, const int width, const int height);
		void getSpect(istream& istr);
		void draw(ostream& ostr) const;
	};
}
#endif
