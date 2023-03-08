/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :03/07/2022
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Name.h"
using namespace std;
namespace sdds {
    void Name::setEmpty(){
        FName = nullptr;
        MName = nullptr;
        LName = nullptr;
        s = false;
    }
    void Name::set(const char* fname ,const char* lname, const char* mname) {
        if (fname != nullptr)
        {
            delete[] FName;
            FName = nullptr;
            FName = new char[strlen(fname) + 1];
            strcpy(FName, fname);
        }
        if (mname != nullptr)
        {
            delete[] MName;
            MName = nullptr;
            MName = new char[strlen(mname) + 1];
            strcpy(MName, mname);
        }
        if (lname != nullptr)
        {
            delete[] LName;
            LName = nullptr;
            LName = new char[strlen(lname) + 1];
            strcpy(LName, lname);
        }
    }
    bool Name::valid(const char* name)const {
        bool ans = true;
        if (name == nullptr || name[0]==' ' || strlen(name) == 0)
        {
            ans= false;
        }
        return ans;
    }
    Name::Name(){
        setEmpty();
    }
    Name::Name(const char* fname) {
        if (valid(fname))
        {
            setEmpty();
            FName = new char[strlen(fname) + 1];
            strcpy(FName, fname);

        }
        else
        {
            setEmpty();
        }
    }
    Name::Name(const char* fname, const char* lname) {
        if (valid(fname)) {
            setEmpty();
            FName = new char[strlen(fname) + 1];
            strcpy(FName, fname);
            LName = new char[strlen(lname) + 1];
            strcpy(LName, lname);
        }
        else
        {
            setEmpty();
        }
    }
    Name::Name(const char* fname, const char* mname, const char* lname) {
        if (valid(fname))
        {
            setEmpty();
            FName = new char[strlen(fname) + 1];
            strcpy(FName, fname);
            MName = new char[strlen(mname) + 1];
            strcpy(MName, mname);
            LName = new char[strlen(lname) + 1];
            strcpy(LName, lname);
        }
        else
        {
            setEmpty();
        }
        
    }
    Name::Name(const Name& n) {

        if (bool(n))
        {
            setEmpty();
            *this = n;
        }
    }
    Name& Name::operator=(const Name& n) {
        if (this!=&n)
        {
            if (bool(n))
            {
                delete[] FName;
                FName = nullptr;
                FName = new char[strlen(n.FName) + 1];
                strcpy(FName, n.FName);
                if (valid(n.MName))
                {
                    delete[] MName;
                    MName = nullptr;
                    MName = new char[strlen(n.MName) + 1];
                    strcpy(MName, n.MName);
                }
                if (valid(n.LName))
                {
                    delete[] LName;
                    LName = nullptr;
                    LName = new char[strlen(n.LName) + 1];
                    strcpy(LName, n.LName);
                }
            }
            else
            {
                delete[] FName;
                FName = nullptr;
                delete[] MName;
                MName = nullptr;
                delete[] LName;
                LName = nullptr;
            }
        }
        
        return *this;
    }
    Name::~Name() {
        delete[] FName;
        FName = nullptr;
        delete[] MName;
        MName = nullptr;
        delete[] LName;
        LName = nullptr;
    }
    void Name::setShort(bool ans) {
        if (ans==true )
        {
            s = true;
        }
    }
    Name& Name::operator +=(const char str[]) {
        bool space = false;
            for (int i = 0; str[i]=='\0'; i++)
            {
                if (str[i]==' ')
                {
                    space = true;
                }
            }
            if (strcmp(str, "   ")==0|| strcmp(str,"") == 0)
            {
                space = true;
            }
            if (space == false)
            {
                if (!valid(FName)) {

                    delete[] FName;
                    FName = nullptr;
                    FName = new char[strlen(str) + 1];
                    strcpy(FName, str);
                }
                else if (!valid(MName)) {

                    delete[] MName;
                    MName = nullptr;
                    MName = new char[strlen(str) + 1];
                    strcpy(MName, str);
                }
                else if (!valid(LName)) {
                    delete[] LName;
                    LName = nullptr;
                    LName = new char[strlen(str) + 1];
                    strcpy(LName, str);
                }
                else
                {
                    delete[] FName;
                    delete[] MName;
                    delete[] LName;
                    setEmpty();
                }
            }
        
        return *this;
    }
    Name::operator bool() const {
        return valid(FName);
    }
    istream& Name::read(istream& istr) {
        char fname[50];
        char mname[50];
        char lname[50];
        char a;
        delete[] FName;
        FName = nullptr;
        delete[] MName;
        MName = nullptr;
        delete[] LName;
        LName = nullptr;
        istr >> fname;
        a = istr.peek();
        if (a==' ')
        {
            a = '\0';
            istr >> mname;
            a = istr.peek();
            if (a==' ')
            {
                a = '\0';
                
                istr >> lname;
                a = istr.peek();
                if (a==' ')
                {
                    setEmpty();
                } 
                else
                {
                    a = '\0';
                    if (istr.fail())
                    {
                        istr.clear();
                        istr.ignore(1000, '\n');
                    }
                    else
                    {

                        set(fname, lname, mname);
                    }
                }
            }
            else 
            {
                if (!istr.fail())
                {
                    set(fname, mname);
                }

                
            }
        }
        else 
        {
            if (!istr.fail())
            {
                set(fname);
            }

        }
        return istr;
    }
    istream& operator>>(istream& istr, Name& n) {
        return n.read(istr);
    }
    ostream& Name::printName(ostream& ostr, bool ans) const {

            if (MName != nullptr && FName != nullptr && LName != nullptr)
            {
                if (s== true)
                {
                    ostr << FName << " " << MName[0] << '.' << " " << LName;
                }
                else
                {
                    ostr << FName << " " << MName << " " << LName;
                }
                
            }
            else if (FName!=nullptr && LName!=nullptr)
            {
                ostr << FName << " " << LName;
            }
            else if (FName != nullptr && MName != nullptr)
            {
                ostr << FName << " " << MName;
            }
            else if (FName!= nullptr)
            {
                ostr << FName;
            }
            
        return ostr;
    }
    ostream& operator<<(ostream& ostr, const Name& n) {
        int c = 0;
        if (n.operator bool())
        {
            n.printName(ostr, false);
        } 
        else
        {
            ostr << "Bad Name";
            if (c==1)
            {
                cin.putback('\n');
            }
            c++;
        }
        return ostr;
    }
}