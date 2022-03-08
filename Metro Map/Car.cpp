#include "Car.h"
//car constructor.
Car::Car(int junctionNum, std::string name) {
    this->name = name;
    this->junctionNum = junctionNum;

}
/*copy constructor*/
Car::Car(const Car &temp) {
    this->junctionNum = temp.junctionNum;
    this->name = temp.name;
    this->next = temp.next;
}
/*assignment operator overloading*/
Car &Car::operator=(const Car &other) {
    if(this == &other){
        return *this;

    }
    this->name = other.name;
    this->junctionNum = other.junctionNum;
    this->next = other.next;
    return *this;
}

//return the car junction number.
unsigned int Car::getJunctionNum() const {
    return junctionNum;
}
//sets the current junction number
void Car::setJunctionNum(int junctionNum) {
    this->junctionNum = junctionNum;

}

Car *Car::getNext() const {
    return next;
}

void Car::setNext(Car *next) {
    this->next = next;

}

const string &Car::getName() const {
    return name;
}

Car::Car() {
    this->junctionNum = 0;
    this->name = "";
    this->next = NULL;
}

int Car::getPollutionFactor() const {
    return pollutionFactor;
}

int Car::WhereTo(int roads) {
    return 0;
}

Car::~Car() {

}





