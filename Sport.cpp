/*************************************
Program: Sport.cpp
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef SPORT_CPP
#define SPORT_CPP

#include "Attraction.h"
#include "Sport.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib> //to convert cstring

using namespace std;

//implementation of function in class sport(functions is explained in header file).
Sport::Sport(){}

Sport::Sport(int typeID, string name, string openHrs, string openDay, string address, string contact, int ageLim, double entrance, string type, string sportName)
: Attraction(typeID, name, openHrs, openDay, address, contact), ageLim(ageLim), entrance(entrance), type(type), sportName(sportName)
{}

istream& operator >> (istream &in, Sport &info) //overloaded operator >> to load data
{
    return info.input(in);
}

Sport::Sport(ifstream& info)
{
    info >> *this; //load data into the variables
}

void Sport::setAgeLimit(int ageLim)
{
    this -> ageLim = ageLim;
}

void Sport::setEntranceFee(double entrance)
{
    this -> entrance = entrance;
}

void Sport::setSportType(string type)
{
    this -> type = type;
}

void Sport::setSportName(string sportName)
{
    this -> sportName = sportName;
}

void Sport::display()
{
    cout << getName() << " (Sport Attraction)" << endl
         << "_________________________________________________________" << endl
         << "Opening hour  : " << getOpenHrs() << endl
         << "Opening days  : " << getDay() << endl
         << "Address       : " << getAddress() << endl
         << "Contact number: " << getContact() << endl
         << "Age limit     : " << ageLim << endl
         << "Entrance fee  : " <<"RM " << fixed << setprecision(2) << entrance << endl
         << "Sport type    : " << type << endl
         << "Sport can do  : " << sportName << endl << endl;
}

ostream& Sport::output (ostream& out)
{
    Attraction::output(out);
    out << ageLim << "\n" << entrance << "\n" << type << "\n" << sportName << "\n";
    return out;
}

istream& Sport::input(istream& in)
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

    getline(in, info);
    ageLim = atoi(info.c_str()); //convert string into integer

    getline(in, info);
    entrance = atof(info.c_str()); //convert string into double

    getline(in, type);
    getline(in, sportName);

    return in;
}

Sport::~Sport(){}

#endif // SPORT_CPP
