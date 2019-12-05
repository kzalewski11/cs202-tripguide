//List.h
//List class interface

#include "Node.h"

class List
{
    public:
        List();                     //default constructor
        List(char * listName);      //constructor with passed in name
        ~List();                    //destructor
        void add(Node * toAdd);     //add node wrapper
        void display();             //display all items in list (wrapper)
        void displayRev();          //display return trip wrapper

    private:
        int display(Node * head);  //display recursive function
        void add(Node * head, Node * toAdd);    //add passed in node to list
        int displayRev(Node * head);    //display return trip
        void deleteList(Node * head);        //recursive list deletion
        Node * head;                //pointer to head of list
        char * routeName;           //route name
        
};
