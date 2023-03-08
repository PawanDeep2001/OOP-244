/* Citation and Sources...
Final Project Milestone 4
Module: Utils
Filename: Utils.cpp
Version 1.0
Author	Name   :Pawan Deep
        ID     :111144218
        Email  :pdeep1@myseneca.ca
        Date   :03/31/2022
Revision History
-----------------------------------------------------------
Date      Reason
03/31/2022  Preliminary release
03/31/2022  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstring>
#include "Utils.h"
using namespace std;
namespace sdds {
    // The ut object of type Utils that is accessible to any file including "Utils.h" to call the Utils
    // methods
    Utils ut;

    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    void Utils::alocpy(char*& destination, const char* source) {
        if (destination!=nullptr)
        {
            delete[] destination;
            destination = nullptr;
        }
        if (source!= nullptr)
        {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }
    int Utils::getint(const char* prompt) {
        int number=0;
        if (prompt!=nullptr)
        {
            cout << prompt;
            cin >> number;

            if (number%1!=0)
            {
                do
                {
                    cout << "Invalid Integer, retry: ";
                    cin >> number;
                } while (number%1!=0);
            }
        }
        return number;
    }
    int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
        int number=0;
        do
        {
            number = getint(prompt);
            if (errMes!=nullptr)
            {
                cout << errMes << ", retry: ";
            }
            else
            {
                cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
            }
        } while (number<min || number>max);
        return number;
    }
}