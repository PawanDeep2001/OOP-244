/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :02/02/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Train.h"
namespace sdds {
    void Train::set(const char* names, int num, double speeds) {
        int length=0;
        if (names!=nullptr)
        {
            length = strlen(names);
        }
        if (names!=nullptr && length!=0 && num>=0 && num<= MAX_PEOPLE && speeds>=0 && speeds<=MAX_SPEED)
        {
            strcpy(name, names);
            numpeople = num;
            speed = speeds;
        }
        else
        {
            //set to safe empty state name="", empty string, 
            //set to safe empty state numpeople=-1, outside the range of the max and min people, 
            //set to safe empty state speed=-1, outside the range of the max and min speed.
            strcpy(name, "");
            numpeople = -1;
            speed = -1;
        }
    }
    int Train::getNumberOfPeople() const {
        return numpeople;
    }
    const char* Train::getName() const {
        return name;
    }
    double Train::getSpeed() const{
        return speed;
    }
    bool Train::isSafeEmpty() const {
        bool ans=true;
        if (numpeople!=-1)
        {
            ans = false;
        }
        return ans;
    }
    void Train::display() const {
        if (numpeople!=-1)
        {
            cout << "NAME OF THE TRAIN : " << name << endl;
            cout << "NUMBER OF PEOPLE  : " << numpeople << endl;
            cout << fixed << setprecision(2) << "SPEED             : " << speed << " km/h" << endl;
        }
        else
        {
            cout << "Safe Empty State!" << endl;
        }
        
    }
    bool Train::loadPeople(const int num) {
        bool ans = false;
        if (numpeople!=-1)
        {
            if (numpeople + num >= 0 && numpeople + num <= MAX_PEOPLE)
            {
                numpeople = numpeople + num;
                ans = true;
            }
            else if (numpeople + num < 0)
            {
                ans = true;
                numpeople = 0;
            }
            else if (numpeople + num > MAX_PEOPLE)
            {
                ans = true;
                numpeople = MAX_PEOPLE;
            }
        }
        
        return ans;
    }
    bool Train::changeSpeed(const int num) {
        bool ans = false;
        if (speed!=-1)
        {
            if (speed + num >= 0 && speed + num <= MAX_SPEED)
            {
                ans = true;
                speed = speed + num;
            }
            else if (speed + num < 0)
            {
                ans = true;
                speed = 0;
            }
            else if (speed + num > MAX_SPEED)
            {
                ans = true;
                speed = MAX_SPEED;
            }
        }
        
        return ans;
    }
    int transfer(Train &tr1, Train &tr2) {
        bool ans1 = tr1.isSafeEmpty();
        bool ans2 = tr2.isSafeEmpty();
        int people1 = tr1.getNumberOfPeople();
        int people2 = tr2.getNumberOfPeople();
        int exceed = 0;
        int transferred = -1;
        if (ans1!= true && ans2!=true)
        {
            if ((people2+people1)<=MAX_PEOPLE)
            {
                tr1.loadPeople(people2);
                tr2.loadPeople(-people2);
                transferred = people2;
            }
            else if((people1+people2)>MAX_PEOPLE)
            {
                exceed = MAX_PEOPLE - people1;
                tr1.loadPeople(exceed);
                tr2.loadPeople(-exceed);
                transferred = exceed;
            }
        }
        return transferred;
    }
}