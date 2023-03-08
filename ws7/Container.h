/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/16/2022
*/
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
#include <iostream>
using namespace std;
namespace sdds {
	class Container
	{
		char Content[50];
		int Capacity = 0;
		int Volume = 0;
	protected:
		void setEmpty();
		int capacity();
		int volume();
	public:
		Container(const char* content, int capacity, int volume=0);
		int operator+=(int volume);
		int operator-=(int volume);
		operator bool() const;
		void clear(int capacity, const char* content);
		ostream& print(ostream& ostr);
		istream& read(istream& istr);
	};
	ostream& operator<<(ostream& ostr, Container& con);
	istream& operator>>(istream& istr, Container& con);
}
#endif