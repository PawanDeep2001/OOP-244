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
#include "Container.h"
using namespace std;
namespace sdds {
    Container::Container(const char* content, int capacity, int volume) {
        if (volume<capacity && content!=nullptr)
        {
            strcpy(Content, content);
            Capacity = capacity;
            Volume = volume;
        }
        else
        {
            setEmpty();
        }
    }
    void Container::setEmpty() {
        Volume = 0;
        Capacity = 0;
        strcpy(Content, "");
    }
    int Container::capacity() {
        return Capacity;
    }
    int Container::volume() {
        return Volume;
    }
    int Container::operator+=(int volume) {
        int add = 0;
        if (Volume+volume <= Capacity)
        {
            Volume += volume;
            add = volume;
        }
        else
        {
            add = Capacity - Volume;
            Volume = Capacity;
        }
        return add;
    }
    int Container::operator-=(int volume) {
        int minus = 0;
        if (Volume - volume >= 0)
        {
            Volume -= volume;
            minus = volume;
        }
        else
        {
            minus = Volume;
            Volume = 0;
        }
        return minus;
    }
    Container::operator bool() const {
        bool ans = false;
        if (Capacity>0)
        {
            ans = true;
        }
        return ans;
    }
    void Container::clear(int capacity, const char* content) {
        if (capacity>0 && strcmp(content, ""))
        {
            Capacity = capacity;
            strcpy(Content, content);
        }
    }
    ostream& Container::print(ostream& ostr) {
        if (Capacity>0)
        {
            ostr << Content << ": (" << Volume << "cc/" << Capacity << ")";
        }
        else
        {
            ostr << "****: (**cc/***)";
        }
        return ostr;
    }
    istream& Container::read(istream& istr) {
        int num = 0;
        if (Capacity==0)
        {
            cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
            cin.get();
            istr.ignore();
            
        }
        else
        {
            cout << "Add to ";
            print(cout);
            cout << endl << "> ";
            cin >> num;
            if (cin.peek()!='\n')
            {
                cout << "Invalid Integer, retry: ";
                cin >> num;
            }
            else
            {
                if (num>999 || num<1)
                {
                    cout << "Value out of range [1<=val<=999]: ";
                    cin >> num;
                }
                else
                {
                    if (num > 0 && num <= 220000)
                    {
                        int add=*this += num;
                        cout << "Added " <<add << " CCs" << endl;
                    }
                }
            }
            
        }
        return istr;
    }
    ostream& operator<<(ostream& ostr, Container& con) {
        return (con.print(ostr));
    }
    istream& operator>>(istream& istr, Container& con) {
        return (con.read(istr));
    }
}