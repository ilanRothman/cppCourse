//
// Created by iroth on 11/25/2021.
//
#ifndef HEX_PLACE_H
#define HEX_PLACE_H
#include <string>
#include <iostream>
using namespace std;

// This class represents a place in the board game.
class Place{
    //Big three implementations:
    //Destructor - no dynamically allocations so no need to create a distructor.
    // Copy Constructer - had no need for one so relied on the default one.
    // Operator = - again, had no need for one.

    private:
        string state ;
        bool visited; // to help for recursion check win. no need to visit a visited place already.
    public:

        Place() {this->state = 'O'; this->visited =false;}

        const string&getState() const {return state;}

        void setState(char newState) {state = newState;} //state can be 'R' 'B' or O.

        bool isVisited() const {return visited;}

        void setVisited(bool changed) {Place::visited = changed;}







};



#endif //HEX_PLACE_H
