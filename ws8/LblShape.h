/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/22/2022
*/
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds {
	class LblShape: public Shape
	{
		char* m_label=nullptr;
	protected:
		const char* label()const;
	public:
		LblShape();
		LblShape(const char* lab);
		~LblShape();
		LblShape(const LblShape&) =delete;
		LblShape& operator=(const LblShape&) = delete;
		void getSpect(istream& istr);
	};
}
#endif