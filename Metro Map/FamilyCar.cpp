

#include <cstdlib>
#include "FamilyCar.h"

/*random result for if to move car or not.*/
int FamilyCar::WhereTo(int roads) {
    int stay_or_go = rand()% (1+roads);
    return stay_or_go;
}
//return the pollution factor
int FamilyCar::getPollutionFactor() const {
    return pollutionFactor;
}

