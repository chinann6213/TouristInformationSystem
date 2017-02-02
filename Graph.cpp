/*************************************
Program: Graph.cpp
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "LinkedStack.cpp"
#include "LinkedList.cpp"
#include "Graph.h"

#include <fstream>
#include <cassert>

Graph::Graph(){}

Graph::Graph(const int size, int **tempMatrix):size(size) // overloaded constructor to copy 2D array
{
    matrix = new int* [size];

    for (int i = 0; i < size; i++)
    {
        matrix[i] = new int [size];
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = tempMatrix[i][j];
        }
    }
}

bool Graph::isConnected(int x, int y)
{
    assert(x > 0 && x <= size);
    assert(y > 0 && y <= size);
    return matrix[x - 1][y - 1] == 1; // return true(1) when two cities is connected
}

void Graph::addEdge(int x, int y)
{
    assert(x > 0 && x <= size);
    assert(y > 0 && y <= size);
    matrix[x - 1][y - 1] = 1; // set the connection of 2 cities into the 2D matrix
}

void Graph::GoBack(int x, int y)
{
    assert(x > 0 && x <= size);
    assert(y > 0 && y <= size);
    matrix[y - 1][x - 1] = 1; // set the connection of 2 cities from b to a if a to b is set
}

void Graph::removeEdge(int x, int y)
{
    assert(x > 0 && x <= size);
    assert(y > 0 && y <= size);
    matrix[x - 1][y - 1] = 0; // remove the connection of 2 cities in the 2D matrix
}

int Graph::DFS(const int start, const int toFind)
{
    LinkedStack<int> connection; // create an empty stack
    bool *visited = new bool[size + 1]; // create a dynamic array
    for (int i = 0; i <= size; i++) // mark the array to become zero(unvisited)
    {
        visited[i] = false;
    }
    connection.push(start); // push the departure city onto the array
    visited[start] = true; // mark the departure city as visited
    if (start == toFind) return -1;

    LinkedList<int> found; // Linked list to store the connection of departure city to another cities
    int count = 0;
    while(!connection.isEmpty())
    {
        int wanted = connection.peek(); // peek the top value of the stack
        connection.pop();
        found.insert(count, wanted); // insert the value after peeked
        if (wanted == toFind) break;
        for (int i = size; i > 0; i--)
        {
            if (isConnected(wanted, i) && !visited[i])
            {
                connection.push(i); // push the cities which are connected to the departure city
                visited[i] = true; // mark those cities as visited
            }
        }
        count ++;
    }
    delete [] visited;

    if (!isConnected(start, toFind) && !visited[toFind]) return 0; // return 0 if the departure city is not connected with any other cities
    else if (!isConnected(start, toFind)) return -2; // return -2 if connection is indirect
    else return found.getEntry(count); // return the destination city if the connection is direct
}

int Graph::getSize() const
{
    return size;
}

int Graph::printGraph(int x, int y) const
{
    assert(x >= 0 && x < size);
    assert(y >= 0 && y < size);
    return matrix[x][y];
}

Graph::~Graph()
{
    for (int i = 0; i < size; ++i)
    {
        delete [] matrix[i];
    }
    delete[] matrix;
}

#endif // GRAPH_CPP
