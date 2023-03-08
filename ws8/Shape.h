/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/22/2022
*/
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iostream>
using namespace std;
namespace sdds {
	class Shape
	{
	public:
		virtual void draw(ostream& ostr) const = 0;
		virtual void getSpect(istream& istr)=0;
		virtual ~Shape() {};
	};
	ostream& operator<<(ostream& ostr, const Shape& s);

    istream& operator>>(istream& istr, Shape& s);
}
#endif