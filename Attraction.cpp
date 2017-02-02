/*************************************
Program: Attraction.cpp
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef ATTRACTION_CPP
#define ATTRACTION_CPP

#include "Attraction.h"
#include "Sport.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//implementation of function in attraction class.
Attraction::Attraction(){}

Attraction::Attraction(int typeID, string name, string openHrs, string openDay, string address, string contact)
: typeID(typeID), name(name), openHrs(openHrs), openDay(openDay), address(address), contact(contact){}

int Attraction::gettypeID()
{
    return typeID;
}

void Attraction::settypeID(int typeID)
{
    this -> typeID = typeID;
}

void Attraction::setName(string name)
{
    this -> name = name;
}

void Attraction::setHrs(string openHrs)
{
    this -> openHrs = openHrs;
}

void Attraction::setDay(string openDay)
{
    this -> openDay = openDay;
}

void Attraction::setAddress(string address)
{
    this -> address = address;
}

void Attraction::setContact(string contact)
{
    this -> contact = contact;
}

string Attraction::getName()
{
    return name;
}

string Attraction::getOpenHrs()
{
    return openHrs;
}
string Attraction::getDay()
{
    return openDay;
}

string Attraction::getAddress()
{
    return address;
}

string Attraction::getContact()
{
    return contact;
}

ostream& Attraction::output(ostream& out)
{
    out << typeID << "\n"  << name << "\n" << openHrs << "\n" << openDay << "\n" << address << "\n" << contact << "\n";
    return out;
};

Attraction::~Attraction(){}

#endif // ATTRACTION_CPP
