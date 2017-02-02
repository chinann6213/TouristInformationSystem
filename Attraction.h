/*************************************
Program: Attraction.h
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef ATTRACTION_HPP
#define ATTRACTION_HPP

#include "LinkedList.cpp"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Attraction
{
    private:

        int typeID;
        string name, openHrs, openDay, address, contact;

    public:

        Attraction();
        Attraction(int typeID, string name, string openHrs, string openDay, string address, string contact);
        virtual ~Attraction();

        virtual void display() = 0;

        void settypeID(int typeID);
        void setName(string name);
        void setHrs(string openHrs);
        void setDay(string openDay);
        void setAddress(string address);
        void setContact(string contact);

        int gettypeID();
        string getName();
        string getOpenHrs();
        string getDay();
        string getAddress();
        string getContact();

        virtual ostream& output(ostream& out);// Function to help overloading extraction operator
        virtual istream& input(istream& in) = 0; // Function to help overloading insertion operator
};

#endif // end ATTRACTION_H

