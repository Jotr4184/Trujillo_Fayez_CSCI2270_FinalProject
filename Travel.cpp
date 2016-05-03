#include "Travel.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Travel::Travel()
{
    head = NULL;
    tail = NULL;
}

Travel::~Travel()
{
    //dtor
    cancelTrip();
}

void Travel::planTrip()
{
    //note: all index's match up with all arrays, so the first index for each array is for the first city, the second is the second city and so on...
    //build our trip with planned out cities we want to "visit"
    string cityArray[10] = {"San Fransisco", "Boulder", "Denver", "Dallas", "Louisville", "Tallahassee", "Chicago", "Washington, D.C.", "New York", "Boston"};
    //array of our souvenirs available for each city
    string souvenirArray[10] = {"Bumper Sticker", "Fresh Herbs", "Concert T-Shirt", "Cowboy Star", "Cow Hide Postcard", "Phone Case", "Souvenir Mug", "Washington Monument Replica", "Teddy Bear", "Souvenir Baseball"};
    //price of souvenirs available for each city
    int souvenirPriceArray[10] = {15, 100, 25, 20, 15, 40, 10, 30, 40, 30};
    //array of hot spots available for each city
    string hotSpotArray[10] = {"Golden Gate Bridge", "Flatirons", "Summit Music Hall", "Cowboy's Stadium", "Cow fields", "Tallahassee Museum", "Willis Tower", "The White House", "Statue of Liberty", "Fenway Park"};
    int numCities = 10;

    City *cityAdded;
    City *currentCity;

    for(int i = 0; i < numCities; i++)
    {
        if(head == NULL)
        {
            cityAdded = new City(cityArray[i], NULL, NULL, souvenirArray[i], souvenirPriceArray[i], hotSpotArray[i]);
            currentCity = cityAdded;
            head = currentCity;
        }
        else
        {
            cityAdded = new City(cityArray[i], NULL, currentCity, souvenirArray[i], souvenirPriceArray[i], hotSpotArray[i]);
            currentCity->next = cityAdded;
            currentCity = cityAdded;

        }
    }
    tail = currentCity;
}

void Travel::printTrip()
{
    //traverse linked list printing out each city
    cout << "===CURRENT TRIP PATH===" << endl;

    if (head == NULL)
        cout << "NULL" << endl;
    //If not yet built, prints out each city and then "NULL"
    else
    {
        City *current = head;

        cout<<"NULL <- ";

        while (current->next != NULL)
        {
            cout << current->cityName << " <-> ";
            current = current->next;
        }
        cout << current->cityName << " -> ";
        cout << "NULL" << endl;
    }

    cout << "==================" << endl;

}

void Travel::setBudget(int setBudget)
{
    cout << "Your budget is set at $" << setBudget << endl;
    budget = setBudget;
    budgetCheck = true;
}

void Travel::addCity(string previousCity, string cityName, string souvenirName, int souvenirPrice, string hotSpot)
{
    if(previousCity == "First")         //if they want to add a city to the beginning
    {
        City *c = new City(cityName, head, NULL, souvenirName, souvenirPrice, hotSpot);
        head = c;
    }
    else
    {
        City * tmp = head;

        while(tmp->cityName != previousCity && tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        City * newCity = new City(cityName, tmp->next, tmp, souvenirName, souvenirPrice, hotSpot);

        tmp->next = newCity;
    }
    cout << "City added: " << cityName << endl;

    if(souvenirName != "NULL")                                        //check if added a souvenir
    {
        cout << "City Souvenir: " << souvenirName << endl;
        cout << "City Souvenir Price: $" << souvenirPrice << endl;
    }
    else
    {
        cout << "You did not add a souvenir." << endl;
    }

    if(hotSpot != "NULL")                                           //check if added a hot-spot
    {
        cout << "City Hot-Spot: " << hotSpot << endl;
    }
    else
    {
        cout << "You did not add a hot-spot to visit." << endl;
    }
    cout << "City added after: " << previousCity << endl;
}

void Travel::deleteCity(string cityNameIn)
{
    City *delCity = NULL;
    City *searchCity = head;

    bool found = false;                         //search for city first
    while(!found and searchCity != NULL)
    {
        if(searchCity->cityName == cityNameIn)
        {
            found = true;
        }
        else
        {
            searchCity = searchCity->next;
        }

    }
    if(found == true)
    {
        if(searchCity == head)                  //if it's the head
        {
            delCity = head;
            head = head->next;
            head->previous = NULL;
            delete delCity;
        }
        else if (searchCity == tail){           //Else if the city is the tail  (tail changes added by AKNucoder)
 +            delCity = tail;
 +            if (tail->previous != NULL){        //If the city before the last city is not null
 +                tail->previous->next = NULL;    //Make the previous city's next be NULL (since the last city is being deleted).
 +            }
 +            tail = tail->previous;              //Officially assign the previous city as the tail.
 +            delete delCity;
          }
        else
        {
            searchCity->previous->next = searchCity->next;
            searchCity->next->previous = searchCity->previous;
            delete searchCity;
        }

        cout << cityNameIn << " has been deleted from your trip." << endl;
    }
    else
    {
        cout<<cityNameIn<<" not found"<<endl;
    }
}

City *Travel::startTrip(City *start)
{
    start = head;
    cout << "You have started your trip, the first city is: " << start->cityName << endl;
    return head;
}

int Travel::buySouvenir(City *currentCity, int inputBudget)
{
    int souvenirPrice = currentCity->souvenirPrice;
    if(souvenirPrice > inputBudget)         //check if have enough $$
    {
        cout << "Unfortunately you do not have the required funds to purchase." << endl;
        budget = inputBudget;
        return budget;
    }
    else
    {
        inputBudget = inputBudget - souvenirPrice;      //subtract from budget

        souvenirsPurhcased.push_back (currentCity->souvenirName);       //push souvenir onto our purchased souvenirs list
        budget = inputBudget;

        cout << "You purchased: " << currentCity->souvenirName << "!" << endl;
        return budget;
    }
}

int Travel::returnBudget()      //returns the running budget set from menu option (4)
{
    return budget;
}

void Travel::printSouvenirs()       //loop through our souvenir purchased vector and print out contents
{
    for(int i=0; i<souvenirsPurhcased.size(); i++)
        {
            cout << souvenirsPurhcased[i];
            cout << ", ";
        }
}

void Travel::cancelTrip()       //delete entire trip + data
{
    City * tmp;

    while (head != NULL)        //loop through every node
    {
        tmp = head;

        head = head->next;

        cout<<"Canceling "<<tmp->cityName<<endl;     //delete stored node 1 at a time
        delete tmp;
    }
}
