/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :01/25/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include  <iostream>
#include "cStrTools.h"

using namespace std;
namespace sdds {
    Car *cars=nullptr;
    int allSize;
    int numCars;
    int arrSize;
    void VBPLE_Title()
    {
        cout << "Vehicle Border Passing Log Entry" << endl << "Enter the data in the following format:" << endl;
        cout << "Make and model,LicensePlate,MilitaryTime<ENTER>" << endl << "Exit the program by entering the following:" << endl << "X,<ENTER>" << endl;
    }

    void initialize(int allocSize)
    {
        numCars = 0;
        allSize = allocSize;
        arrSize = allocSize;
        cars = new Car[allSize];
    }
    void deallocate(Car& C)
    {
        delete[] C.makeModel;
        C.makeModel = nullptr;
    }
    bool read(Car& C)
    {
        bool flag = false;
        char mkModel[61];
        read(mkModel, 61, ',');
        if (mkModel[0]!='X')
        {
            flag = true;
            C.makeModel = nullptr;
            C.makeModel = new char[62];
            strCpy(C.makeModel, mkModel);
            read(C.numPlate, 9, ',');
            cin >> C.time;
        }
        return flag;
    }
    void print(const Car& C)
    {
        cout << C.time << ": " << C.makeModel << "," << C.numPlate << endl;
    }
    void record(const Car& C)
    {
        int i;
        int temparr;
        if (numCars==arrSize)
        {
            Car* moreCars = nullptr;
            temparr = arrSize + allSize;
            moreCars = new Car[arrSize+allSize];
            for (i = 0; i < arrSize; i++)
            {
                moreCars[i].makeModel = cars[i].makeModel;
                strCpy(moreCars[i].numPlate, cars[i].numPlate);
                moreCars[i].time = cars[i].time;
            }
            delete[] cars;
            cars = nullptr;
            arrSize = temparr;
            cars = moreCars;
            moreCars = nullptr;
        }
        cars[numCars].makeModel= C.makeModel;
        cars[numCars].time = C.time;
        strCpy(cars[numCars].numPlate, C.numPlate);
        numCars++;
    }
    void endOfDay()
    {
        int i;
        for ( i = 0; i < numCars; i++)
        {
            print(cars[i]);
            deallocate(cars[i]);
        }
        delete[] cars;
        cars = nullptr;
    } 
}