//Segment.cpp
//Road class implementation

#include "Segment.h"

//Segment default constructor
Segment::Segment(): travelMinutes(40)
{}

//Segment destructor
Segment::~Segment()
{
}

//segment display
int Segment::display()
{
    cout << "Segment is free and clear. Travel Time is "
        << travelMinutes << " minutes.\n";
    
    return travelMinutes;
}

//add delay based on conditions
void Segment::addMins(int add)
{
    travelMinutes += add;
}

//Weather default constructor
Weather::Weather(): ice(true), rain(true), snow(false)
{}

//Weather destructor
Weather::~Weather()
{
}

//weather display
int Weather::display()
{
    //calculate minutes delay in section
    calcDelay();

    //display weather message
    cout << "Inclement weather causing " << delay << " minute delay in this segment.";

    //display chain requirements
    if(ice)
        cout << " Installed chains required.";
    
    if(snow && !ice)
        cout << " Must Carry Chains.";

    cout << endl;

    return 40 + delay;
}

//change delay based on conditions
void Weather::calcDelay()
{
    //delay is 120 minutes
    if(ice && rain && snow)
        delay = 120;

    //delay is 100 minutes
    else if(ice && !rain && snow)
        delay = 100;

    //delay is 80 minutes
    else if(ice && rain && !snow)
        delay = 80;

    //delay is 60 minutes
    else if((ice && !rain && !snow) || (!ice && rain && snow))
        delay = 60;

    //delay is 40 minutes
    else if(!ice && !rain && snow)
        delay = 40;

    //delay is 20 minutes
    else if(!ice && rain && !snow)
        delay = 20;

    //no delay
    else
        delay = 0;
}

//Traffic default constructor
Traffic::Traffic(): trafficLevel(0)
{}

//Traffic constructor with arg
Traffic::Traffic(int n): trafficLevel(n)
{}

//Traffic destructor
Traffic::~Traffic()
{
}

//traffic display
int Traffic::display()
{
    calcDelay();
    cout << "Traffic is causing a " << delay << " minute delay in this segment." << endl;

    return 40 + delay;
}

//change delay based on traffic
void Traffic::calcDelay()
{
    delay = trafficLevel * 10;
}

//Accident default constructor
Accident::Accident(): severity(0)
{}

//accident constructor with arg
Accident::Accident(int sev): severity(sev)
{}

//accident destructor
Accident::~Accident()
{
}

//accident display
int Accident::display()
{
    calcDelay();
    cout << "Accident causing "<< delay << " minute delay." << endl;

    return 40 + delay;
}

//change delay based on accidents
void Accident::calcDelay()
{
    delay =
        severity * 20;
}
