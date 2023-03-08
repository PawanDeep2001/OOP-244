/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/22/2022
*/
#include <iostream>
#include <cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds {
    Rectangle::Rectangle() :LblShape(){
        m_height = 0;
        m_width = 0;
    }
    Rectangle::Rectangle(const char* str, const int width, const int height): LblShape(str) {
        m_height = height;
        m_width = width;
        int len = 0;
        len= strlen(label());
        if(m_height<3 || m_width< len)
        {
            m_height = 0;
            m_width = 0;
        }
    }
    void Rectangle::getSpect(istream& istr) {
        LblShape::getSpect(istr);
        istr >> m_width;
        istr.ignore(1000, ',');
        istr >> m_height;
        istr.ignore(1000, '\n');
    }
    void Rectangle::draw(ostream& ostr)const {
        if (m_width>0)
        {
            ostr << "+";
            for (int i = 0; i < (m_width - 2); i++)
            {
                ostr << "-";
            }
            ostr << "+" << endl;
            ostr << "|" << left << label();
            int count = strlen(label());
            for (int i = 0; i < (m_width - 2 - count); i++)
            {
                ostr << " ";
            }
            ostr << "|" << endl;
            for (int i = 0; i < m_height - 3; i++)
            {
                ostr << "|";
                for (int o = 0; o < m_width - 2; o++)
                {
                    ostr << " ";
                }
                ostr << "|" << endl;
            }
            ostr << "+";
            for (int i = 0; i < (m_width - 2); i++)
            {
                ostr << "-";
            }
            ostr << "+" ;
        }
    }
}