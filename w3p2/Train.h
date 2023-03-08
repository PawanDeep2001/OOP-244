/*
    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Name   :Pawan Deep
    ID     :111144218
    Email  :pdeep1@myseneca.ca
    Date   :02/02/2022
*/

#ifndef _TRAIN_H // replace with relevant names
#define _TRAIN_H
#define MAX_NAME_LEN 20
#define MAX_PEOPLE 1000
#define MAX_SPEED 320
namespace sdds {
    class Train {
        char name[MAX_NAME_LEN];
        int numpeople;
        double speed;
    public:
        void set(const char* names, int num, double speeds);
        int getNumberOfPeople() const;
        const char* getName() const;
        double getSpeed() const;
        bool isSafeEmpty() const;
        void display() const;
        bool loadPeople(const int num);
        bool changeSpeed(const int num);
    };
    int transfer(Train &tr1,Train &tr2);
}

#endif
