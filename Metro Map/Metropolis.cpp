#include <iostream>
#include <iomanip>
#include "Metropolis.h"
using namespace std;

/*constructor*/

Metropolis::Metropolis(double **graph, unsigned int size){
    this->graph = graph;
    this->size = size;
    roadCount = 0;
    carCount = 0;
    junctionCount = 0;
    junctions = new Junction[size];
    locations = new Map<string,unsigned int>;

}
/*destructor */
Metropolis::~Metropolis() {

    for(int i = 0; i < roadCount; i++){
        delete roads[i];
    }
    for(int i = 0 ; i < carCount; i++){
        delete cars[i];
    }
    delete [] junctions;

    for(unsigned int i = 0; i<size ; i++){
        delete graph[i];
    }
    delete[] graph;
    this->locations->clear();



}
/*adding new junction*/
void Metropolis::addJunction(Junction& newJunction, int index) {
    junctions[index] = newJunction;
    junctionCount++;


}
/*creating all the roads by looping over the graph. if weight is higher than 0
  it means it's a road.*/
void Metropolis::createRoads() {
    for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < size; j++) {
            if (graph[i][j] > 0) {
                Road *newRoad = new Road(junctions[i], junctions[j], graph[i][j]);
                roads[roadCount] = newRoad; // adding the road main road list.
                junctions[i].addRoad(*newRoad); //adding the road to the correct junction.
                roadCount++;}
        }
    }
}


/*adding new vehicle to main vehicle list*/
void Metropolis::addVehicle(Car &newCar) {
    cars[carCount] = &newCar;
    carCount++;
    this->locations->insert(newCar.getName(), newCar.getJunctionNum());
}

/*takes the vehicle from current juntion ands moves it to the wanted junction*/
void Metropolis::move(Car &car, int moveTo) {
    int junctionNum = car.getJunctionNum();
    junctions[junctionNum-1].removeVehicle(car); //removing from current junction
    junctions[junctionNum-1].getRoad(moveTo).getTo().addVehicle(car); //passing the car to the wanted junction.
    car.setJunctionNum(junctions[junctionNum-1].getRoad(moveTo).getTo().getJunctionId()); //setting the new junction ID.
    locations->updateValue(car.getName(),car.getJunctionNum());
    junctions[junctionNum-1].getRoad(moveTo).addPollution(car.getPollutionFactor()); //adding pollution to the used road.


}

/*printing the updated matrix*/
void Metropolis::printMatrix() {
    int currRoad = 0;
    for(unsigned int i = 0 ; i< getSize();i++){
        for (unsigned int j = 0 ; j < getSize();j++){
            if(currRoad < roadCount){
                if(roads[currRoad]->getFrom().getJunctionId() == i+1 &&roads[currRoad]->getTo().getJunctionId() == j+1){
                    cout << std::setprecision(3)<< roads[currRoad]->getPollution();
                    currRoad++;}
                else{
                    cout << "0";
                }
            }
            else{
                cout << "0";
            }
            if(j == getSize()-1){
                cout << endl;;
            }
            else{
                cout<< " ";
            }
        }
    }

}

/*printing the current vehicles location*/
void Metropolis::printVehicles() {
    for(unsigned int i = 0; i< getSize(); i++){
        cout << i+1 <<":";
        for ( int j = 0;j< getVehicleCount();j++){
            if(getVehicle(j).getJunctionNum() == i+1){
                cout << " "<<getVehicle(j).getName();
            }
        }
        cout << endl;

    }

}

/*getters and setters*/
int Metropolis::getVehicleCount() const {
    return carCount;
}

Car &Metropolis::getVehicle(unsigned int index) {
    return *cars[index];
}


unsigned int Metropolis::getSize() const {
    return size;
}

int Metropolis::getIterations() const {
    return iterations;
}

void Metropolis::setIterations(int iter) {
    this->iterations = iter;
}

Junction& Metropolis::getJunction(int index){
    return junctions[index];
}



