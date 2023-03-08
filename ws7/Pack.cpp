/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/16/2022
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Pack.h"
using namespace std;
namespace sdds {
    Pack::Pack(const char* content, const int size, const int unitsize, const int number) :Container(content, size * unitsize, unitsize * number) 
    {
        Size = size;
        unitSize = unitsize;
        Number = number;
    }
    int Pack::operator += (int units) 
    {
        int result = 0;
        result = Container::operator+=(units * unitSize) / unitSize;
        Number += result;
        return result;
    }
    int Pack::operator -= (int units) 
    {
        int result = 0;
        result = Container::operator-=(units * unitSize) / unitSize;
        Number -= result;
        return result;
    }
    int Pack::unit() 
    {
        return unitSize;
    }
    int Pack::noOfUnits() 
    {
        return Number;
    }
    int Pack::size() 
    {
        return Size;
    }
    void Pack::clear(int size, int unitsize, const char* content) {
        if (unitSize > 0) {
            Container::clear(size * unitsize, content);
            Size = size;
            unitSize = unitsize;
            Number = 0;
        }
    }
    ostream& Pack::print(ostream& ostr) {
        Container::print(ostr);
        if (Container::operator bool() == true) {
            ostr << ", " << Number << " in a pack of " << Size;
        }
        return ostr;
    }
    istream& Pack::read(istream& istr) {
        int num;
        if (operator bool()==false) 
        {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
            cin.get();
        }
        else if (Number == Size) 
        {
            cout << "Pack is full!, press <ENTER> to continue...";
            cin.get();
            istr.ignore();
        }
        else 
        {
            cout << "Add to ";
            print(cout);
            int max = Size - Number;
            cout << endl << "> ";
            istr >> num;
            if (num > Size) 
            {
                cout << "Invalid Integer, retry: ";
                cin >> num;
            }

            else if (num < 1 || num > max) 
            {
                cout << "Value out of range [1<=val<=" << max << "]: ";
                cin >> num;
            }
            num = (*this += num);
            cout << "Added " << num << endl;
        }

        return istr;
    }
    ostream& operator<<(ostream& ostr, Pack& P) {
        return P.print(ostr);
    }

    istream& operator>>(istream& istr, Pack& P) {
        return P.read(istr);
    }

}
