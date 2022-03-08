
#include <cstdio>
#include "Road.h"

//constructor
Road::Road(Junction& from, Junction& to, double length) {
    this->from = &from;
    this->to = &to;
    this->length = length;
    pollution = 0;
    this->next = NULL;


}

//copy constructor
Road::Road(const Road &temp) {
    this->from = temp.from;
    this->to = temp.to;
    this->length = temp.length;
    this->next = temp.next;
    this->pollution = temp.pollution;

}

/*assignment operator overloading*/
Road &Road::operator=(const Road &other) {
    if(this == &other){
        return *this;
    }
    this->from = other.from;
    this->to = other.to;
    this->length = other.length;
    this->next = other.next;
    this->pollution = other.pollution;
    return *this;
}

/*getters and setters.*/
double Road::getPollution() const {
    return pollution;
}

const Junction &Road::getFrom() const {
    return *from;
}

Junction &Road::getTo()  {
    return *to;
}

Road *Road::getNext() const {
    return next;
}

void Road::setNext(Road *next) {
    Road::next = next;
}

void Road::addPollution(int pollutionFactor) {
    this->pollution = pollutionFactor/this->length;

}
