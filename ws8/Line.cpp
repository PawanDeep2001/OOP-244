/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/22/2022
*/
#include <iostream>
#include <cstring>
#include "Line.h"
using namespace std;
namespace sdds {
    Line::Line(): LblShape() {
        m_length = 0;
    }
    Line::Line(const char* str, int num) : LblShape(str){
        m_length = num;
    }
    void Line::getSpect(istream& istr) {
        LblShape::getSpect(istr);
        istr >> m_length;
        istr.ignore(1000, '\n');
    }
    void Line::draw(ostream& ostr) const{
        if (m_length>0 && label()!=nullptr)
        {
            ostr << label() << endl;
            for (int i = 0; i < m_length; i++)
            {
                ostr << "=";
            }
        }
    }
}