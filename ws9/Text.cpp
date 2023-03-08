/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/29/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Text.h"
using namespace std;
namespace sdds {
    Text::Text() {
        m_content = nullptr;
    }
    const char& Text::operator[](int index)const {
        return m_content[index];
    }
    Text::Text(Text& t) {
        *this = t;
    }
    Text& Text::operator=(Text& t) {
        if (t.m_content!=nullptr)
        {
            delete[] m_content;
            m_content = nullptr;
            m_content = new char[strlen(t.m_content) + 1];
            strcpy(m_content, t.m_content);
        }
        return *this;
    }
    Text::~Text() {
        delete[] m_content;
        m_content = nullptr;
    }
    istream& Text::read(istream& istr) {
        delete[] m_content;
        m_content = nullptr;
        int i = 0;
        char c;
        int length = getFileLength(istr)+1 ;
        m_content = new char[length];
        while (istr.get(c))
        {
            if (istr)
            {
                
                m_content[i] = c;
                i++;
            }

        }
        m_content[i] = '\0';
        if (m_content!=nullptr)
        {
            istr.clear();
        }
        return istr;
    }
    ostream& Text::write(ostream& ostr) const {
        if (m_content!= nullptr)
        {
            ostr << m_content;
        }
        return ostr;
    }
    int Text::getFileLength(std::istream& is) {
        int len{};
        if (is) {
            // save the current read position
            std::streampos cur = is.tellg();
            // go to the end
            is.seekg(0, ios::end);
            // let what is the positions (end position = size)
            len = is.tellg();
            // now go back to where you were.
            is.seekg(cur);
        }
        return len;
    }
    istream& operator>>(istream& istr, Text& t) {
        t.read(istr);
        return istr;
    }
    ostream& operator<<(ostream& ostr, const Text& t) {
        t.write(ostr);
        return ostr;
    }
}