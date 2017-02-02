/*************************************
Program: Sport.h
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef SPORT_H
#define SPORT_H

#include "Attraction.h"
#include <iostream>

#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib> //to convert cstring

using namespace std;

class Sport: public Attraction
{
    private:

        int ageLim;
        double entrance;
        string type; //individual/group
        string sportName; //type of sport can be done

    public:

        Sport();
        Sport(int typeID, string name, string openHrs, string openDay, string address, string contact, int ageLim, double entrance, string type, string sportName);
        Sport(ifstream& info); // helps to load the data into the variables
        ~Sport();

        void setAgeLimit(int ageLim);
        void setEntranceFee(double entrance);
        void setSportType(string type);
        void setSportName(string sportName);
        void display(); //function to display the information of selected sport attraction

        ostream& output(ostream& out); // Function to help overloading extraction operator
        istream& input(istream& in); // Function to help overloading insertion operator
};

#endif // SPORT_H
