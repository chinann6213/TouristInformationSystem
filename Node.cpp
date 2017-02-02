/*************************************
Program: Node.cpp
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

#include <cstddef>

using namespace std;


template <class Itemtype>
Node <Itemtype>::Node():next(NULL) {}

template <class Itemtype>
Node <Itemtype>::Node(const Itemtype& anItem):item(anItem), next(NULL) {}

template <class Itemtype>
Node <Itemtype>::Node(const Itemtype& anItem, Node <Itemtype>* nextNodePtr):
                      item(anItem), next(nextNodePtr) {}

template <class Itemtype>
void Node <Itemtype>::setItem(const Itemtype& anItem)
{
    item = anItem;
}

template <class Itemtype>
void Node <Itemtype>::setNext(Node <Itemtype>* nextNodePtr)
{
    next = nextNodePtr;
}

template <class Itemtype>
Itemtype Node <Itemtype>::getItem() const
{
    return item;
}

template <class Itemtype>
Node <Itemtype>* Node <Itemtype>::getNext() const
{
    return next;
}

#endif // NODE_CPP
