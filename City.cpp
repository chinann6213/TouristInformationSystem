/*************************************
Program: City.cpp
Course:  OOPDS
Year:    2015/16 Trimester 2
Name:    NG CHIN ANN
ID:      1142701684
Lecture: TC01
Lab:     TT03
Email:   chinann6213@gmail.com
Phone:   011 - 1076 6957
*************************************/
#ifndef CITY_CPP
#define CITY_CPP

#include "City.h"
#include "Attraction.h"
#include "Sport.h"
#include "Shopping.h"
#include "Culture.h"
#include "Restaurant.h"
#include "Graph.h"
#include "LinkedList.cpp"

#include <iostream>
#include <string>
#include <iomanip> //to set precision
#include <sstream> //to use istringstream
#include <cstdlib> //to use clear screen and do cstring conversion
#include <fstream> //to save and load file

//implementation of function in class City(functions are explained in header file)
City::City(){}

City::City(string name, int id): name(name), id(id){}

int City::getAttractionSize(){
    return attractions.getLength();
}

void City::setName(string name){
    this -> name = name;
}

string City::getName(){
    return name;
}

void City::setAttraction(int position, Attraction* attraction){
    attractions.insert(position, attraction); // insert a new attraction into linkedlist
}

Attraction* City::getAttraction(int ind){
    return attractions.getEntry(ind); // return the attraction selected by user
}

int City::errorHandling(int temp){
    int n;
    string select;
    bool error = false;
    do{
        try{
            cout << "==> ";
            cin >> select;
            if (!(istringstream (select) >> n))
                throw select;
            else if (!(n >0 && n <= temp))
                throw n;
            error = true;
        }
        catch (string select){
            cout << "Error: You input string \"" << select << "\".\n"
                 << "Input must be positive integer between the given range only.\n";
        }
        catch (int m){
            cout << "Error: You input invalid number " << m << ".\n"
                 << "Input must be positive integer between the given range only.\n";
        }
    }while(!error);
    return n;
}

int City::integerHandling(){
    int n;
    string select;
    bool error = false;
    do{
        try{
            cout << "==> ";
            cin >> select;
            if (!(istringstream (select) >> n))
                throw select;
            error = true;
        }
        catch (string Stringselect){
            cout << "Error: You input string \"" << Stringselect << "\".\n"
                 << "Input must be positive digits only.\n";
        }
    }while(!error);
    return n;
}

double City::doubleHandling(){
    double n;
    string select;
    bool error = false;
    do{
        try{
            cout << "==> ";
            cin >> select;
            if (!(istringstream (select) >> n))
                throw select;
            error = true;
        }
        catch (string Stringselect){
            cout << "Error: You input string \"" << Stringselect << "\".\n"
                 << "Input must be positive digits only.\n";
        }
    }while(!error);
    return n;
}

void City::runAdmin(){
    bool returns = false;
    do{
        cout << "!=========================================!" << endl
             << "!                                         !" << endl
             << "!     Administrator Navigation Panel      !" << endl
             << "!                                         !" << endl
             << "!=========================================!" << endl
             << "\nPlease select one of the option below to proceed.\n"
             << "[1] Add new city\n"
             << "[2] Remove an existed city\n"
             << "[3] Edit an existed city\n"
             << "[4] Add new attraction of an existed city\n"
             << "[5] Remove an existed attraction\n"
             << "[6] Edit information of an existed attraction\n"
             << "[7] Add/ Remove city connection\n"
             << "[8] Return to main menu\n";

        int choice = errorHandling(8); system("CLS");

        if (choice == 1) runAddCity();
        else if (choice == 2) runRemoveCity();
        else if (choice == 3) runEditCity();
        else if (choice == 4) runAddAttraction();
        else if (choice == 5) runRemoveAttraction();
        else if (choice == 6) runEditAttraction();
        else if (choice == 7) runEditConnection();
        else if (choice == 8) returns = true;

    }while (!returns);
}

void City::runAddCity(){
    cout << "Please select an option.\n"
         << "[1] Add a new city\n"
         << "[2] Return to Admin panel\n";

    int select = errorHandling(2); system("CLS");

    if (select == 1) {
        cout << "|::::::::::Add New City::::::::::|\nPlease enter a city name that you wish to add.\n==> ";

        string newCity;
        cin.ignore(1000, '\n');
        getline(cin, newCity);

        int cityLength = newCity.size();

        string upCity;
        for (int up = 0; up < cityLength; up++){ // convert the first letter of newly entered city name into capital letter
            if (up == 0)
                upCity = toupper(newCity[0]); // convert the first alphabet into capital letter
            else
                upCity = upCity + newCity[up]; // concatenate the remaining character with first character
        }

        cityName.insert(cityName.getLength(), new City(upCity, cityName.getLength() + 1)); // insert the new city into linked list

        cout << "Add success!\n";

        cityName.sort(); // sort the linked list after a new city is added every time

        int **tempMatrix; // temporary 2D matrix to store the existed city connection
        tempMatrix = new int* [cityName.getLength()];
        for (int z = 0; z  < cityName.getLength(); z++){
            tempMatrix[z] = new int [cityName.getLength()];
            for(int w = 0; w < cityName.getLength(); w++){
                if (z == cityName.getLength() - 1) tempMatrix[z][w] = 0; // initialize the newly added row into zero
                else if (w == cityName.getLength() - 1) tempMatrix[z][w] = 0; // initialize the newly added column into zero
                else tempMatrix[z][w] = connect -> printGraph(z, w); // copy the existed connection
            }
        }
        delete connect;
        connect = new Graph(cityName.getLength(), tempMatrix); // pass the temporary matrix to the original matrix

        // delete temporary variable after using
        for (int i = 0; i < cityName.getLength(); ++i)
            delete [] tempMatrix[i];
        delete [] tempMatrix;

        saveAttraction();

        cout << "Please select an option to proceed.\n"
             << "[1] Continue to add attraction\n"
             << "[2] Return to Admin panel\n";

        int choice = errorHandling(2); system("CLS");

        if (choice == 1) runAddAttraction();
        else if (choice == 2) return;
    }
    else if (select == 2) return;
}

void City::runAddAttraction(){
    cout << "|::::::::::Add New Attraction::::::::::|\n";

    int temp = 0; int citySize = cityName.getLength();

    for (int i = 0; i < citySize; i++){
        cout << "[" << i + 1 << "] " << cityName.getEntry(i) -> name << endl;
        temp = i; //variable to store the size of cityName
    }

    cout << "Please select one of the city to add its attraction.\nEnter [" << temp + 2 << "] back to Admin Panel\n";

    int selection = temp + 2;
    int choice = errorHandling(selection); system("CLS");

    if(choice == selection) return;
    else{
        system("CLS");
        cout << "You have chosen " << cityName.getEntry(choice - 1) -> name << ".\n\n"
             << "[1] Sport\n"
             << "[2] Culture\n"
             << "[3] Shopping\n"
             << "[4] Restaurant\n\n"
             << "\nPlease choose one of the attraction type that you wish to add.\n\n"
             << "[5] Return to Admin panel\n";

        int typeChoice = errorHandling(5); system("CLS");
        cin.ignore(1000, '\n');

        if(typeChoice == 5) return;

        cout << "You have chosen attraction type: ";
        if (typeChoice == 1) cout << "Sport.\n";
        else if (typeChoice == 2) cout << "Culture.\n";
        else if (typeChoice == 3) cout << "Shopping.\n";
        else if (typeChoice == 4) cout << "Restaurant.\n";

        int newSize = cityName.getEntry(choice - 1) -> getAttractionSize();
        string Attname, openHrs, openDay, address, contact;

        cout << "Enter attraction name ==> "; getline(cin, Attname);
        cout << "Enter open hours(9.00am to 10.00pm) ==> "; getline(cin, openHrs);
        cout << "Enter open day(e.g Monday to Friday) ==> "; getline(cin, openDay);
        cout << "Enter address(N/A for null value) ==> "; getline(cin, address);
        cout << "Enter contact number(N/A for null value) ==> "; getline(cin, contact);

        if(typeChoice == 1){
            int ageLim; double entrance; string type, sportName;
            cout << "Enter age limit of the sport "; ageLim = integerHandling();
            cout << "Enter entrance fee in RM(e.g 3.00) "; entrance = doubleHandling(); cin.ignore(1000, '\n');
            cout << "Enter sport type(group/individual) ==> "; getline(cin, type);
            cout << "Enter name of sport can do ==> "; getline(cin, sportName);
            cityName.getEntry(choice - 1) -> setAttraction(newSize, new Sport(typeChoice, Attname, openHrs, openDay, address,
                                                                              contact, ageLim, entrance, type, sportName));
        }
        else if(typeChoice == 2){
            double entranceFee; string type, information, facility;
            cout << "Enter entrance fee in RM(e.g 3.00) "; entranceFee = doubleHandling(); cin.ignore(1000, '\n');
            cout << "Enter type of culture(Historical/Religious) ==> "; getline(cin, type);
            cout << "Enter brief info of the cultural attraction ==> "; getline(cin, information);
            cout << "Enter facility of the cultural attraction ==> "; getline(cin, facility);
            cityName.getEntry(choice - 1) -> setAttraction(newSize, new Culture(typeChoice, Attname, openHrs, openDay, address,
                                                                                contact, entranceFee, type, information, facility));
        }
        else if(typeChoice == 3){
            double tax; int discount, mallNum;
            cout << "Enter tax charged in %(exclude '%') "; tax = doubleHandling();
            cout << "Enter the maximum discount given by the shopping mall "; discount = integerHandling();
            cout << "Enter the number of mall in the area "; mallNum  = integerHandling(); cin.ignore(1000, '\n');
            cout << "Enter the name of the malls\n";
            LinkedList<string> newMallName;
            for(int j = 0; j < mallNum; j++){
                string newMall;
                cout << "==> "; getline(cin, newMall);
                newMallName.insert(j, newMall);
            }
            cityName.getEntry(choice - 1) -> setAttraction(newSize, new Shopping(typeChoice, Attname, openHrs, openDay, address,
                                                                                contact, tax, discount, newMallName));
        }
        else if(typeChoice == 4){
            string highlight, food, price;
            cout << "Enter highlight of the restaurant ==> "; getline(cin, highlight);
            cout << "Enter food served ==> "; getline(cin, food);
            cout << "Enter price range of the food in RM(e.g 20.00 - 50.00) ==> "; getline(cin, price);
            cityName.getEntry(choice - 1) -> setAttraction(newSize, new Restaurant(typeChoice, Attname, openHrs, openDay, address,
                                                                                contact, highlight, food, price));
        }
    }
    saveAttraction();
    cout << "Update completed.\nTo return to ADMIN PANEL: "; system("Pause"); system("CLS");
    return;
}

void City::runEditCity(){
    cout << "|:::::::::::Edit Existed City::::::::::|\n";

    int temp = 0; int citySize = cityName.getLength();

    for (int i = 0; i < citySize; i++){
        cout << "[" << i + 1 << "] " << cityName.getEntry(i) -> name << endl;
        temp = i; //variable to store the size of vector cityName
    }

    cout << "Please select one of the city to edit.\nEnter [" << temp + 2 << "] back to Admin panel\n";

    int selection = temp + 2;
    int choice = errorHandling(selection); system("CLS");
    if (choice == temp + 2) return;
    else{
        cout << "Please enter a new name for the chosen city(" << cityName.getEntry(choice - 1) -> name << ").\n==> ";
        string editName;
        cin.ignore(1000, '\n'); getline(cin, editName);
        cityName.getEntry(choice - 1) -> setName(editName);
    }
    cityName.sort(); // Sort the city when the name is edited
    saveAttraction();
    cout << "Update completed.\nTo return to ADMIN PANEL: "; system("Pause"); system("CLS");
    return;
}

void City::runEditAttraction(){
    cout << "|:::::::Edit Existed Attractions:::::::|\n";

    int temp = 0; int citySize = cityName.getLength();

    for (int i = 0; i < citySize; i++){
        cout << "[" << i + 1 << "] " << cityName.getEntry(i) -> name << endl;
        temp = i; //variable to store the size of vector cityName
    }

    cout << "Please select one of the city to edit.\nEnter [" << temp + 2 << "] back to Admin panel\n";
    int selection = temp + 2;
    int choice = errorHandling(selection); system("CLS");

    if (choice == temp + 2) return;
    else{
        cout << "You have chosen " << cityName.getEntry(choice - 1) -> name << ".\n\n"
             << "[1] Sport\n"
             << "[2] Culture\n"
             << "[3] Shopping\n"
             << "[4] Restaurant\n\n"
             << "\nPlease choose one of the attraction type that you wish to edit.\n"
             << "[5] Return to Admin panel\n";
        int typeChoice = errorHandling(5); system("CLS");
        if (typeChoice == 5) return;
        else{
            cout << "You have chosen " << cityName.getEntry(choice - 1) -> name << ".\n";
            int attractionSize = cityName.getEntry(choice - 1) -> getAttractionSize();
            int counts = 1; int index = 0; LinkedList<int> position;
            for(int x = 0; x < attractionSize; x ++){
                if (cityName.getEntry(choice - 1) -> getAttraction(x) -> gettypeID() == typeChoice){
                    position.insert(index, x); // store the position of the attractions in the linked list
                    cout << "[" << counts <<"] " << cityName.getEntry(choice - 1) -> getAttraction(x) -> getName() << endl;
                    counts ++; index ++;
                }
            }
            cout << "Please select one of the attractions to edit.\nEnter [" << counts << "] back to Admin panel\n";
            int selectEdit = errorHandling(counts); system("CLS");
            cin.ignore(1000, '\n');
            //------------------------------------------attraction name chosen--------------------------------------------
            if (selectEdit == counts) return;
            else{
                char answer;
                do{
                    int toEdit = position.getEntry(selectEdit - 1);
                    string Attname, openHrs, openDay, address, contact, information, facility, type, sportName;
                    string highlight, food, price;
                    int ageLim, discount; double entrance, tax;

                    int editChoice;
                    cout << "You have chosen " << cityName.getEntry(choice - 1) -> getAttraction(toEdit) -> getName() << "\n"
                         << "Please choose one of the attribute to start edit.\n"
                         << "[1] Attraction name\n"
                         << "[2] Open hours\n"
                         << "[3] Open day\n"
                         << "[4] Address\n"
                         << "[5] Contact number(N/A for null value)\n";
                    if(typeChoice == 1){
                        cout << "[6] Age limit of the sport\n"
                             << "[7] Entrance fee\n"
                             << "[8] Sport type\n"
                             << "[9] Name of sport can do\n"
                             << "[10] Return to Admin panel.\n";
                        editChoice = errorHandling(10);
                    }
                    else if(typeChoice == 2){
                        cout << "[6] Entrance fee\n"
                             << "[7] Type of culture\n"
                             << "[8] Brief info of the cultural attraction\n"
                             << "[9] Facility of the cultural attraction\n"
                             << "[10] Return to Admin panel.\n";
                        editChoice = errorHandling(10);
                    }
                    else if(typeChoice == 3){
                        cout << "[6] Tax charged\n"
                             << "[7] Maximum discount given by the shopping mall\n"
                             << "[8] Name of the malls\n"
                             << "[9] Return to Admin panel.\n";
                        editChoice = errorHandling(9);
                    }
                    else if(typeChoice == 4){
                        cout << "[6] Highlight of the restaurant\n"
                             << "[7] Food served\n"
                             << "[8] Price range of the food\n"
                             << "[9] Return to Admin panel.\n";
                        editChoice = errorHandling(9);
                    }
                    cin.ignore(1000, '\n'); system("CLS");
                    //-------------------------Attribute to be edited chosen----------------------------
                    if (editChoice == 1){
                        cout << "Enter a new name: "; getline(cin, Attname);
                        cityName.getEntry(choice - 1) -> getAttraction(toEdit) -> setName(Attname);
                    }
                    else if (editChoice == 2){
                        cout << "Enter a new open hours(e.g 9.00am to 10.00pm): "; getline(cin, openHrs);
                        cityName.getEntry(choice - 1) -> getAttraction(toEdit) -> setHrs(openHrs);
                    }
                    else if (editChoice == 3){
                        cout << "Enter a new open day(e.g Monday to Friday): "; getline(cin, openDay);
                        cityName.getEntry(choice - 1) -> getAttraction(toEdit) -> setDay(openDay);
                    }
                    else if (editChoice == 4){
                        cout << "Enter a new address(N/A for null value): "; getline(cin, address);
                        cityName.getEntry(choice - 1) -> getAttraction(toEdit) -> setAddress(address);
                    }
                    else if (editChoice == 5){
                        cout << "Enter a new contact number(N/A for null value): "; getline(cin, contact);
                        cityName.getEntry(choice - 1) -> getAttraction(toEdit) -> setContact(contact);
                    }
                    // downcast to access the function in derived class
                    Sport* sport = dynamic_cast<Sport*> (cityName.getEntry(choice - 1) -> getAttraction(toEdit));
                    Culture* culture = dynamic_cast<Culture*> (cityName.getEntry(choice - 1) -> getAttraction(toEdit));
                    Shopping* shopping = dynamic_cast<Shopping*> (cityName.getEntry(choice - 1) -> getAttraction(toEdit));
                    Restaurant* restaurant = dynamic_cast<Restaurant*> (cityName.getEntry(choice - 1) -> getAttraction(toEdit));
                    if (editChoice == 6){
                        if (typeChoice == 1){
                            cout << "Enter a new age limit"; ageLim = integerHandling();
                            sport -> setAgeLimit(ageLim);
                        }
                        else if (typeChoice == 2){
                            cout << "Enter a new entrance fee in RM(e.g 3.00)"; entrance = doubleHandling(); cin.ignore(1000, '\n');
                            culture -> setEntranceFee(entrance);
                        }
                        else if (typeChoice == 3){
                            cout << "Enter a new tax in % (exclude '%')"; tax = doubleHandling();
                            shopping -> setTax(tax);
                        }
                        else if (typeChoice == 4){
                            cout << "Enter new highlight of the restaurant: "; getline(cin, highlight);
                            restaurant -> setHighlight(highlight);
                        }
                    }
                    else if (editChoice == 7){
                        if (typeChoice == 1){
                            cout << "Enter a new entrance fee in RM(e.g 3.00)"; entrance = doubleHandling(); cin.ignore(1000, '\n');
                            sport -> setEntranceFee(entrance);
                        }
                        else if (typeChoice == 2){
                            cout << "Enter a new type of culture(Historical/Religious: "; getline(cin, type);
                            culture -> setCultureType(type);
                        }
                        else if (typeChoice == 3){
                            cout << "Enter a new maximum discount";  discount = integerHandling();
                            shopping -> setDiscount(discount);
                        }
                        else if (typeChoice == 4){
                            cout << "Enter new food served in the restaurant: "; getline(cin, food);
                            restaurant -> setFood(food);
                        }
                    }
                    else if (editChoice == 8){
                        if (typeChoice == 1){
                            cout << "Enter new sport type(group/individual): "; getline(cin, type);
                            sport -> setSportType(type);
                        }
                        else if (typeChoice == 2){
                            cout << "Enter a new brief info of the cultural attraction: "; getline(cin, information);
                            culture -> setInfo(information);
                        }
                        else if (typeChoice == 3){
                            int countMall = 0;
                            for (int m = 0; m < shopping -> getMallLength(); m++){
                                cout << m + 1 << ". " << shopping -> getMall(m) << endl;
                                countMall ++;
                            }
                            cout << "Please choose the malls' name that you want to edit(" << countMall + 1 << " to quit).\n";
                            int getMallPos = errorHandling(countMall + 1);
                            if (getMallPos == countMall + 1){
                                system("CLS");
                                return;
                            }
                            else{
                                cin.ignore(1000, '\n');
                                cout << "Enter new name for the chosen shopping mall: "; getline(cin, Attname);
                                shopping -> setMall(getMallPos - 1, Attname);
                            }
                        }
                        else if (typeChoice == 4){
                            cout << "Enter new price range of the restaurant in RM(e.g 20.00 - 50.00): "; getline(cin, price);
                           restaurant -> setPrice(price);
                        }
                    }
                    else if (editChoice == 9){
                        if (typeChoice == 1){
                            cout << "Enter new sport name: "; getline(cin, sportName);
                            sport -> setSportName(sportName);
                        }
                        else if (typeChoice == 2){
                            cout << "Enter a new facility of the cultural attraction: "; getline(cin, facility);
                            culture -> setFacility(facility);
                        }
                        else if (typeChoice == 3){
                            return;
                            break;
                        }
                        else if (typeChoice == 4){
                            return;
                            break;
                        }
                    }
                    else if (editChoice == 10){
                        if (typeChoice == 1){
                            return;
                            break;
                        }
                        else if (typeChoice == 2){
                            return;
                            break;
                        }
                    }
                    cout << "Continue to edit? (y for continue, any other key to exit)\n==>";
                    cin >> answer;
                    system("CLS");
                }while (answer == 'y' || answer == 'Y');
            }
        }
        saveAttraction();
        cout << "Update completed.\nTo return to ADMIN PANEL: "; system("Pause"); system("CLS");
        return;
    }
}

void City::runRemoveCity(){
    cout << "|::::::::::Remove Existed City:::::::::|\n";

    int temp = 0; int citySize = cityName.getLength();

    for (int i = 0; i < citySize; i++){
        cout << "[" << i + 1 << "] " << cityName.getEntry(i) -> name << endl;
        temp = i; //variable to store the size of vector cityName
    }
    cout << "Please select one of the city to remove.\nEnter [" << temp + 2 << "] back to Admin panel\n";
    int selection = temp + 2;
    int choice = errorHandling(selection);

    if (choice == temp + 2){
        system("CLS");
        return;
    }
    else{
        int toRemove = cityName.getEntry(choice - 1) -> id - 1;
        int **tempMatrix;
        tempMatrix = new int* [cityName.getLength() - 1];
        for (int z = 0; z  < cityName.getLength() - 1; z++){ // loop to adjust the matrix to remove the connection of deleted city
            tempMatrix[z] = new int [cityName.getLength() - 1];
            for(int w = 0; w < cityName.getLength() - 1; w++){
                if (z < toRemove && w < toRemove)
                    tempMatrix[z][w] = connect -> printGraph(z, w);
                else if ((z < toRemove && w == toRemove) || (z < toRemove && w > toRemove))
                    tempMatrix[z][w] = connect -> printGraph(z, w + 1);
                else if ((z == toRemove && w < toRemove) || (z > toRemove && w < toRemove))
                    tempMatrix[z][w] = connect -> printGraph(z + 1, w);
                else if ((z == toRemove && w == toRemove) || (z == toRemove && w > toRemove) ||
                         (z > toRemove && w == toRemove) || (z > toRemove && w > toRemove))
                    tempMatrix[z][w] = connect -> printGraph(z + 1, w + 1);
            }
        }
        delete connect;
        connect = new Graph(cityName.getLength() - 1, tempMatrix);
        for (int i = 0; i < cityName.getLength(); i++){
            if (cityName.getEntry(i) -> id > cityName.getEntry(choice - 1) -> id)
                cityName.getEntry(i) -> id --; // decrease the id of city by 1 if the id is bigger than the deleted city
        }
        for (int i = 0; i < cityName.getLength() - 1; i++)
            delete [] tempMatrix[i];
        delete [] tempMatrix;
        cityName.remove(choice - 1); // after finish copying the city connection, remove the city.
    }

    cityName.sort();

    saveAttraction();
    cout << "Remove completed.\nTo return to ADMIN PANEL: "; system("Pause"); system("CLS");
    return;
}

void City::runRemoveAttraction(){
    cout << "|:::::::Remove Existed Attraction::::::|\n";

    int temp = 0; int citySize = cityName.getLength();

    for (int i = 0; i < citySize; i++){
        cout << "[" << i + 1 << "] " << cityName.getEntry(i) -> name << endl;
        temp = i; //variable to store the size of cityName
    }

    cout << "Please select one of the city to remove.\nEnter [" << temp + 2 << "] back to Admin panel\n";

    int selection = temp + 2;
    int choice = errorHandling(selection); system("CLS");

    if (choice == temp + 2) return;
    else{
        cout << "You have chosen " << cityName.getEntry(choice - 1) -> name << ".\n";
        int attractionSize = cityName.getEntry(choice - 1) -> getAttractionSize();
        int tempSize = 0; int index = 0; LinkedList<int> position;
        for(int x = 0; x < attractionSize; x++){
            position.insert(index, x); // store the position of attraction in a linked list
            cout << "[" << x + 1 << "]" << cityName.getEntry(choice - 1) -> getAttraction(x) -> getName() << endl;
            tempSize = x; index ++;
        }
        cout << "Please select one of the attractions to remove.\nEnter [" << tempSize + 2 << "] back to Admin panel\n";
        tempSize = tempSize + 2;
        int selectDelete = errorHandling(tempSize);
        if (selectDelete == tempSize){
            system("CLS");
            return;
        }
        else{
            int toDelete = position.getEntry(selectDelete - 1);
            cityName.getEntry(choice - 1) -> attractions.remove(toDelete);
        }

        saveAttraction();
        cout << "Remove completed.\nTo return to ADMIN PANEL: "; system("Pause"); system("CLS");
        return;
    }
}

void City::runEditConnection(){
    cout << "|:::::::::Edit City Connection:::::::::|\n"
         << "[1]Add new city connection\n"
         << "[2]Remove an existed city connection\n"
         << "[3]Return to admin panel\n";

    int choice = errorHandling(3); system("CLS");

    char answer;
    do{
        if (choice == 1) cout << "You choose to add a new connection.\nGuide: enter departure city and destination to add connection.\n";
        else if (choice == 2) cout << "You choose to remove an existed connection.\nGuide: enter departure city and destination to remove connection.\n";
        else if (choice == 3) return;

        for (int i = 0; i < cityName.getLength(); i++)
            cout << "[" << i + 1 << "]" << cityName.getEntry(i) -> name << endl;

        cout << "Please enter the departure city\n"; int depart = errorHandling(cityName.getLength());

        LinkedList<int> city; int i;
        for (i = 0; i < depart - 1; i++){
            cout << "[" << i + 1 << "]" << cityName.getEntry(i) -> name << endl;
            city.insert(i, i); // store the position of city in linked list
        }
        for (int j = depart; j < cityName.getLength(); j++){
            cout << "[" << j << "]" << cityName.getEntry(j) -> name << endl;
            city.insert(i, j); // store the position of city in linked list
            i++;
        }

        cout << "Please enter destination\n"; int destination = errorHandling(cityName.getLength() - 1);

        if (choice == 1){ // add city connection
            connect -> addEdge(cityName.getEntry(depart - 1) -> id, cityName.getEntry(city.getEntry(destination - 1)) -> id);
            cout << "Connection added successfully!\n"
                 << "Does there a return flight from the destination? (y for yes / any key for no)\n==> ";

            char returnFlight; cin >> returnFlight;
            if (returnFlight == 'y' || returnFlight == 'Y'){
                connect -> GoBack(cityName.getEntry(depart - 1) -> id, cityName.getEntry(city.getEntry(destination - 1)) -> id);
                cout << "Fly back connection added successfully!\n";
            }
            cout << "Continue to add city connection?(y for yes / any key for no)\n==> ";
            cin >> answer; system("CLS");
        }
        else if (choice == 2){ // remove city connection
            connect -> removeEdge(cityName.getEntry(depart - 1) -> id, cityName.getEntry(city.getEntry(destination - 1)) -> id);
            cout << "Connection removed successfully!\n";
            cout << "Continue to remove city connection?(y for yes / any key for no)\n==> ";
            cin >> answer; system("CLS");
        }
        saveAttraction();
    }while(answer == 'y' || answer == 'Y');
}

void City::execute(){
    loadAttraction();
    MainMenu();
}

void City::MainMenu(){
    bool quit = false;
    while (!quit){
        cout << "|================================|" << endl
             << "|                                |" << endl
             << "|   Tourist Information System   |" << endl
             << "|                                |" << endl
             << "|================================|\n" << endl
             << "Please select one of the option to begin...\n" << endl
             << "1. Administrator" << endl
             << "2. User" << endl
             << "3. Quit\n" << endl;

        int choice = errorHandling(3);
        switch (choice){
            case 1:
                system("CLS");
                runAdmin();
                break;
            case 2:
                system("CLS");
                runCity();
                break;
            case 3:
                quit = true;
                break;
        }
    }
}

void City::runCity(){
    int temp = 0;
    cout << "|::::Welcome to Tourist Information System (User Page)::::|\n\n";

        int citySize = cityName.getLength();

        for (int i = 0; i < citySize; i++){
            cout << "[" << i + 1 << "] " << cityName.getEntry(i) -> name << endl;
            temp = i; //variable to store the size of vector cityName
        }

        temp = temp + 2;
        cout << "\nPlease select one of the cities to view its information." << endl
             << "\n[" << temp << "] ---> main menu.\n" << endl;

        int id = errorHandling(temp); system("CLS");

        if (id == temp) return;
        else runAttraction(id);
}

void City::runAttraction(int id){
    cout << "You have chosen " << cityName.getEntry(id - 1) -> name << ".\n\n"
         << "[1] Sport\n"
         << "[2] Culture\n"
         << "[3] Shopping\n"
         << "[4] Restaurant\n"
         << "[5] View all attraction\n"
         << "[6] View city connection\n\n";

    int temp = 8; // size of the attraction selection
    cout << "\nPlease choose one of the option above to view its information.\n" <<endl
         << "[" << temp - 1 << "] ---> city selection page." << endl
         << "[" << temp << "] ---> main menu.\n" << endl;

    int getAtt = errorHandling(temp); system("CLS");

    if (getAtt == 6) runCityConnection(id);
    else if (getAtt == temp - 1) runCity();
    else if (getAtt == temp) return;
    else runLocation(id, getAtt);
}

void City::runLocation(int id, int getAtt){
    int counts = 1;
    cout << "List of attraction selected in " << cityName.getEntry(id - 1) -> name << ":\n"  << endl;

    int attractionSize = cityName.getEntry(id - 1) -> getAttractionSize();
    LinkedList<int> position; int index = 0;
    for(int i = 0; i < attractionSize; i ++){
        if (cityName.getEntry(id - 1) -> getAttraction(i)->gettypeID() == getAtt){
            position.insert(index, i);
            cout << "[" << counts <<"] " << cityName.getEntry(id - 1) -> getAttraction(i) -> getName() << endl;
            counts ++; index ++;
        }
        else if (getAtt == 5){ // display all attractions
            cout << "_________________________________________________________" << endl;
            cityName.getEntry(id - 1) -> getAttraction(i) -> display();
        }
    }
    cout << endl << "Please input to proceed...\n" << endl
         << "[" << counts << "] ---> attraction type selection" << endl
         << "[" << counts + 1 << "] ---> city selection page." << endl
         << "[" << counts + 2 << "] ---> main menu.\n" << endl;

    int temp = counts + 2;
    int dispItem = errorHandling(temp); system("CLS");

    if (dispItem == temp - 2) runAttraction(id);
    else if (dispItem == temp - 1) runCity();
    else if (dispItem == temp) return;
    else{
        int getLocation = position.getEntry(dispItem - 1);
        runDisplay(id, getAtt, getLocation);
    }
}

/**Flight connection between cities ( <-> = two ways | -> = one way )
   Georgetown, Penang -> Melaka
   Georgetown, Penang <-> Kuala Lumpur -> Kota Kinabalu, Sabah
   Melaka <-> Kuala Lumpur <-> Georgetown, Penang
   Melaka <-> Kuala Lumpur -> Kota Kinabalu, Sabah
   Kota Kinabalu, Sabah -> Melaka <-> Kuala Lumpur <-> Georgetown, Penang
**/
void City::runCityConnection(int id){
    int answer;
    do{
        cout << "|::::Flight Connection Between Cities::::|\n"
             << "Depart from: " << cityName.getEntry(id - 1) -> name << endl
             << "Please select one of the city below as your destination.\n";

        LinkedList<int> city; int i;
        for (i = 0; i < id - 1; i++){
            cout << "[" << i + 1 << "]" << cityName.getEntry(i) -> name << endl;
            city.insert(i, i);
        }

        for (int j = id; j < cityName.getLength(); j++){
            cout << "[" << j << "]" << cityName.getEntry(j) -> name << endl;
            city.insert(i, j);
            i++;
        }

        int apart = errorHandling(cityName.getLength() - 1);
        // Depth first search to find the city connection
        int found = connect -> DFS(cityName.getEntry(id - 1) -> id , cityName.getEntry(city.getEntry(apart - 1)) -> id);

        if (found == -1)
            cout << "\nYou are in the same city. No flight available.\n";
        else if (found == 0)
            cout << "\nThe city you want to travel is not connected with " << cityName.getEntry(id - 1) -> name << ".\n";
        else if (found == cityName.getEntry(city.getEntry(apart - 1)) -> id)
            cout << "\nThere is a direct flight from " << cityName.getEntry(id - 1) -> name << " to "
                 << cityName.getEntry(city.getEntry(apart - 1)) -> name << endl;
        else if (found == -2)
            cout << "\nThere is an indirect flight between " << cityName.getEntry(id - 1) -> name << " and "
                 << cityName.getEntry(city.getEntry(apart - 1)) -> name << ".\n";

        cout << "\n\nDo you want to view another cities which are connected to " << cityName.getEntry(id - 1) -> name
             << "?\n[1]Continue to view city connection\n"
             << "[2]Return to view attractions of the city\n"
             << "[3]Return to city selection panel\n"
             << "[4]Return to main menu\n";

        answer = errorHandling(4); system("CLS");

        if (answer == 2) runAttraction(id);
        else if (answer == 3) runCity();
        else if (answer == 4) return;
    }while(answer == 1);
}

void City::runDisplay(int id, int getAtt, int getLocation){
    cityName.getEntry(id - 1) -> getAttraction(getLocation) -> display();

    cout << endl << "Please input to continue...\n" << endl
         << "[1] ---> main menu" << endl
         << "[2] ---> city selection" << endl
         << "[3] ---> attraction type selection" << endl
         << "[4] ---> view other attraction\n" << endl;

    int backs = errorHandling(4); system("CLS");

    if (backs == 1) return;
    else if (backs == 2) runCity();
    else if (backs == 3) runAttraction(id);
    else if (backs == 4) runLocation(id, getAtt);
}

ostream& City::output(ostream& out){ // helps to save the attribute of city
    out << name << "\n" << id << "\n";
    return out;
}

istream& City::input(istream& in){
    getline(in, name);

    string info;
    getline(in, info);
    int id = atoi(info.c_str()); // convert string into integer
    this -> id = id;

    return in;
}

ostream& operator << (ostream &out, City &info){ // helps to save the attribute of city
    return info.output(out);
}

ostream& operator << (ostream &out, Attraction &info){ // helps to save the attribute of attraction
    return info.output(out);
}

void City::saveAttraction(){
    ofstream file;
    file.open("TIS.txt");
    file << cityName.getLength() << "\n";

    int citySize = cityName.getLength();
    for(int i = 0; i < citySize; i ++){
        file << *cityName.getEntry(i);
        file << cityName.getEntry(i) -> attractions.getLength() << "\n";

        for (int j = 0; j < cityName.getEntry(i) -> getAttractionSize(); j ++){
            if(cityName.getEntry(i) -> attractions.getEntry(j) -> gettypeID() == 1)
                file << "sport" << "\n";
            else if (cityName.getEntry(i) -> attractions.getEntry(j) -> gettypeID() == 2)
                file << "culture" << "\n";
            else if (cityName.getEntry(i) -> attractions.getEntry(j) -> gettypeID() == 3)
                file << "shopping" << "\n";
            else if (cityName.getEntry(i) -> attractions.getEntry(j) -> gettypeID() == 4)
                file << "restaurant" << "\n";

            file << *cityName.getEntry(i) -> attractions.getEntry(j); // save all the information of the attractions
        }
    }
    file << connect -> getSize() << "\n"; // save the size of matrix
    for (int i = 0; i < connect -> getSize(); i++){
        for (int j = 0; j < connect -> getSize(); j++){
            file << connect -> printGraph(i, j) << " "; // save the data in the matrix
        }
        file << "\n";
    }

    file.close();
}

istream& operator >> (istream &in, City &info){ // helps to load city attribute
    return info.input(in);
}

City::City(ifstream& info){
    info >> *this; // load the data into the attribute
}

bool operator > (City& r1, City& r2){ // operator > overloaded for bubble sort
    return r1.getName() > r2.getName();
}

void City::loadAttraction(){
    int citySize, attractionSize;
    string extra;

    ifstream file("TIS.txt");

    if (file.fail()){
        cout << "Fail to load data.\n";
        return;
    }

        getline(file, extra); // obtain the size of city by get the whole line
        citySize = atoi(extra.c_str()); // convert it into integer

        for (int i = 0; i < citySize; i ++){
            cityName.insert(i, new City(file)); // pass the info of the cities into linked list

            file >> attractionSize; // get the size of attractions' linked list
            getline(file, extra); // get the extra line

            string attype;

            for (int j = 0; j < attractionSize; j ++){
                getline(file, attype); // load the attractions type
                if (attype == "sport")
                    cityName.getEntry(i) -> setAttraction(j, new Sport(file)); // insert the info of the attraction into linked list
                else if (attype == "culture")
                    cityName.getEntry(i) -> setAttraction(j, new Culture(file));
                else if (attype == "shopping")
                    cityName.getEntry(i) -> setAttraction(j, new Shopping(file));
                else if (attype == "restaurant")
                    cityName.getEntry(i) -> setAttraction(j, new Restaurant(file));
            }
        }

        getline(file, extra);
        int matrixSize = atoi(extra.c_str()); // convert the info of the line into integer

        int **tempMatrix; // temporary 2D matrix to store the city connection
        tempMatrix = new int* [cityName.getLength()];
        for (int n = 0; n < matrixSize; n++){
            tempMatrix[n] = new int [cityName.getLength()];
            for (int m = 0; m < matrixSize; m++){
                int connection;
                file >> connection; // load the data
                tempMatrix[n][m] = connection; // into 2D matrix
            }
        }

        getline(file, extra);
        file.close();

        cityName.sort(); // sort the linked list after cities are added

        connect = new Graph(cityName.getLength(), tempMatrix);

        for (int i = 0; i < cityName.getLength(); i++) // loop to delete 2D temporary matrix
            delete [] tempMatrix[i];
        delete [] tempMatrix;
}

City::~City(){
    delete connect; // delete pointer variable before closing
    cityName.clear();
    attractions.clear();
}

#endif // CITY_CPP
