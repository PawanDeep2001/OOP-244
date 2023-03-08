/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/22/2022
*/
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include <iostream>
#include "LblShape.h"
using namespace std;
namespace sdds {
	class Line: public LblShape
	{
		int m_length=0;
	public:
		Line();
		Line(const char* str, int num);
		void getSpect(istream& istr);
		void draw(ostream& ostr) const;
	};
}
#endif
