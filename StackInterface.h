/*************************************
Program: StackInterface.h
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

template<class ItemType>
class StackInterface
{
    public:

        virtual bool isEmpty() const = 0;
        virtual bool push(const ItemType& newEntry) = 0;
        virtual bool pop() = 0;
        virtual ItemType peek() const = 0;

};
#endif // end StackInterface
