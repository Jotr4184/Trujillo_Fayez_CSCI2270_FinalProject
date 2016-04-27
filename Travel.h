#ifndef TRAVEL_H_INCLUDED
#define TRAVEL_H_INCLUDED
#include <iostream>
#include <vector>

struct City{
    std::string cityName;
    std::string souvenirName;
    int souvenirPrice;
    std::string hotSpot;
    City *next;
    City *previous;

    City(){}; // default constructor

    City(std::string initName, City *initNext, City *initPrevious, std::string initSouvenirName, int initSouvenirPrice, std::string initHotSpot)
    {
        cityName = initName;
        next = initNext;
        previous = initPrevious;
        souvenirName = initSouvenirName;
        souvenirPrice = initSouvenirPrice;
        hotSpot = initHotSpot;
    }

};

class Travel
{
    public:
        Travel();
        ~Travel();
        void addCity(std::string, std::string, std::string, int, std::string);
        void planTrip();
        void printTrip();
        void printNetwork();
        void deleteCity(std::string);
        void cancelTrip();
        void setBudget(int);
        City *startTrip(City *start);
        int buySouvenir(City *currentCity, int);
        int returnBudget();
        void printSouvenirs();

    protected:
    private:
        City *head;
        City *tail;
        int budget=0;
        bool budgetCheck;
        std::vector<std::string> souvenirsPurhcased;
};


#endif // TRAVEL_H_INCLUDED
