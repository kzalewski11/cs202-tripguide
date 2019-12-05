//Node.h
//Node class interface

#include "Segment.h"

class Node
{
    public:
        Node();                 //default constructor
        ~Node();                //destructor
        Node(Segment * newSegment);      //constructor with arg

        Node * goNext();               //go next function
        void setNext(Node * toSet);     //set next function
        int display();             //node display


    protected:
        Segment * s1;           //base class object pointer
        Node * next;            //next node pointer

};
