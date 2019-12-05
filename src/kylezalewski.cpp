//kylezalewski.cpp
//CS202
//Prog1

#include "Routes.h"

int main()
{
    //user interface headline
    cout << "=================================\n";
    cout << "Welcome to Mt. Hood Trip Planner!\n";
    cout << "=================================\n";

    //summary block
    cout << "You have two route options:\n";
    cout << "US Route 26\n";
    cout << "Interstate 84 and Oregon 35.\n\n";
    cout << "We aim to help you make the best choice for your travels.\n";
    cout << "=========================================================\n";

    //create new array for routes
    Routes * r = new Routes();

    //create segments
    //segments for 26 route
    Segment * a1 = new Segment();
    Segment * a2 = new Weather();
    Segment * a3 = new Traffic(3);
    Segment * a4 = new Accident(5);

    //segments for 84/35 route
    Segment * b1 = new Segment();
    Segment * b2 = new Segment();
    Segment * b3 = new Weather();
    Segment * b4 = new Segment();

    //create names for lists
    char * name1 = new char[20];
    strcpy(name1, "US Route 26");
    
    char * name2 = new char[20];
    strcpy(name2, "Interstate 84, Oregon 35");

    //create lists
    List * l1 = new List(name1);
    List * l2 = new List(name2);

    //create nodes
    Node * n1 = new Node(a1);
    Node * n2 = new Node(a2);
    Node * n3 = new Node(a3);
    Node * n4 = new Node(a4);

    Node * m1 = new Node(b1);
    Node * m2 = new Node(b2);
    Node * m3 = new Node(b3);
    Node * m4 = new Node(b4);

    //add nodes to lists
    l1->add(n1);
    l1->add(n2);
    l1->add(n3);
    l1->add(n4);

    l2->add(m1);
    l2->add(m2);
    l2->add(m3);
    l2->add(m4);

    //add lists to routes array
    r->add(l1);
    r->add(l2);

    //current route condition summary
    cout << "Here are the current conditions on each route:\n\n";
    r->display();

    //user menu to choose route
    int choice = 0;
    cout << "Which route would you like to take? Enter '1' for US Route 26 or '2' for Interstate 84/Oregon 35:\n";
    cin >> choice;
    cout << endl;
    r->returnTrip(choice);
    cout << endl;

    delete r;
    delete name1;
    delete name2;

	//return from main
	return 0;
}
