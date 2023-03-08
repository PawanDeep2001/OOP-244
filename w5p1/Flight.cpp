/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :02/16/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }
    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }
    Flight::operator bool() const {
        bool ans = false;
        if (m_passengers > 0 && m_fuel>=m_passengers*600)
        {
            ans = true;
        }
        return ans;
    }
    Flight::operator int() const {
        return m_passengers;
    }
    Flight::operator double() const {
        return m_fuel;
    }
    Flight::operator const char*() const {
        return m_title;
    }
    bool Flight::operator~() const {   
        bool ans = false;
        if (m_passengers==0)
        {
            ans = true;
        }
        return ans;
    }
    Flight& Flight::operator=(Flight& flight)
    {
        if (this != &flight)
        {
            m_passengers = flight.m_passengers;
            m_fuel = flight.m_fuel;
            strcpy(m_title, flight.m_title);
            flight.emptyPlane();
        }
        return *this;
    }

    Flight& Flight::operator=(const int passenger)
    {
        if (passenger > 0 && passenger <= 388)
        {
            m_passengers = passenger;
        }
        return *this;
    }
    Flight& Flight::operator=(const double fuel)
    {
        if (fuel > 0 && fuel <= FuelTankCapacity)
        {
            m_fuel = fuel;
        }
        return *this;
    }

    Flight& Flight::operator+=(const double fuel)
    {
        if (fuel > 0 && m_fuel < FuelTankCapacity &&m_fuel+fuel< FuelTankCapacity)
        {
            m_fuel =m_fuel + fuel;
        }
        else if (fuel > 0 && m_fuel < FuelTankCapacity && m_fuel + fuel > FuelTankCapacity)
        {
            m_fuel = FuelTankCapacity;
        }
        return *this;
    }
    Flight& Flight::operator+=(const int passenger)
    {
        if (passenger > 0 && m_passengers < Boen747Capacity && m_passengers+passenger< Boen747Capacity)
        {
            m_passengers = m_passengers + passenger;
        }
        else if (passenger > 0 && m_passengers < Boen747Capacity && m_passengers + passenger < Boen747Capacity)
        {
            m_passengers = Boen747Capacity;
        }
        return *this;
    }
    Flight& Flight::operator-=(const double fuel)
    {
        if (fuel >= 0 && m_fuel-fuel>=0)
        {
            m_fuel = m_fuel - fuel;
        }
        else if (fuel >= 0 && m_fuel-fuel<0)
        {
            m_fuel = 0;
        }
        return *this;
    }

    Flight& Flight::operator-=(const int passenger)
    {
        if (passenger >= 0 && m_passengers-passenger>=0)
        {
            m_passengers =m_passengers- passenger; 
        }
        else if (passenger >= 0 && m_passengers - passenger < 0)
        {
            m_passengers = 0;
        }
        return *this;
    }
    Flight& Flight::operator<<(Flight& flight)
    {
        if (this != &flight)
        {
            if (flight.m_passengers < Boen747Capacity - m_passengers)
            {
                m_passengers += flight.m_passengers;
                flight.m_passengers = 0;
            }
            else {
                flight.m_passengers -= Boen747Capacity - m_passengers;
                m_passengers += Boen747Capacity - m_passengers;
            }
        }
        return *this;
    }
    Flight& Flight::operator>>(Flight& flight)
    {
        if (this != &flight && (*this) && (flight))
        {
            if (m_passengers <= Boen747Capacity - flight.m_passengers)
            {
                flight.m_passengers += m_passengers;
                m_passengers = 0;
            }
            else {
                m_passengers -= Boen747Capacity - flight.m_passengers;
                flight.m_passengers += Boen747Capacity - flight.m_passengers;
            }
        }
        return *this;
    }

    int operator+ (const Flight& f1, const Flight& f2) 
    {
        int ans = 0;
        if (bool(f1)==true && bool(f2)==true)
        {
            ans= f1.m_passengers + f2.m_passengers;
        }
        return ans;
    }
    int operator += (int& a, const Flight& f2) 
    {
        a += f2.m_passengers;
        return a;
    }
}