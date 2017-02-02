/*************************************
Program: ListInterface.h
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef LISTINTERFACE_H
#define LISTINTERFACE_H

using namespace std;

template <class Itemtype>
class ListInterface
{
    public:

        virtual bool isEmpty() const = 0; // function to check whether the list is empty
        virtual int getLength() const = 0; // function to get the size of the list
        virtual bool insert(int newPosition, const Itemtype& newEntry) = 0; // function to insert data to the list
        virtual bool remove(int position) = 0; // function to remove data in specified location
        virtual void clear() = 0; // function to clear all the data of list
        virtual void setEntry(int position, const Itemtype& newEntry) = 0; // function to input info
        virtual Itemtype getEntry(int position) const = 0; // function to get info
};

#endif // LISTINTERFACE_H
