//Routes.cpp
//Routes class implementation

#include "Routes.h"

//default constructor
Routes::Routes()
{
    array[0] = nullptr;
    array[1] = nullptr;
}


//destructor
Routes::~Routes()
{
    if(array[0])
    {
        delete array[0];
        array[0] = nullptr;
    }

    if(array[1])
    {
        delete array[1];
        array[1] = nullptr;
    }
}

//display Routes array
void Routes::display()
{
    if(array[0])
        array[0]->display();

    cout << endl << endl;

    if(array[1])
        array[1]->display();

    cout << endl;
}

//add passed in list
void Routes::add(List * toAdd)
{
    if(array[0])
    {
        if(array[2])
        {
            cout << "Routes are full. No additional routes allowed\n";
            return;
        }
        array[1] = toAdd;
    }else
        array[0] = toAdd;
}

//display return trip
void Routes::returnTrip(int n)
{
    //display first route return trip
    if(n == 1)
        array[0]->displayRev();

    //display second route return trip
    if(n == 2)
        array[1]->displayRev();
}
