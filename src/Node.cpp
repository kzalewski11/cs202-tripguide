//Node.cpp
//Node class implementation

#include "Node.h"

//default constructor
Node::Node(): s1(nullptr), next(nullptr)
{}

//destructor
Node::~Node()
{
    delete s1;
    s1 = nullptr;

    delete next;
    next = nullptr;
}

//constructor with segment argument
Node::Node(Segment * newSegment)
{
    s1 = newSegment;
    next = nullptr;
}

//go next
Node * Node::goNext()
{
    return next;
}

//set next
void Node::setNext(Node * toSet)
{
    next = toSet;
}

//display node
int Node::display()
{
    return s1->display();
}
