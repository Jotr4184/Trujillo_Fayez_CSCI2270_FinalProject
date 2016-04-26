#ifndef TRAVEL_H
#define TRAVEL_H

struct City
{
    std::string cityName;
    std::string souvenirName;
    int souvenirPrice;
    std::string HotSpot;
    City *next;
    City *previous;

    City(){};

    City(std::string initcityName,std::string initsouvenirName,int initsouvenirprice,std::string initHotSpot, City *initnext, City *initprev)
    {
        cityname=initcityName;
        souvenirName=initsouvenirName;
        souvenirPrice=initsouvenirprice;
        HotSpot=initHotSpot;
        next=initnext;
        previous=initprev;
    }
};

class Travel
{
    public:
        Travel();
        ~Travel();
        void planTrip();
        void addCity(std::string city, std::string cityPrv);
        void deleteCity(std::string city);
        void cancelTrip();
        void printTrip();
        void addHotSpot(std::string place);
        void addSouvenir(std::string thing,int price);
        int setBudget(int money);
        void startTrip();
        void nextCity();
        void prevCity();
    protected:
    private:
        int budget;
};

#endif // TRAVEL_H
