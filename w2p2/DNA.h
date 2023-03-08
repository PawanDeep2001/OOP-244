/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :01/31/2022
*/
#ifndef _DNA_H // replace with relevant names
#define _DNA_H
namespace sdds {
    struct DNA
    {
        int id;
        char* numdna;
    };
    bool beginSearch(const char* filename);
    bool read(const char* subDNA);
    void sort();
    void displayMatches();
    void deallocate();
    void endSearch();
}
#endif