/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :01/25/2022
*/

#ifndef _CAR_H // replace with relevant names
#define _CAR_H
namespace sdds {
    struct Car
    {
        char numPlate[9];
        char *makeModel;
        int time;
    };
    void VBPLE_Title();
    void initialize(int allocSize);
    bool read(Car& C);
    void deallocate(Car& C);
    void print(const Car& C);
    void record(const Car& C);
    void endOfDay();
}


#endif