/*************************************
Program: Restaurant.h
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Attraction.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> //to convert cstring

using namespace std;

class Restaurant:public Attraction
{
    private:

        string highlight; //highlights of the restaurant
        string food; //the type of food
        string price; //price range

    public:

        Restaurant();
        Restaurant(int typeID, string name, string openHrs, string openDay, string address, string contact, string highlight, string food, string price);
        Restaurant(ifstream& info); // helps to load the data into the variables
        ~Restaurant();

        void setHighlight(string highlight);
        void setFood(string food);
        void setPrice(string price);
        void display(); //function to display the information of selected restaurant

        ostream& output (ostream& out); // Function to help overloading extraction operator
        istream& input(istream& in); // Function to help overloading insertion operator
};

#endif // RESTAURANT_H
