/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :02/12/2022
*/
#ifndef _ROBOT_H // replace with relevant names
#define _ROBOT_H
namespace sdds {
    class Robot
    {
        char* name;
        char* location;
        double weight;
        double width;
        double height;
        double speed;
        bool deployed;
        void resetInfo();
    public:
        Robot();
        ~Robot();
        Robot(const char* names, const char* locations, double weights, double widths, double heights, double speeds, bool deployments);
        Robot& set(const char* names, const char* locations, double weights, double widths, double heights, double speeds, bool deployments);
        Robot& setLocation(const char* locations);
        Robot& setDeployed(bool deployment);
        const char* getName() const;
        const char* getLocation() const;
        bool isDeployed() const;
        bool isValid() const;
        void display() const;
        double Speed() const;
    };
    int conrtolRooomReport(const Robot robot[], int num_robots);
}

#endif
