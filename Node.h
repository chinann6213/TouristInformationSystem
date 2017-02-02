/*************************************
Program: Node.h
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef NODE_H
#define NODE_H

template <class Itemtype>
class Node
{
    private:

        Itemtype item;
        Node <Itemtype>* next;

    public:

        Node();
        Node(const Itemtype& anItem);
        Node(const Itemtype& anItem, Node <Itemtype>* nextNodePtr);
        void setItem(const Itemtype& anItem);
        void setNext(Node <Itemtype> * nextNodePtr);
        Itemtype getItem() const;
        Node <Itemtype>* getNext() const;
};

#endif // NODE_H
