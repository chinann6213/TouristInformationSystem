/*************************************
Program: Restaurant.cpp
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef RESTAURANT_CPP
#define RESTAURANT_CPP

#include "Attraction.h"
#include "Restaurant.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> //to convert cstring

using namespace std;

//implementation of function in class restaurant(functions is explained in header file).
Restaurant::Restaurant(){}

Restaurant::Restaurant(int typeID, string name, string openHrs, string openDay, string address, string contact, string highlight, string food, string price)
:Attraction(typeID, name, openHrs, openDay, address, contact), highlight(highlight), food(food), price(price){}

istream& operator >> (istream &in, Restaurant &info) //overloaded operator >> to load data
{
    return info.input(in);
}

Restaurant::Restaurant(ifstream& info)
{
    info >> *this; //load data into the variables
}

void Restaurant::setHighlight(string highlight)
{
    this -> highlight = highlight;
}

void Restaurant::setFood(string food)
{
    this -> food = food;
}

void Restaurant::setPrice(string price)
{
    this -> price = price;
}

void Restaurant::display() //display the information of the attractions
{
    cout << getName() << " (Restaurant)" << endl
         << "_________________________________________________________" << endl
         << "Opening hour       : " << getOpenHrs() << endl
         << "Opening days       : " << getDay() << endl
         << "Address            : nearby" << getAddress() << endl
         << "Reservation Hotline: " << getContact() << endl
         << "Highlights         : " << highlight << endl
         << "Food type          : " << food << endl
         << "Price range        : RM" << fixed << setprecision(2) << price << endl << endl;
}

ostream& Restaurant::output (ostream& out)
{
    Attraction::output(out); //common attribute from super class
    out << highlight << "\n" << food << "\n" << price << "\n";
    return out;
}

istream& Restaurant::input(istream& in)
{
    string info;

    getline(in, info);
    int typeID = atoi(info.c_str()); //convert string into integer
    settypeID(typeID);

    getline(in, info);
    setName(info);

    getline(in, info);
    setHrs(info);

    getline(in, info);
    setDay(info);

    getline(in, info);
    setAddress(info);

    getline(in, info);
    setContact(info);

    getline(in, highlight);
    getline(in, food);
    getline(in, price);

    return in;
}

Restaurant::~Restaurant(){}

#endif // RESTAURANT_CPP
