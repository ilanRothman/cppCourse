
#ifndef METROMAP_JUNCTION_H
#define METROMAP_JUNCTION_H
#include "Car.h"
#include "Road.h"

class Junction{
private:
unsigned int junctionID;
int vehicleCount;
int roadCount;
Car *head;
Road* roadHead;

public:

    /*the big three are all implemented here except destructor because i am using pointers as part of
     the class data types, so I didn't want to rely on the defaults that the compiler makes */
    Junction();
    Junction(int id,int size);
    Junction(const Junction &temp);
    Junction& operator=(const Junction &other);


    /*adding vehicle to linklist*/
    void addVehicle(Car& vehicle);

    /*removing vehicle from the list*/
    Car & removeVehicle(Car& vehicle);

    /*adding a neighbor road to the road junction linked list*/
    void addRoad(Road& newRoad);


    /*getters*/
    unsigned int getJunctionId() const;

    int getVehicleCount() const;

    Road& getRoad(int index);

    int getRoadCount() const;

};
#endif //METROMAP_JUNCTION_H
