/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :02/12/2022
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Robot.h"
namespace sdds {
    void Robot::resetInfo() {
        name = nullptr;
        location = nullptr;
        weight = -1;
        width = -1;
        height = -1;
        speed = -1;
        deployed = false;
    }
    Robot::Robot() {
        resetInfo();
    }
    Robot::~Robot() {
        delete[] name;
        name = nullptr;
        delete[] location;
        location = nullptr;
    }
    Robot::Robot(const char* names, const char* locations, double weights, double widths, double heights, double speeds, bool deployments) {
        name = nullptr;
        location = nullptr;
        name = new char[strlen(names) + 1];
        location = new char[strlen(locations) + 1];
        strcpy(name, names);
        strcpy(location, locations);
        weight = weights;
        width = widths;
        height = heights;
        speed = speeds;
        deployed = deployments;
    }
    Robot& Robot::set(const char* names, const char* locations, double weights, double widths, double heights, double speeds, bool deployments) {
        delete[] name;
        delete[] location;
        name = nullptr;
        location = nullptr;
        name = new char[strlen(names) + 1];
        location = new char[strlen(locations) + 1];
        strcpy(name, names);
        strcpy(location, locations);
        weight = weights;
        width = widths;
        height = heights;
        speed = speeds;
        deployed = deployments;
        return *this;
    }
    Robot& Robot::setLocation(const char* locations) {
        location = nullptr;
        location = new char[strlen(locations) + 1];
        strcpy(location, locations);
        return *this;
    }
    Robot& Robot::setDeployed(bool deployment) {
        deployed = deployment;
        return *this;
    }
    const char* Robot::getName() const{
        return name;
    }
    const char* Robot::getLocation() const{
        return location;
    }
    bool Robot::isDeployed() const {
        return deployed;
    }
    bool Robot::isValid() const {
        bool ans = true;
        if (name==nullptr||location==nullptr|| weight<=0|| width<=0|| height<=0|| speed<=0)
        {
            ans = false;
        }
        return ans;
    }
    void Robot::display() const {
        if (deployed == true)
        {
            cout << "| " << left << setw(11) << name << "| " << left << setw(16) << location << "| " << right << setw(6) << fixed << setprecision(1) << weight << " | " << right << setw(6) << fixed << setprecision(1) << width << " | " << right << setw(6) << fixed << setprecision(1) << height << " | " << right << setw(6) << fixed << setprecision(1) << speed << " | " << left << setw(9) << "YES" << "|" << endl;

        }
        else
        {
            cout << "| " << left << setw(11) << name << "| " << left << setw(16) << location << "| " << right << setw(6) << fixed << setprecision(1) << weight << " | " << right << setw(6) << fixed << setprecision(1) << width << " | " << right << setw(6) << fixed << setprecision(1) << height << " | " << right << setw(6) << fixed << setprecision(1) << speed << " | " << left << setw(9) << "NO" << "|" << endl;

        }

    }
    double Robot::Speed() const {
        return speed;
    }
    int conrtolRooomReport(const Robot robot[], int num_robots) {
        int i = 0;
        int index = 0;
        double max = 0;
        int count = 0;
        cout << "                        ------ Robot Control Room -----" << endl;
        cout << "                    ---------------------------------------" << endl;
        cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
        cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
        for ( i = 0; i < num_robots; i++)
        {
            
            if (robot[i].isValid())
            {
                robot[i].display();
                if (robot[i].Speed()>max)
                {
                    max = robot[i].Speed();
                    index = i;
                }
                if (robot[i].isDeployed())
                {
                    count++;
                }
            }
            else
            {
                return i;
            }
        }
        cout << "|=============================================================================|" << endl;
        cout << "| SUMMARY:                                                                    |" << endl;
        cout << "| "<< count <<"  robots are deployed.                                                     |" << endl;
        cout << "| The fastest robot is:                                                       |" << endl;
        cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
        cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
        robot[index].display();
        cout << "|=============================================================================|" << endl;
        return -1;
    }
}