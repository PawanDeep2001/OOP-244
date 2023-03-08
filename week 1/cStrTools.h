/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :01/19/2022
*/
#ifndef _CSTRTOOLS_H // replace with relevant names
#define _CSTRTOOLS_H
namespace sdds {
    char toLower(char ch);
    int strCmp(const char* s1, const char* s2);
    int strnCmp(const char* s1, const char* s2, int len);
    void strCpy(char* des, const char* src);
    int strLen(const char* str);
    const char* strStr(const char* str, const char* find);
    int isAlpha(char ch);
    int isSpace(char ch);
    void trim(char word[]);
    void toLowerCaseAndCopy(char des[], const char source[]);
}
#endif

