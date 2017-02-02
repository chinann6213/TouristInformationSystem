/*************************************
Program: Shopping.h
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef SHOPPING_H
#define SHOPPING_H

#include "Attraction.h"
#include "LinkedList.cpp"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> //to convert cstring

using namespace std;

class Shopping: public Attraction
{
    private:

        double tax;
        int discount, position; // position of mall
        LinkedList <string> mall; // Linked list to store shopping mall's name

    public:

        Shopping();
        Shopping(int typeID, string name, string openHrs, string openDay, string address, string contact, double tax, int discount, LinkedList <string> mall);
        Shopping(ifstream& info); // helps to load the data into the variables
        ~Shopping();

        void setTax(double tax);
        void setDiscount(int discount);
        void setMall(int position, string editMall);
        string getMall(int position);
        int getMallLength(); // get the size of mall
        void display(); //function to display the information of selected shopping mall
        void clearMall(); // clear the linked list mall for reuse purpose

        ostream& output (ostream& out); // Function to help overloading extraction operator
        istream& input(istream& in); // Function to help overloading insertion operator
};

#endif // SHOPPING_H
