//
// Created by iroth on 12/23/2021.
//

#ifndef METROMAP_LUXURYCAR_H
#define METROMAP_LUXURYCAR_H

#include "Car.h"

//no need of big three depending on base class and default constructors.
class LuxuryCar :  public virtual Car {
    private:
        int pollutionFactor;


public:

    LuxuryCar(int junctionNum, const string &name) : Car(junctionNum, name), pollutionFactor(3) {
    }
    int getPollutionFactor() const;
    /*random result for if to move car or not.*/
    int WhereTo(int roads);
};

#endif //METROMAP_LUXURYCAR_H
