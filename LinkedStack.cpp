/*************************************
Program: LinkedStack.cpp
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef LINKED_STACK_CPP
#define LINKED_STACK_CPP

#include <cassert>        // For assert

#include "LinkedStack.h"  // Header file
#include "Node.cpp"

template<class ItemType>
LinkedStack<ItemType>::LinkedStack() : topPtr(nullptr)
{
}

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{
    Node<ItemType>* origChainPtr = aStack.topPtr;

    if (origChainPtr == nullptr)
    {
        topPtr = nullptr;
    }
    else
    {
        topPtr = new Node<ItemType>();
        topPtr->setItem(origChainPtr->getItem());
        Node<ItemType>* newChainPtr = topPtr;
        origChainPtr = origChainPtr->getNext();

        while (origChainPtr != nullptr)
        {
            ItemType nextItem = origChainPtr->getItem();
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
    }
}

template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
    while (!isEmpty())
	{
	    pop();
	}
}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
	return topPtr == nullptr;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);
	topPtr = newNodePtr;
    newNodePtr = nullptr;

	return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop()
{
	bool result = false;
	if (!isEmpty())
	{
		Node<ItemType>* nodeToDeletePtr = topPtr;
		topPtr = topPtr->getNext();
        nodeToDeletePtr->setNext(nullptr);
		delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        result = true;
	}
	return result;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const
{
    assert(!isEmpty());
    {
        return topPtr->getItem();
    }
}

#endif // LINKED_STACK_CPP
