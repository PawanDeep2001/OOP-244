/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/16/2022
*/
#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include <iostream>
#include "Container.h"
using namespace std;
namespace sdds {
	class Pack : public Container
	{
		int unitSize = 0;
		int Size = 0;
		int Number = 0;
	public:
		Pack(const char* content, const int size, const int unitsize = 330, const int number = 0);
        int operator += (int units);
        int operator -= (int units);
        int unit();
        int noOfUnits();
        int size();
		void clear(int packSize, int unitSize, const char* content);
		ostream& print(ostream& ostr);
		istream& read(istream& istr);

	};
	ostream& operator<<(ostream& ostr, Pack& P);
	istream& operator>>(istream& istr, Pack& P);
}
#endif