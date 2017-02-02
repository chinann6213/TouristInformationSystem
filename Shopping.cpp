/*************************************
Program: Shopping.cpp
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef SHOPPING_CPP
#define SHOPPING_CPP

#include "Attraction.h"
#include "Shopping.h"
#include "LinkedList.cpp"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib> //to convert cstring

using namespace std;

//implementation of function in class shopping(functions is explained in header file).
Shopping::Shopping(){}

Shopping::Shopping(int typeID, string name, string openHrs, string openDay, string address, string contact, double tax, int discount, LinkedList <string> mall)
: Attraction(typeID, name, openHrs, openDay, address, contact), tax(tax), discount(discount), mall(mall){}

istream& operator >> (istream &in, Shopping &info) //overloaded operator >> to load data
{
    return info.input(in);
}

Shopping::Shopping(ifstream& info)
{
    info >> *this; //load data into the variables
}

void Shopping::setTax(double tax)
{
    this -> tax = tax;
}

void Shopping::setDiscount(int discount)
{
    this -> discount = discount;
}

void Shopping::setMall(int position, string editMall)
{
    mall.setEntry(position, editMall);
}

string Shopping::getMall(int position)
{
    return mall.getEntry(position);
}

int Shopping::getMallLength()
{
    return mall.getLength();
}

void Shopping::display() //display the information of the attractions
{
    cout << "Shopping malls located in " <<getName()  << endl
         << "_________________________________________________________" << endl;

    int mallSize = mall.getLength();
    for (int i = 0; i < mallSize; i ++)
    {
        cout << i + 1 <<". " << mall.getEntry(i) << endl;
    }

    cout << "_________________________________________________________" << endl
         << "Opening hour  : " << getOpenHrs() << endl
         << "Opening days  : " << getDay() << endl
         << "Address       : " << getAddress() << endl
         << "Contact number: " << getContact() << endl
         << "Taxation      : " << fixed << setprecision(2) << tax << "% GST." <<endl
         << "Discount      : up to " << discount << "%" << endl << endl;

}

void Shopping::clearMall()
{
    mall.clear();
}

ostream& Shopping::output (ostream& out)
{
    Attraction::output(out); //common attribute from super class
    out << tax << "\n" << discount << "\n" << mall.getLength() << "\n";
    int mallSize = mall.getLength();
    for (int i = 0; i < mallSize; i++)
    {
        out << mall.getEntry(i) << "\n";
    }

    return out;
}

istream& Shopping::input(istream& in)
{
    string info;
    int mallsize;

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
    tax = atof(info.c_str()); //convert string into double

    getline(in, info);
    discount = atoi(info.c_str()); //convert string into integer

    clearMall();
    getline(in, info);
    mallsize = atoi(info.c_str()); //convert string into integer

    for(int i = 0; i < mallsize; i++)
    {
        string mallname;
        getline(in, mallname);
        mall.insert(i, mallname);
    }

    return in;
}

Shopping::~Shopping(){}
#endif // SHOPPING_CPP
