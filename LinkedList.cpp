/*************************************
Program: LinkedList.cpp
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "Node.cpp"
#include "LinkedList.h"

#include <iostream>
#include <cstddef>
#include <cassert>

template <class Itemtype>
LinkedList <Itemtype>::LinkedList(): headPtr(NULL), itemCount(0) {}

template <class Itemtype>
LinkedList <Itemtype>::LinkedList(const LinkedList <Itemtype>& aList)
{
    itemCount = aList.itemCount;
    Node<Itemtype> * tracePtr = aList.headPtr;

    if (tracePtr == NULL)
	{
	    headPtr = NULL;
	}
	else
    {
        headPtr = new Node <Itemtype>();
        headPtr -> setItem(tracePtr -> getItem());

        Node <Itemtype>* newChainPtr = headPtr;
        tracePtr = tracePtr -> getNext();
        while(tracePtr != NULL)
        {
            //Copy values
            Itemtype nextItem = tracePtr -> getItem();

            Node <Itemtype>* newNodePtr = new Node <Itemtype> (nextItem);

            newChainPtr -> setNext(newNodePtr);

            newChainPtr = newChainPtr -> getNext();

            tracePtr = tracePtr -> getNext();
        }
        newChainPtr -> setNext(NULL);
	}
}

template <class Itemtype>
Node <Itemtype>* LinkedList <Itemtype>::getNodeAt(int position) const
{
    assert((position >= 0) && (position < itemCount));

    Node <Itemtype>* curPtr = headPtr;
    for (int i = 0; i < position; i ++)
    {
        curPtr = curPtr -> getNext();
    }
    return curPtr;
}

template <class Itemtype>
bool LinkedList <Itemtype>::isEmpty() const
{
    return itemCount == 0;
}

template <class Itemtype>
int LinkedList <Itemtype>::getLength() const
{
    return itemCount;
}

template <class Itemtype>
bool LinkedList <Itemtype>::insert(int newPosition, const Itemtype& newEntry) //insert city/ attractions
{
    bool ableToInsert = (newPosition >= 0) && (newPosition <= itemCount); // +1 to enable adding to end

    if(ableToInsert)
    {
        Node <Itemtype>* newNodePtr = new Node <Itemtype> (newEntry);

        if (newPosition == 0)
        {
            newNodePtr -> setNext(headPtr);
            headPtr = newNodePtr;
        }
        else
        {
            Node <Itemtype>* prevPtr = getNodeAt(newPosition - 1);
            newNodePtr -> setNext(prevPtr -> getNext());
            prevPtr -> setNext(newNodePtr);
        }
        itemCount ++;
    }
    return ableToInsert;
}

template <class Itemtype>
bool LinkedList <Itemtype>::remove(int position)
{
    bool ableToRemove = (position >= 0) && (position < itemCount);

    if(ableToRemove)
    {
        Node <Itemtype>* curPtr = NULL;
        if (position == 0)
        {
            curPtr = headPtr;
            headPtr = headPtr -> getNext();
        }
        else
        {
            Node <Itemtype>* prevPtr = getNodeAt(position - 1);
            curPtr = prevPtr -> getNext();
            prevPtr -> setNext(curPtr -> getNext());
        }
        curPtr -> setNext(NULL);
        delete curPtr;
        curPtr = NULL;

        itemCount --;
    }
    return ableToRemove;
}

template <class Itemtype>
void LinkedList <Itemtype>::clear()
{
    while (!isEmpty())
    {
        remove(0);
    }
}

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)
{
    Node<ItemType>* nodePtr = getNodeAt(position);
    nodePtr->setItem(newEntry);
}

template <class Itemtype>
Itemtype LinkedList <Itemtype>::getEntry(int position) const
{
    assert((position >= 0) && (position < itemCount));

    Node <Itemtype>* nodePtr = getNodeAt(position);
    return nodePtr -> getItem();
}

template <class Itemtype>
void LinkedList<Itemtype>::sort() // sorting function using bubble sort
{
    Node<Itemtype> *current = headPtr; // pointer point to the head pointer of a linked list
    int count = 0;
    while(current != NULL)
    {
        count++; // calculate the total items in a linked list
        current = current -> getNext();
    }
    for(int i = count ; i > 1 ; i-- )
    {
        Node<Itemtype> *temp;
        Node<Itemtype> *swap1;
        swap1 = headPtr;
        for(int j = 0 ; j < count - 1 ; j++ )
        {
            if(*swap1 -> getItem() > *swap1 -> getNext() -> getItem()) // swap 2 items if first items is bigger than second item
            {
                Node<Itemtype> *swap2 = swap1 -> getNext();
                swap1 -> setNext(swap2 -> getNext());
                swap2 -> setNext(swap1);
                if(swap1 == headPtr)
                {
                    headPtr = swap2;
                    swap1 = swap2;
                }
                else
                {
                    swap1 = swap2;
                    temp -> setNext(swap2);
                }
            }
            temp = swap1;
            swap1 = swap1 -> getNext();
        }
    }
}

template <class Itemtype>
LinkedList <Itemtype>::~LinkedList()
{
    clear();
}

#endif // LINKEDLIST_CPP
