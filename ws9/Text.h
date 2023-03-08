/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/29/2022
*/
#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include <iostream>
using namespace std;
namespace sdds {
	class Text
	{
		char* m_content = nullptr;
	protected:
		const char& operator[](int index)const;
	public:
		Text();
		Text(Text& t);
		Text& operator=(Text& t);
		~Text();
		istream& read(istream& istr);
		virtual ostream& write(ostream& ostr) const;
		int getFileLength(std::istream& is);
	};
	istream& operator>>(istream& istr, Text& t);
	ostream& operator<<(ostream& ostr, const Text& t);
}
#endif