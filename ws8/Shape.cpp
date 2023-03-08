/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/22/2022
*/
#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds {
    ostream& operator<<(ostream& ostr, const Shape& s) {
        s.draw(ostr);
        return ostr;
    }

    istream& operator>>(istream& istr, Shape& s) {
        s.getSpect(istr);
        return istr;
    }
}