/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :01/22/2022
*/
#ifndef _PHONE_H // replace with relevant names
#define _PHONE_H
namespace sdds {
    struct numDatabase
    {
        char name[51];
        char area[51];
        char prefix[10];
        char number[10];
    };
    void phoneDir(const char* programTitle, const char* fileName);
}
#endif