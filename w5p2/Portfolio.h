/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :02/17/2022
*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

    class Portfolio {
        double m_value = 0;
        char m_stock[16];
        char m_type;
        void emptyPortfolio();
    public:
        Portfolio();
        Portfolio(double value, const char* stock, char type);
        void dispPortfolio() const;
        std::ostream& display() const;
        operator double() const;
        operator const char* () const;
        operator char () const;
        operator bool() const;
        bool operator ~() const;
        Portfolio& operator +=(const double value);
        Portfolio& operator -=(const double value);
        Portfolio& operator<<(Portfolio& portf);
        Portfolio& operator>>(Portfolio& portf);
        friend double operator+(const Portfolio& p1, const Portfolio& p2);
        friend double operator+=(double& a, const Portfolio& f2);
    };
}
#endif // SDDS_Portfolio_H_
