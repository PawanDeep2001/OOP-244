/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :02/08/2022
*/
#ifndef _CARINVENTORY_H // replace with relevant names
#define _CARINVENTORY_H
namespace sdds {
    class CarInventory
    {
        char* m_type;
        char* m_brand;
        char* m_model;
        int m_year;
        int m_code;
        double m_price;
        void resetInfo();
    public:
        CarInventory();
        ~CarInventory();
        CarInventory(const char* type, const char* brand, const char* model, int year=2022, int code=100, double price=1);
        CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const CarInventory& car) const;
    };
    bool find_similar(CarInventory car[], const int num_cars);
}

#endif
