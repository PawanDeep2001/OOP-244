/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/29/2022
*/
#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
#include <iostream>
#include "Text.h"
using namespace std;
namespace sdds {
	class HtmlText: public Text
	{
		char* m_title=nullptr;
	public:
		HtmlText();
		HtmlText(const char* ch);
		HtmlText(HtmlText& t);
		HtmlText& operator=(HtmlText& t);
		~HtmlText();
		ostream& write(ostream& ostr) const;
	};
}
#endif