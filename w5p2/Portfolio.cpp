/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :02/17/2022
*/
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"
#include <cstring>
using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }
    Portfolio::operator double() const {
        return m_value;
    }
    Portfolio::operator const char* () const {
        return m_stock;
    }
    Portfolio::operator char () const {
        return m_type;
    }
    Portfolio::operator bool() const {
        bool ans = false;
        if (m_type == 'V'|| m_type == 'G' || m_type == 'I')
        {
            ans = true;
        }
        return ans;
    }
    Portfolio& Portfolio::operator +=(const double value) {
        if (this && value>=0 &&m_value-value>0)
        {
            m_value += value;
        }
        return *this;
    }
    Portfolio& Portfolio::operator -=(const double value) {
        if (this && value >= 0 && m_value - value > 0)
        {
            m_value -= value;
        }
        return *this;
    }
    bool Portfolio::operator ~() const {
        bool ans = false;
        if (m_value<0)
        {
            ans = true;
        }
        return ans;
    }
    Portfolio& Portfolio::operator<<(Portfolio& portf) {
        if (this && portf && this!=&portf)
        {
            m_value += portf.m_value;
            portf.emptyPortfolio();
        }
        return *this;
    }
    Portfolio& Portfolio::operator>>(Portfolio& portf) {
        if (this && portf && this != &portf) {
            portf.m_value += m_value;
            emptyPortfolio();
        }
        return *this;
    }
    double operator+(const Portfolio& p1, const Portfolio& p2) {
        double ans = 0;
        if (p1 && p2)
        {
            ans = p1.m_value + p2.m_value;
        }
        return ans;
    }
    double operator+=(double& a, const Portfolio& p2) {
        a += p2.m_value;
        return a;
    }
}