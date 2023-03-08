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
#include "HtmlText.h"
using namespace std;
namespace sdds {
    HtmlText::HtmlText() {
        m_title = nullptr;
    }
    HtmlText::HtmlText(const char* ch) {
        m_title = new char[strlen(ch)+1];
        strcpy(m_title, ch);
    }
    HtmlText::~HtmlText() {
        delete[] m_title;
        m_title = nullptr;
    }
    HtmlText::HtmlText(HtmlText& t) {
        *this = t;
    }
    HtmlText& HtmlText::operator=(HtmlText& t) {
        Text::operator=(t);
        if (t.m_title!=nullptr)
        {
            if (m_title!=nullptr)
            {
                delete[] m_title;
                m_title = nullptr;
            }
            m_title = new char[strlen(t.m_title) + 1];
            strcpy(m_title, t.m_title);
        }
        return *this;
    }
    ostream& HtmlText::write(ostream& ostr) const {
        bool MS = false;
        int i= 0;
        char ch;
        ostr << "<html><head><title>";
        if (m_title!=nullptr)
        {
            ostr << m_title;
        }
        else
        {
            ostr << "No Title";
        }
        ostr << "</title></head>\n<body>\n";
        if (m_title!=nullptr)
        {
            ostr << "<h1>" << m_title << "</h1>\n";
        }
        do
        {
            ch = Text::operator[](i);
            i++;
            if (ch==' ')
            {
                if (MS==true)
                {
                    ostr << "&nbsp;";
                }
                else
                {
                    MS = true;
                    ostr << " ";
                }
            }
            else if (ch=='<')
            {
                ostr << "&lt;";
                MS = false;
            }
            else if (ch == '>')
            {
                ostr << "&gt;";
                MS = false;
            }
            else if (ch=='\n')
            {
                ostr << "<br />\n";
                MS = false;
            }
            else if (ch == '\0')
            {
                ;
            }
            else
            {
                MS = false;
                ostr << ch;
            }
        } while (ch!='\0');
        ostr << "</body>\n</html>";
        return ostr;
    }
}