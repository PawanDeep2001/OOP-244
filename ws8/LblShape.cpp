/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/22/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "LblShape.h"
using namespace std;
namespace sdds {
    LblShape::LblShape(){
        if (m_label!=nullptr)
        {
            m_label = nullptr;
        }
    }
    LblShape::LblShape(const char* lab) {
        if (lab!=nullptr)
        {
            m_label = new char[strlen(lab)+1];
            strcpy(m_label, lab);
        }
    }
    const char* LblShape::label()const {
        return m_label;
    }
    LblShape::~LblShape() {
        delete[] m_label;
        m_label = nullptr;
    }
    void LblShape::getSpect(istream& istr) {
        char temp[50];
        istr.getline(temp, 50, ',');
        istr.clear();
        if (temp[0]!=' ')
        {
            delete[] m_label;
            m_label = nullptr;
            m_label = new char[strlen(temp) + 1];
            strcpy(m_label, temp);
        }
    }
    
}