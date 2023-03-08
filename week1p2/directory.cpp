/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :01/22/2022
*/
#include <iostream>
#include "Phone.h"
using namespace sdds;
int main() {
    std::cout << "Enter the following Data:" << std::endl
        << "----------------------\n"
        "lukE\nsky\nfett\nfeT\nJack\n!\n"
        "----------------------\n";
    phoneDir("Star Wars", "phones.txt");
    std::cout << std::endl << "----------------------------------" << std::endl;
    phoneDir("Broken Phone Book", "badDataFile.txt");
    return 0;
}