/*************************************
Program: Culture.cpp
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef CULTURE_CPP
#define CULTURE_CPP

#include "Attraction.h"
#include "Culture.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> //to convert cstring

using namespace std;

//implementation of function in class culture(functions is explained in header file).
Culture::Culture(){}

Culture::Culture(int typeID, string name, string openHrs, string openDay, string address, string contact, double entranceFee, string type, string information, string facility)
: Attraction(typeID, name, openHrs, openDay, address, contact), entranceFee(entranceFee), type(type), information(information), facility(facility)
{}

istream& operator >> (istream &in, Culture &info) //overloaded operator >> to load data
{
    return info.input(in);
}

Culture::Culture(ifstream& info)
{
    info >> *this; //load data into the variables
}

void Culture::setEntranceFee(double entranceFee)
{
    this -> entranceFee = entranceFee;
}

void Culture::setCultureType(string type)
{
    this -> type = type;
}

void Culture::setInfo(string information)
{
     this -> information = information;
}

void Culture::setFacility(string facility)
{
    this -> facility = facility;
}

void Culture::display()
{
    cout << getName() << " (Cultural Attractions)" << endl
         << "_________________________________________________________" << endl
         << "Opening hour  : " << getOpenHrs() << endl
         << "Opening days  : " << getDay() << endl
         << "Address       : " << getAddress() << endl
         << "Contact number: " << getContact() << endl
         << "Entrance fee  : RM " << fixed << setprecision(2) << entranceFee << endl
         << "Culture Type  : " << type << endl
         << "Brief info.   : " << information << endl
         << "Facility      : " << facility << endl << endl;
}

ostream& Culture::output (ostream& out)
{
    Attraction::output(out);
    out << entranceFee << "\n" << type << "\n" << information << "\n" << facility << "\n";
    return out;
}

istream& Culture::input(istream& in)
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
    entranceFee = atof(info.c_str()); //convert string into double

    getline(in, type);
    getline(in, information);
    getline(in, facility);

    return in;
}

Culture::~Culture(){}

#endif //CULTURE_CPP
