#include "Maserati.h"

//getter.
int Maserati::getPollutionFactor() const {
    return pollutionFactor;
}
//same as sports car random pick for moving junction.
int Maserati::WhereTo(int roads) {
    return SportsCar::WhereTo(roads);
}
