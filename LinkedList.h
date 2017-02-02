/*************************************
Program: LinkedList.h
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef LINKEDLIST_H
#define LINKEDLISH_H

#include "Node.cpp"
#include "ListInterface.h"

#include <cassert>

template <class Itemtype>
class LinkedList: public ListInterface <Itemtype>
{
    private:

        Node <Itemtype>* headPtr; // the starting point of the list
        int itemCount; // variable to store the size of the list
        Node <Itemtype>* getNodeAt(int position) const; // function to get node

    public:

        LinkedList();
        LinkedList(const LinkedList <Itemtype>& aList);
        virtual ~LinkedList();

        bool isEmpty() const;
        int getLength() const;
        bool insert(int newPosition, const Itemtype& newEntry);
        bool remove(int position);
        void clear();
        void setEntry(int position, const Itemtype& newEntry);
        Itemtype getEntry(int position) const;
        void sort(); // sorting function using bubble sort
};

#endif // LINKEDLIST_H
