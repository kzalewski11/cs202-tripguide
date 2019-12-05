//Routes.h
//Routes class interface

#include "List.h"

class Routes
{
    public:
        Routes();                       //default constructor
        ~Routes();                      //destructor

        void display();     //display both routes in array
        void add(List * toAdd);      //add passed in list
        void returnTrip(int n);      //display return trip

    protected:
        //array of pointers to list heads for two routes
        List * array[2];
};
