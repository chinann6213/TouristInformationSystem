/*************************************
Program: Culture.h
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef CULTURE_H
#define CULTURE_H

#include "Attraction.h"
#include <iostream>

#include <string>
#include <fstream>
#include <cstdlib> //to convert cstring

using namespace std;

class Culture: public Attraction
{
    private:

        double entranceFee;
        string type; //religious or historical
        string information;
        string facility;

    public:

        Culture();
        Culture(int typeID, string name, string openHrs, string openDay, string address, string contact, double entranceFee, string type, string information, string facility);
        Culture(ifstream& info); // helps to load the data into the variables
        ~Culture();

        void setEntranceFee(double entranceFee);
        void setCultureType(string type);
        void setInfo(string information);
        void setFacility(string facility);
        void display(); //function to display the information of selected culture attraction

        ostream& output(ostream& out);  // Function to help overloading extraction operator
        istream& input(istream& in); // Function to help overloading insertion operator
};

#endif // CULTURE_H
