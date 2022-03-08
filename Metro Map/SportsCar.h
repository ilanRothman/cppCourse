

#ifndef METROMAP_SPORTSCAR_H
#define METROMAP_SPORTSCAR_H

#include "Car.h"


class SportsCar:  public virtual Car {
    //no need of big three depending on base class and default constructors.
    private:
            int pollutionFactor;
    public:

    SportsCar(int junctionNum, const string &name) : Car(junctionNum, name), pollutionFactor(4) {}
    /*random result for if to move car or not.*/
    virtual int WhereTo(int roads);

    int getPollutionFactor() const;
};

#endif //METROMAP_SPORTSCAR_H
