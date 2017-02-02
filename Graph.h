/*************************************
Program: Graph.h
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedStack.cpp"

#include <iostream>
#include <fstream>

class Graph
{
    private:

        int size; // size of 2D matrix
        int **matrix; // declaration of 2D matrix to store flight connection

    public:

        Graph();
        Graph(const int size, int **tempMatrix);
        ~Graph();

        bool isConnected(int x, int required); // check the connection between 2 cities
        void addEdge(int x, int y); // add connection between two cities
        void removeEdge(int x, int y); // remove connection between two cities
        void GoBack(int x, int y); // flight to destination and flight back
        int DFS(const int , const int); // function to search the flight from departure city to destination
        int getSize() const; // get size of 2D matrix
        int printGraph(int x, int y) const; // function helps to save the 2D matrix
};

#endif // GRAPH_H
