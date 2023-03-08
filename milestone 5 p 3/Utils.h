/* Citation and Sources...
Final Project Milestone 53
Module: Utils
Filename: Utils.h
Version 1.0
Author	Name   :Pawan Deep
        ID     :111144218
        Email  :pdeep1@myseneca.ca
        Date   :04/05/2022
Revision History
-----------------------------------------------------------
Date      Reason
04/05/2022  Preliminary release
04/05/2022  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
namespace sdds {
    // Testing date values for application testing and debugging
    // these values must not change at submission time.
    const int sdds_testYear = 2022;
    const int sdds_testMon = 03;
    const int sdds_testDay = 31;
    class Utils {
        bool m_testMode = false;
    public:
        // this function will be used to get the current system date or the test date if m_testMode is true
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        // this function will return the number of days in a month based on the year
        // 1<=mon<=12  year: four digit number (example: 2021)
        int daysOfMon(int mon, int year)const;
        // Puts the system date in test mode, where getSystemDate() function will return 2022, 03, 31
        // or whatever the three constant test dates are set to
        void testMode(bool testmode = true);
        void alocpy(char*& destination, const char* source);
        int getint(const char* prompt = nullptr);
        int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
    };
    extern Utils ut;  // provides global access to the ut instance in the Utils.cpp file
}