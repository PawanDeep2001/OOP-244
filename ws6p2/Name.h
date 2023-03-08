/*
	I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
	Name   :Pawan Deep
	ID     :111144218
	Email  :pdeep1@myseneca.ca
	Date   :03/07/2022
*/
#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>
using namespace std;
namespace sdds {
	class Name
	{
		char* FName;
		char* MName;
		char* LName;
		bool s;
		void setEmpty();
		void set(const char* fname = nullptr, const char* lname = nullptr, const char* mname = nullptr);
		bool valid(const char* name)const;
	public:
		Name();
		Name(const char* fname);
		Name(const char* fname, const char* lname);
		Name(const char* fname, const char* mname, const char* lname);
		Name(const Name& n);
		Name& operator=(const Name& n);
		~Name();
		void setShort(bool ans);
		Name& operator +=(const char str[]);
		operator bool() const;
		istream& read(istream& istr);
		ostream& printName(ostream& ostr, bool ans=false) const;
		
	};
	istream& operator>>(istream& istr, Name& n);
	ostream& operator<<(ostream& ostr, const Name& n);
}
#endif