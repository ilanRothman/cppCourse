//
// Created by iroth on 12/23/2021.
//

#include "Junction.h"
#include "Road.h"

/*constructors*/

Junction::Junction():head(NULL),roadHead(NULL) {
    this->junctionID = 0;
    this->vehicleCount = 0;
    roadCount = 0;
}

Junction::Junction(int id, int size):head(NULL),roadHead(NULL){
    this->junctionID = id;
    this->vehicleCount = 0;
    roadCount = 0;
}


/*copy constructor and assignment operator overloading*/
Junction::Junction(const Junction &temp) {
    this->junctionID = temp.junctionID;
    this->head = temp.head;
    this->vehicleCount = temp.vehicleCount;
    this->roadCount = temp.roadCount;
    roadHead = temp.roadHead;
}

Junction &Junction::operator=(const Junction &other) {
    if(this == &other){
        return *this;
    }
    roadHead = other.roadHead;
    this->junctionID = other.junctionID;
    this->vehicleCount = other.getVehicleCount();
    this->head = other.head;
    this->roadCount = other.roadCount;
    return *this;
}


/*adding vehicle to linklist*/

void Junction::addVehicle(Car &vehicle) {
    if(!this->head) {
        head = &vehicle;
        vehicleCount++;
        return;
    }
    vehicle.setNext(head);
    head = &vehicle;
    vehicleCount++;

}

/*removing vehicle from the list*/
Car& Junction::removeVehicle(Car &vehicle) {
    Car* temp = this->head;
    Car* prev;
    if(temp != NULL && temp->getName() == vehicle.getName()){
        head = temp->getNext();
        vehicleCount--;
        return *temp;
    }
    while(temp &&temp->getName()!= vehicle.getName()){
        prev = temp;
        temp = temp->getNext();
    }
    if(!temp){
        return *temp;
    }
    prev->next = temp->getNext();
    vehicleCount--;
    return *temp;

}

/*adding a neighbor road to the road junction linked list*/
void Junction::addRoad(Road &newRoad) {
    if(!this->roadHead){
        roadHead = &newRoad;
        roadCount++;
        return;
    }
    newRoad.setNext(roadHead);
    this->roadHead = &newRoad;
    roadCount++;

}

/*getters*/

unsigned int Junction::getJunctionId() const {
    return junctionID;
}

int Junction::getVehicleCount() const {
    return vehicleCount;
}


int Junction::getRoadCount() const {
    return this->roadCount;
}

Road &Junction::getRoad(int index) {
    Road* temp = roadHead;
    for(int i = 0; i < index-2; i++){
        temp = temp->getNext();

    }
    return *temp;
}
