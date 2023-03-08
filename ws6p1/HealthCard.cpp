/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/03/2022
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "HealthCard.h"
using namespace std;
namespace sdds {
    bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
        bool ans = false;
        if (name!=nullptr && strcmp(name,"")!=0 && number > 999999999 && number< 9999999999 && strlen(vCode)==2 && strlen(sNumber) == 9)
        {
            ans = true;
        }
        return ans;
    }
    void HealthCard::setEmpty() {
        m_name = nullptr;
        m_number = 0;
        m_vCode[0] = '\0';
        m_sNumber[0] = '\0';
    }
    void HealthCard::allocateAndCopy(const char* name) {
        if(name==nullptr)
        {
            delete[] name;
            name = nullptr;
        }
        else
        {
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
        }
        
    }
    void HealthCard::extractChar(istream& istr, char ch) const {
        char next = istr.peek();
        if (next==ch)
        {
            istr.ignore();
        }
        else
        {
            istr.ignore(1000, ch);
            istr.setstate(ios::failbit);
        }
    }
    ostream& HealthCard::printIDInfo(ostream& ostr)const {
        
        ostr << m_number << "-" << m_vCode << ", " << m_sNumber ;
        return ostr;
    }
    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
        if (validID(name, number, vCode, sNumber))
        {
            delete[] m_name;
            allocateAndCopy(name);
            m_number = number;
            strcpy(m_vCode, vCode);
            strcpy(m_sNumber, sNumber);
        }
        else
        {
            delete[] m_name;
            setEmpty();
        }
    }
    HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
        if (validID(name, number, vCode, sNumber))
        {
            set(name, number, vCode, sNumber);
        }
    }
    HealthCard::HealthCard(const HealthCard& hc) {
        if (validID(hc.m_name,hc.m_number,hc.m_vCode, hc.m_sNumber)==true)
        {
            *this = hc;
        }
    }
    HealthCard& HealthCard::operator=(const HealthCard& hc) {
        if (this!=&hc)
        {
            delete[] m_name;
            setEmpty();
            allocateAndCopy(hc.m_name);
            m_number = hc.m_number;
            strcpy(m_sNumber, hc.m_sNumber);
            strcpy(m_vCode, hc.m_vCode);
        }
        return *this;
    }
    HealthCard::~HealthCard() {
        delete[] m_name;
        m_name = nullptr;
    }
    HealthCard::operator bool() const {
        bool ans = false;
        if (m_name!=nullptr)
        {
            ans = true;
        }
        return ans;
    }
    ostream& HealthCard::print(ostream& ostr, bool toFile) const {
            if (toFile == true && m_name != nullptr)
            {
                ostr << m_name << ",";
                printIDInfo(ostr);
                ostr << endl;
            }
            else if (toFile == false)
            {
                int num = strlen(m_name);
                ostr << m_name;
                for (int i = 0; i < (50 - num); i++)
                {
                    ostr << ".";
                }
                printIDInfo(ostr);
            }
            return ostr;
    }
    istream& HealthCard::read(istream& istr) {
        char name[56];
        long long number;
        char code[3];
        char snumber[10];
        istr.get(name, MaxNameLength, ',');
        extractChar(istr, ',');
        istr >> number;
        extractChar(istr, '-');
        istr.get(code, 3, ',');
        extractChar(istr, ',');
        istr.get(snumber, 10, '\n');
        extractChar(istr, '\n');
        if (!istr.fail())
        {
            set(name, number, code, snumber);
        }
        else
        {
            delete[] m_name;
            setEmpty();
            istr.clear();
            istr.ignore(1000, '\n');
        }
        return istr;
    }
    ostream& operator<<(ostream& ostr, const HealthCard& hc) {
        if (hc)
        {
            hc.print(ostr, false);
        }
        else
        {
            ostr << "Invalid Health Card Record";
        }
        return ostr;
    }
    istream& operator>>(istream& istr, HealthCard& hc) {
        return (hc.read(istr));
    }
}