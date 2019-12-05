//Segment.h
//Segment class interface

#include <iostream>
#include <cstring>

using namespace std;

class Segment   //base segment assumes no adverse conditions
{
    public:
        Segment();              //default constructor
        virtual ~Segment();             //destructor

        virtual int display();     //base class display
        void addMins(int add);    //adds delay based on segment condition

    protected:
        int travelMinutes;  //total travel time
};

class Weather: public Segment
{
    public:
        Weather();              //default constructor
        ~Weather();             //destructor
        
        int display();         //Weather display
        void calcDelay();      //change delay based on conditions

    private:
        bool ice;               //icy conditions
        bool rain;              //rainy conditions
        bool snow;              //snowy conditions
        int delay;         //total delay for this object
};

class Traffic: public Segment
{
    public:
        Traffic();              //default constructor
        Traffic(int n);         //constructor with arg
        ~Traffic();             //destructor

        int display();         //Traffic class display
        void calcDelay();      //change delay based on conditions

    private:
        int trafficLevel;    //current level of traffic
        int delay;          //total delay for object
};

class Accident: public Segment
{
    public:
        Accident();             //default constructor
        Accident(int sev);      //constructor with passed in int
        ~Accident();            //destructor

        int display();         //Accident class display
        void calcDelay();      //change delay based on conditions

    private:
        int severity;           //severity of accident
        int delay;         //total delay for object
};
