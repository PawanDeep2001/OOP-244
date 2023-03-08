/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :04/13/2022
*/
#include <iostream>
#include "Collection.h"
#include "Car.h"
#include "Employee.h"
#include "Student.h"
#include "Collection.h"
using namespace std;
namespace sdds {
    Collection<Employee> select(Employee emp[], int size, Employee& e) 
    {
        int c = 0;
        int j = 0;
        int i = 0;
        for (i = 0; i < size; ++i)
        {
            if (emp[i] == e)
            {
                c++;
            }
        }
        Collection<Employee> dbls(c);

        for (i = 0; i < size; ++i)
        {
            if (emp[i] == e)
            {
                dbls[j++] = emp[i];
            }
        }
        return dbls;
    }
    Collection<Car> select(Car car[], int size, Car& ca) 
    {
        int c = 0;
        int j = 0;
        int i = 0;
        for (i = 0; i < size; ++i)
        {
            if (car[i] == ca)
            {
                c++;
            }
        }
        Collection<Car> dbls(c);

        for (i = 0; i < size; ++i)
        {
            if (car[i] == ca)
            {
                dbls[j++] = car[i];
            }
        }
        return dbls;
    }
    Collection<Student> select(Student stud[], int size, Student& stu) 
    {
        int c = 0;
        int j = 0;
        int i = 0;
        for (i = 0; i < size; ++i)
        {
            if (stud[i] == stu)
            {
                c++;
            }
        }
        Collection<Student> dbls(c);

        for (i = 0; i < size; ++i)
        {
            if (stud[i] == stu)
            {
                dbls[j++] = stud[i];
            }
        }
        return dbls;
    }
    Collection<int> select(int arrey[], int size, int& num) 
    {
        int c = 0;
        int j = 0;
        int i = 0;
        for (i = 0; i < size; ++i)
        {
            if (arrey[i] == num)
            {
                c++;
            }
        }
        Collection<int> dbls(c);

        for (i = 0; i < size; ++i)
        {
            if (arrey[i] == num)
            {
                dbls[j++] = arrey[i];
            }
        }
        return dbls;
    }
    void printCollection(Collection<int>& col, const char* st) 
    {
        cout << st << "\n";
        for (unsigned i = 0; i < col.size(); i++)
        { 
            cout << col[i];
            cout << "\n"; 
        }
    }
    template <typename T>
    void printCollection(Collection<T>& col, const char* st) 
    {
        cout << st << "\n";
        for (unsigned i = 0; i < col.size(); i++)
        {
            col[i].display(cout);
            cout << "\n"; 
        }
    }
};
