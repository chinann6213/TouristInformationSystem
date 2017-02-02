/*************************************
Program: City.h
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef CITY_H
#define CITY_H

#include "Attraction.h"
#include "Sport.h"
#include "Culture.h"
#include "Restaurant.h"
#include "Graph.h"
#include "LinkedList.cpp"

#include <iostream>
#include <string>
#include <iomanip> //to set precision
#include <sstream> //to use istringstream
#include <cstdlib> //to use clear screen and do cstring conversion
#include <fstream> //to save file

using namespace std;

class City
{
    private:
        string name; // name of cities
        int id; // every cities have their own ids represented the location in adj matrix for city connection
        Graph *connect; // pointer point to a 2D matrix
        LinkedList<City*> cityName; //vector to push back city name
        LinkedList<Attraction*> attractions; //vector to push back the name and information of attractions

    public:
        City();
        City(string name, int id); //id will continue increases by 1 when new city is added
        City(ifstream& info); // function helps to pass the variable into operator overloading function
        ~City(); //destructor to delete the elements in the attractions vector

        void setAttraction(int position, Attraction* attraction); //function to push back the attraction type object
        Attraction* getAttraction(int ind); //function to get objects in vector attractions
        int getAttractionSize(); // function to get attraction size
        void setName(string name); // function to set city name
        string getName(); //function to get city name
        int errorHandling(int temp); //function to handle exception
        int integerHandling();
        double doubleHandling();
        //--------------------------Admin function--------------------------------------
        void runAdmin(); //function for Admin
        void runAddCity(); // function to add new city
        void runAddAttraction(); // function to add new attraction
        void runRemoveCity(); // function to remove an existed city
        void runRemoveAttraction(); // function to remove an existed attraction
        void runEditCity(); // function to edit an existed city
        void runEditAttraction(); // function to edit an existed attraction
        void runEditConnection(); // function to edit the connection between 2 cities
        //--------------------------User function---------------------------------------
        void runCity(); //function to run the main screen
        void runAttraction(int id); //function to run attraction types' and also city connection screen
        void runLocation(int id, int getAtt); //function to run the attractions screen
        void runCityConnection(int id); // function to run the connection between two cities
        void runDisplay(int id, int getAtt, int getLocation); //function to display the information of selected attractions

        void MainMenu(); //main menu function of the system
        void execute(); //main function to run the system
        void saveAttraction(); // function to save the city's name and its attraction and also city connection
        void loadAttraction(); // function to load the city's name and its attraction and also city connection

        ostream& output(ostream& out); // function helps to save the information of cites
        istream& input(istream& in); // function helps to load the information of cities
};
#endif // CITY_H
