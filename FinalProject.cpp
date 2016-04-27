/*
Trip Planer (Final Project CSCI2270)
Josh Trujillo & Ahmed Fayez
Professor: Rhonda Hoenigman
TA: Amber Womack
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include "Travel.h"

using namespace std;

int main(int argc, char* argv[])
{
    Travel Tp;
    City *start = NULL;
    bool budgetCheck = false;           //checking if set budget or not
    bool planCheck = false;             //check for if you already planned the trip
    int userInput;
    string userName;

    cout << "Please type your name: " << endl;
    cin >> userName;

    cout <<"Welcome to " << userName << "'s Vacation Extravaganza! Let us begin!" << endl;
    cout << endl;

    while(userInput != 11 && userInput != 2)
    {
        cout << "======Main Menu======"<< endl;
        cout << "1.Plan Trip" << endl;
        cout << "2.Cancel Trip" << endl;
        cout << "3.Print Trip Path" << endl;
        cout << "4.Set Budget" << endl;
        cout << "5.Start Trip" << endl;
        cout << "6.Travel to Next City" << endl;
        cout << "7.Travel Back to Previous City" << endl;
        cout << "8.Add City" << endl;
        cout << "9.Delete City" << endl;
        cout << "10.Buy Souvenir" << endl;
        cout << "11.End Trip and Return Home" << endl;

        if(start != NULL)       //once you've started your trip it displays the current city's information
        {
            cout <<"======City Info======" << endl;
            cout << "Current city: " << start->cityName << endl;
            cout << "City souvenir: " << start->souvenirName << endl;
            cout << "Souvenir price: " << start->souvenirPrice << endl;
            cout << "City hot-spot: " << start->hotSpot << endl;
            cout << "Current budget: " << Tp.returnBudget() << endl;
        }
        cin >> userInput;
        cin.ignore();

        if(userInput == 1)      //Plan Trip/Build Linked List
        {
            if(planCheck == false)      //can only plan the trip once!
            {
                Tp.planTrip();
                Tp.printTrip();
                planCheck = true;
            }
            else
            {
                cout << "You have already planned your trip!" << endl;
            }
        }
        if(userInput == 3)      //print trip path
        {
            Tp.printTrip();
        }
        if(userInput == 4)      //set budget
        {
            if(budgetCheck == true)     //checking for if already set budget
            {
                cout << "You have already set your budget!" << endl;
            }
            else
            {
                int setBudget;
                cout << "Please set a budget for your trip! (Between $100 - $300)" << endl;
                cin >> setBudget;

                while(setBudget < 100 || setBudget > 300)       //has to be between 100 and 300 $$$
                {
                    cout << "Please set a budget as low as $100 and as high as $300." << endl;
                    cin >> setBudget;
                }

                Tp.setBudget(setBudget);
                budgetCheck = true;
            }
        }
        if(userInput == 5)      //start trip
        {
            if(budgetCheck != true)     //have to set budget before starting trip check
            {
                cout << "Please set the budget for your trip before starting by selecting the correct menu option (4)." << endl;
            }
            else
            {
                if(start == NULL)
                {
                    start = Tp.startTrip(start);
                }
                else
                {
                    cout << "You have already started your trip!" << endl;
                }
            }
        }
        if(userInput == 6)      //Travel to next city
        {
            if(start!= NULL)     //as long as the start pointer we made at the beginning isn't NULL, it can proceed
            {
                if(start->next==NULL)
                {
                    cout<<"It seems like you're at the last stop on your list."<<endl;
                }
                else
                {
                    start=start->next;
                }
            }
            else
            {
                cout << "You have to start your trip before going to the next city."<< endl;
            }
        }
        if(userInput == 7)      //Travel back to previous city
        {
            if(start!=NULL)
            {
                if(start->previous==NULL)
                {
                    cout<<"It seems like you're still at the first city of your list."<<endl;
                }
                else
                {
                    start=start->previous;
                }
            }
            else
            {
                cout<<"You have to start your trip before going to the previous city."<<endl;
            }
        }
        if(userInput == 8)      //Add a city to their trip
        {
            string cityNew;
            string cityPrevious;
            string souvenirNew;
            int souvenirNPrice;
            string hotSpotNew;

            cout << "Enter a city name: " << endl;
            getline(cin, cityNew);

            cout << "Enter a previous city name: " << endl;
            getline(cin, cityPrevious);

            cout << "Enter a souvenir for the new city (if you don't wish to add one please type NULL): " << endl;
            getline(cin, souvenirNew);
            if(souvenirNew != "NULL")          //doesn't ask for a price if they didn't want to set a souvenir
            {
                cout << "Enter a price for the souvenir please: " << endl;
                cin >> souvenirNPrice;
                cin.ignore();
            }
            cout << "Enter a hot spot location you would like to visit at this city (if you don't wish to add one please type NULL: " << endl;
            getline(cin, hotSpotNew);

            Tp.addCity(cityPrevious, cityNew, souvenirNew, souvenirNPrice, hotSpotNew);
        }
        if(userInput == 9)          //delete a city in trip
        {
            string cityDelete;

            cout << "Enter a city name: " << endl;
            cin >> cityDelete;

            Tp.deleteCity(cityDelete);
        }
        if(userInput == 10)      //buy souvenir
        {
            int budget = Tp.returnBudget();
            Tp.buySouvenir(start, budget);
        }
    }//End of while loop

    if(userInput == 2)      //cancel trip
    {
        Tp.cancelTrip();
        cout << "Your trip has been canceled!" << endl;
    }

    if(userInput == 11)     //end trip and return home
    {
        cout << "You have successfully ended your trip and returned home!" << endl;
        cout << "I hope you enjoyed " << userName << "'s vacation extravaganza!" << endl;
        cout << "You purchased: ";
        Tp.printSouvenirs();
        cout << endl;
        cout << "Your remaining budget is: $" << Tp.returnBudget() << endl;
    }
    return 0;
}
