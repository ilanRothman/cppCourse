//
// Created by iroth on 12/23/2021.
//

#ifndef METROMAP_FAMILYCAR_H
#define METROMAP_FAMILYCAR_H


#include "Car.h"

class FamilyCar: public Car {
    //no need of big three depending on base class and default constructors.

private:
    int pollutionFactor;
public:
    //constructor
    FamilyCar(int junctionNum, const std::string &name) : Car(junctionNum, name) {pollutionFactor = 2;}
    //getter
    int getPollutionFactor() const;

    /*random result for if to move car or not.*/
    int WhereTo(int roads);



};




#endif //METROMAP_FAMILYCAR_H
