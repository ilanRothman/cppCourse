
#include <cstdlib>
#include "SportsCar.h"

//random number  for decision to stay or move to next junction.
int SportsCar::WhereTo(int roads) {
    int stay_or_go = rand()% (1+roads);
    return stay_or_go;

}
//getter
int SportsCar::getPollutionFactor() const {
    return pollutionFactor;
}
