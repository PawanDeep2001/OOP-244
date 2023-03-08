/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :02/16/2022
*/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

    const int Boen747Capacity = 388;
    const int FuelTankCapacity = 238840;

    class Flight {

        int m_passengers = 0;
        double m_fuel = 0;
        char m_title[16];
        void emptyPlane();

    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double() const;
        operator const char* () const;
        bool operator ~() const;
        Flight& operator =(Flight& flight);
        Flight& operator =(const int passenger);
        Flight& operator =(const double fuel);
        Flight& operator +=(const double fuel);
        Flight& operator +=(const int passenger);
        Flight& operator -=(const double fuel);
        Flight& operator -=(const int passenger);
        Flight& operator <<(Flight& flight);
        Flight& operator >>(Flight& flight);
        friend int operator + (const Flight& f1, const Flight& f2);
        friend int operator += (int& left, const Flight& f2);
    };

}
#endif // SDDS_FLIGHT_H
