
#include <cstdlib>
#include "LuxuryCar.h"

/*random result for if to move car or not.*/
int LuxuryCar::WhereTo(int roads) {
    roads = 2*roads;
    int stay_or_go = rand()% (1+roads);
    if(stay_or_go  < (int)roads/2){ // 50% chance to stay.
        return 0;
    }
    return stay_or_go/2;


}

//getter.
int LuxuryCar::getPollutionFactor() const {
    return pollutionFactor;
}
