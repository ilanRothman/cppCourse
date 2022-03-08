//
// Created by iroth on 12/23/2021.
//

#ifndef METROMAP_MASERATI_H
#define METROMAP_MASERATI_H

#include "SportsCar.h"
#include "LuxuryCar.h"


//no need of big three depending on base class and default constructors.
class Maserati: public virtual SportsCar, public virtual LuxuryCar{
    private:
        int pollutionFactor;

    public:
        Maserati(int junctionNum, const string &name) : Car(junctionNum,name),SportsCar(junctionNum, name),LuxuryCar(junctionNum,name), pollutionFactor(4)  {}
        //getter
        int getPollutionFactor() const;
        //random number for decision to move or not.
        virtual int WhereTo(int roads);

};



#endif //METROMAP_MASERATI_H
