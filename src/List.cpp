//List.cpp
//List class implementation

#include "List.h"

//default constructor
List::List(): head(nullptr), routeName(nullptr)
{}

//constructor with passed in argument
List::List(char * listName): head(nullptr)
{
    routeName = new char[strlen(listName) + 1];
    strcpy(routeName, listName);
}

//destructor
List::~List()
{

    //if list has only one item
    if(!head->goNext())
    {
        delete head;
        head = nullptr;
    }

    //if list has more than one item
    else
        deleteList(head);

    delete routeName;
    routeName = nullptr;
}

//recursive list deletion
void List::deleteList(Node * head)
{
    //stopping condition
    if(!head->goNext())
    {
        head->setNext(nullptr);
        delete head;
        return;
    }

    deleteList(head->goNext());
}

//add node wrapper
void List::add(Node * toAdd)
{
    //if list is empty
    if(!head)
    {
        head = toAdd;
        return;
    }

    //call recursive function
    add(head, toAdd);
}

//add passed in node to list
void List::add(Node * head, Node * toAdd)
{

    //if stopping condition has been reached
    if(!head->goNext())
    {
        head->setNext(toAdd);
        return;
    }

    //recursive call
    add(head->goNext(), toAdd);
}

//display all items in list
void List::display()
{
    //check for null ptr
    if(!head)
        return;

    //display header
    cout << routeName << ":" << endl;

    //call recursive function
    int total = display(head);

    //display total time for route
    cout << "Total time for route is: " << total << " minutes.\n";
}

//display return trip
void List::displayRev()
{
    //check for null ptr
    if(!head)
        return;

    //display header
    cout << "Return trip via " << routeName << ":" << endl;

    //call recursive function
    int total = displayRev(head);

    //display total time for route
    cout << "Total return trip time is: " << total << " minutes.\n";
}

//display all items in list recursive
int List::display(Node * head)
{
    int total = 0;
    total += head->display();

    //continue condition
    if(head->goNext())
        return total + display(head->goNext());

    return total;
}

//display return trip recursive
int List::displayRev(Node * head)
{
    int total = 0;

    //reach stop condition
    if(head->goNext())
        total += displayRev(head->goNext());
        
    return total + head->display();



}
