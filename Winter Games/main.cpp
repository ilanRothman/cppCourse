#include <iostream>
#include "winterGames.h"
#include <cstdlib>

using namespace std;


int main(int argc,char *argv[]) {
    if(argc==3){
        char *arg1 = argv[1];
        char *arg2 = argv[2];
        if(isNumber(arg1) && isNumber(arg2)){ //legal arguments?
            winterGames games(atoi(arg1),atoi(arg2));
            games.start();
            }
        else{
            cerr << "ERROR: USAGE <executable> NUM_REFEREES MAX_ATHLETES" <<endl;

        }


        }
    return 0;
    }



