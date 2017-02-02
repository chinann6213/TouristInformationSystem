/*************************************
Program: LinkedStack.h
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "StackInterface.h"
#include "Node.cpp"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
    private:

        Node<ItemType>* topPtr;

    public:

        LinkedStack();
        LinkedStack(const LinkedStack<ItemType>& aStack);
        virtual ~LinkedStack();

        bool isEmpty() const;
        bool push(const ItemType& newItem);
        bool pop();
        ItemType peek() const;
};

#endif  // end LinkedStack
