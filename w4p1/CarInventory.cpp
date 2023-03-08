/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :02/08/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "CarInventory.h"
namespace sdds {
    CarInventory::CarInventory()
    {
        resetInfo();
    }

    CarInventory::~CarInventory()
    {
        delete[] m_type;
        m_type = nullptr;
        delete[] m_model;
        m_model = nullptr;
        delete[] m_brand;
        m_brand = nullptr;
    }
    CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
        if (type != nullptr || brand != nullptr || model != nullptr || year >= 1990 || code >= 100 || code < 1000 || price > 0)
        {
            m_type = nullptr;
            m_brand = nullptr;
            m_model = nullptr;
            m_type = new char[strlen(type) + 1];
            strcpy(m_type, type);
            m_brand = new char[strlen(brand) + 1];
            strcpy(m_brand, brand);
            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);
            m_year = year;
            m_code = code;
            m_price = price;
        }
        else
        {
            resetInfo();
        }
    }

    void CarInventory::resetInfo() {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0;
    }

    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
        if (type != nullptr || brand != nullptr || model != nullptr || year >= 1990 || code >= 100 || code < 1000 || price > 0)
        {
            delete[] m_type;
            delete[] m_brand;
            delete[] m_model;
            m_type = new char[strlen(type) + 1];
            strcpy(m_type, type);
            m_brand = new char[strlen(brand) + 1];
            strcpy(m_brand, brand);
            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);
            m_year = year;
            m_code = code;
            m_price = price;
        }
        else
        {
            resetInfo();
        }
        return *this;
    }
    void CarInventory::printInfo() const {
        cout << "| " << left << setw(11) << m_type << "| " << left << setw(17) << m_brand << "| " << left << setw(17) << m_model << "| " << left << setw(5) << m_year << "|  " << left << setw(4) << m_code << "| " << right << setw(9) << fixed << setprecision(2) << m_price << " |" << endl;
    }
    bool CarInventory::isValid() const {
        bool ans = true;
        if (m_type==nullptr|| m_brand==nullptr||m_model==nullptr||m_year<1990|| m_code<100||m_code>1000|| m_price<1)
        {
            ans = false;
        }
        return ans;
    }
    bool CarInventory::isSimilarTo(const CarInventory& car) const {
        bool ans = false;
        
        if (m_brand!=nullptr)
        {
            if (strcmp(car.m_brand, m_brand)==0&& strcmp(car.m_type, m_type)==0 && strcmp(car.m_model, m_model)==0&& m_year==car.m_year)
            {
                ans = true;
            }
        }
        return ans;
    }
    bool find_similar(CarInventory car[], const int num_cars) {
        bool ans = false;
        
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car[i].isSimilarTo(car[j])) {
                    ans = true;
                }
            }
        }
        return ans;
    }
}