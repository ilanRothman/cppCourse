//
// Created by iroth on 12/24/2021.
//

#ifndef METROMAP_METROPOLIS_H
#define METROMAP_METROPOLIS_H


#include "Junction.h"
#include "Road.h"
#include "Map.h"

class Metropolis {
private:
    double** graph;
    unsigned int size; // size of graph.
    Junction* junctions; //all junctions list.
    //counters
    int roadCount;
    int carCount;
    int junctionCount;

    Road* roads[500]; //holds the roads
    Car * cars[1000];
    //map that holds the vehicles their location
    Map<string,unsigned int>* locations;
    int iterations; //number of iteration for simulator.


public:
    /*big 3: only destructor needed because no copying or assignment of class was needed so relying on compiler.   */
    /*constructor and destructor*/
    Metropolis(double** graph, unsigned int size);
    ~Metropolis();


    void createRoads();//creates the roads

    void addJunction(Junction& newJunction, int index); //adding new junction to list.
    void addVehicle(Car& newCar); //adding vehicle to list.
    void move(Car &vehicle, int moveTo); //moving vehicle to different junction
    void printMatrix();//prints matrix of roads pollution
    void printVehicles(); // prints current vehicle location.


    /*getters and setters*/
    int getVehicleCount() const;
    int getIterations() const;
    void setIterations(int iter);
    unsigned int getSize() const;
    Junction& getJunction(int index);
    Car& getVehicle(unsigned int index);

};



#endif //METROMAP_METROPOLIS_H
